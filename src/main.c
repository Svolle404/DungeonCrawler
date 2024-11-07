#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "library.h"

#define DUNGEON_WIDTH 72
#define DUNGEON_HEIGHT 18
int dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT];
int entities[DUNGEON_WIDTH][DUNGEON_HEIGHT];

int main(void) {
    srand(time(0));

    generate_dungeon(DUNGEON_WIDTH, DUNGEON_HEIGHT, dungeon);
    spawn_entities(DUNGEON_WIDTH, DUNGEON_HEIGHT, entities, dungeon);

    draw_dungeon(DUNGEON_WIDTH, DUNGEON_HEIGHT, entities, dungeon);

    while (1);
}
