#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"
#include "gemini.h"

#define API_KEY "SUA_CHAVE_AQUI"
#define MAX_RESPOSTA  1024

typedef struct {
    char *ptr;
    size_t len;
} StringBuf;

static void sbInit(StringBuf *s) {
    s->len = 0;
    s->ptr = malloc(1);
    s->ptr[0] = '\0';
}

static size_t sbWrite(void *data, size_t size, size_t nmemb, void *userp) {
    size_t add = size * nmemb;
    StringBuf *s = (StringBuf *)userp;
    char *tmp = realloc(s->ptr, s->len + add + 1);
    if (!tmp) return 0;
    s->ptr = tmp;
    memcpy(s->ptr + s->len, data, add);
    s->len += add;
    s->ptr[s->len] = '\0';
    return add;
}

void respt(const char *prompt, char *out) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        strncpy(out, "Erro ao iniciar libcurl.", MAX_RESPOSTA);
        return;
    }

    cJSON *root      = cJSON_CreateObject();
    cJSON *contents  = cJSON_AddArrayToObject(root, "contents");
    cJSON *mensagem  = cJSON_CreateObject();
    cJSON_AddItemToArray(contents, mensagem);

    cJSON_AddStringToObject(mensagem, "role", "user");
    cJSON *parts     = cJSON_AddArrayToObject(mensagem, "parts");
    cJSON *partObj   = cJSON_CreateObject();
    cJSON_AddItemToArray(parts, partObj);
    cJSON_AddStringToObject(partObj, "text", prompt);

    char *jsonReq = cJSON_PrintUnformatted(root);
    cJSON_Delete(root);

    const char *url =
        "https://generativelanguage.googleapis.com/"
        "v1beta/models/gemini-1.5-flash-latest:generateContent?key=" API_KEY;

    struct curl_slist *hdrs = NULL;
    hdrs = curl_slist_append(hdrs, "Content-Type: application/json; charset=utf-8");

    StringBuf resp;
    sbInit(&resp);

    curl_easy_setopt(curl, CURLOPT_URL,            url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER,     hdrs);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS,     jsonReq);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE,  (long)strlen(jsonReq));
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,  sbWrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,      &resp);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    CURLcode cret = curl_easy_perform(curl);
    long httpCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

    free(jsonReq);

    if (cret != CURLE_OK) {
        snprintf(out, MAX_RESPOSTA, "Erro de rede: %s", curl_easy_strerror(cret));
    }
    else if (httpCode != 200) {
        snprintf(out, MAX_RESPOSTA, "HTTP %ld devolvido pela API.", httpCode);
    }
    else {
        cJSON *rootResp = cJSON_Parse(resp.ptr);
        if (!rootResp) {
            strncpy(out, "Falha ao parsear JSON de resposta.", MAX_RESPOSTA);
        }
        else {
            cJSON *cands = cJSON_GetObjectItemCaseSensitive(rootResp, "candidates");
            if (cJSON_IsArray(cands) && cJSON_GetArraySize(cands) > 0) {
                cJSON *first      = cJSON_GetArrayItem(cands, 0);
                cJSON *contentObj = cJSON_GetObjectItemCaseSensitive(first, "content");
                cJSON *partsArr   = cJSON_GetObjectItemCaseSensitive(contentObj, "parts");
                cJSON *firstPart  = (partsArr && cJSON_GetArraySize(partsArr) > 0)
                                    ? cJSON_GetArrayItem(partsArr, 0)
                                    : NULL;
                cJSON *txt        = firstPart
                                    ? cJSON_GetObjectItemCaseSensitive(firstPart, "text")
                                    : NULL;

                if (cJSON_IsString(txt)) {
                    printf("Resposta Gemini: %s\n", txt->valuestring);

                    strncpy(out, txt->valuestring, MAX_RESPOSTA - 1);
                    out[MAX_RESPOSTA - 1] = '\0';
                } else {
                    strncpy(out, "Campo \"text\" ausente ou inválido.", MAX_RESPOSTA);
                }
            } else {
                cJSON *err  = cJSON_GetObjectItemCaseSensitive(rootResp, "error");
                cJSON *msg  = err ? cJSON_GetObjectItemCaseSensitive(err, "message") : NULL;
                snprintf(out, MAX_RESPOSTA, "Erro da API: %s",
                         (msg && cJSON_IsString(msg)) ? msg->valuestring : "desconhecido");
            }
            cJSON_Delete(rootResp);
        }
    }

    free(resp.ptr);
    curl_slist_free_all(hdrs);
    curl_easy_cleanup(curl);
}
