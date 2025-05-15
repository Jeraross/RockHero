#include "../../include/maps/mapa.h"
#include "../../include/maps/mapa1.h"
#include "../../include/maps/mapa2.h"
#include "../../include/maps/mapa3.h"
#include <stdlib.h>

MapNode* CreateMapList() {
    MapNode* map1 = (MapNode*)malloc(sizeof(MapNode));
    MapNode* map2 = (MapNode*)malloc(sizeof(MapNode));
    MapNode* map3 = (MapNode*)malloc(sizeof(MapNode));

    InitMap1(&map1->data);
    InitMap2(&map2->data);
    InitMap3(&map3->data);

    map1->mapId = 1;
    map2->mapId = 2;
    map3->mapId = 3;


    map1->prev = NULL;
    map1->next = map2;

    map2->prev = map1;
    map2->next = map3;

    map3->prev = map2;
    map3->next = NULL;

    return map1;
}

void FreeMapList(MapNode* list) {
    MapNode* current = list;

    while (current != NULL) {
        MapNode* next = current->next;

        UnloadTexture(current->data.npc.spriteSheet);
        if (current->data.background.id != 0) {
            UnloadTexture(current->data.background);
        }
        UnloadSound(current->data.typeSound);

        free(current);
        current = next;
    }
}