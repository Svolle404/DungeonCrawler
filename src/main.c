#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "library.h"

#define DUNGEON_WIDTH 48
#define DUNGEON_HEIGHT 16
int dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT];

int main(void) {
    srand(time(0));

    generate_dungeon(DUNGEON_WIDTH, DUNGEON_HEIGHT, dungeon);

    draw_dungeon(DUNGEON_WIDTH, DUNGEON_HEIGHT, dungeon);

    while (1);
}
