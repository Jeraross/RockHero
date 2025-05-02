#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gemini.h"
#include <curl/curl.h>
#include "cJSON.h"

int main() {
    static char resposta[1024] = "";
    respt("Qual a capital do Brasil?", resposta);
    return 0;
}
