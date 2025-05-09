TARGET = app
SRC_DIR = src
RELEASE_DIR = bin
LIB_DIR = lib_raylib

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/Player.c $(SRC_DIR)/maps/mapa1.c

CFLAGS = -Wall -std=c99 -I$(LIB_DIR) -I$(SRC_DIR)
LIBS = -L$(LIB_DIR) -lraylib -lopengl32 -lgdi32 -lwinmm

$(RELEASE_DIR)/$(TARGET).exe: $(SOURCES)
	@mkdir -p $(RELEASE_DIR)
	gcc $(CFLAGS) $^ -o $@ $(LIBS)
	@cp $(LIB_DIR)/raylib.dll $(RELEASE_DIR)/
	@echo "Compilação concluída. DLL copiada para bin/"

run: $(RELEASE_DIR)/$(TARGET).exe
	@cd $(RELEASE_DIR) && start $(TARGET).exe

clean:
	rm -rf $(RELEASE_DIR)

.PHONY: run clean