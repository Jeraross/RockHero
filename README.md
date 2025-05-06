# 💻 Projeto com Raylib + cURL + Gemini API

Este repositório contém um projeto C com suporte à [Raylib](https://www.raylib.com/) e integração com a [API Gemini](https://ai.google.dev/). Ele já vem com a estrutura pronta, incluindo dependências como `cURL` e `cJSON`, e um exemplo funcional de requisição à API.

---

## ⚙️ Requisitos

- **Windows**
- [Raylib](https://www.raylib.com/) baixada manualmente
- Acesso ao terminal `w64devkit` (incluso na pasta da Raylib)

---

## 🧭 Passo a Passo para Rodar

### 1. Baixe a Raylib

Acesse o site oficial da Raylib:

🔗 [https://www.raylib.com/](https://www.raylib.com/)

- Baixe a versão para **Windows**
- Extraia os arquivos e navegue até a pasta `/c/raylib/w64devkit`

---

### 2. Crie um atalho do terminal

- Dentro da pasta `w64devkit`, localize o arquivo `w64devkit.exe`
- Crie um **atalho** desse executável na sua **área de trabalho**
- Este terminal é onde você vai compilar e executar o projeto

---

### 3. Adicione sua chave da API Gemini

Abra o arquivo src/gemini.c e substitua o conteúdo da variável:

```gemini.c
#define API_KEY "SUA_CHAVE_AQUI"
```

---

### 4. Compile o jogo

Abra o terminal `w64devkit` e digite no diretório do seu jogo:

```bash
make run
```


