TARGET = app
SRC_DIR = src
RELEASE_DIR = bin
LIB_DIR = lib_raylib

SOURCES = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/entities/player.c \
	$(SRC_DIR)/entities/npc.c \
	$(SRC_DIR)/maps/mapa1.c \
	$(SRC_DIR)/maps/mapa2.c \
	$(SRC_DIR)/maps/mapa3.c \
	$(SRC_DIR)/gemini.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/cJSON.c \
	$(SRC_DIR)/dialogue.c

CFLAGS = -Wall -std=c99 -I$(LIB_DIR) -I$(SRC_DIR) -Icurl/include
LIBS = -L$(LIB_DIR) -Lcurl/lib -lraylib -lcurl -lopengl32 -lgdi32 -lwinmm

$(RELEASE_DIR)/$(TARGET).exe: $(SOURCES)
	@mkdir -p $(RELEASE_DIR)
	gcc $(CFLAGS) $^ -o $@ $(LIBS)
	@cp $(LIB_DIR)/raylib.dll $(RELEASE_DIR)/
	@cp curl/bin/libcurl.dll $(RELEASE_DIR)/  # <- Adicione isso se necessário
	@echo "Compilação concluída. DLLs copiadas para bin/"

run: $(RELEASE_DIR)/$(TARGET).exe
	@cd $(RELEASE_DIR) && start $(TARGET).exe

clean:
	rm -rf $(RELEASE_DIR)/app.exe

.PHONY: run clean
