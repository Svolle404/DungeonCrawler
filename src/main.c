#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "library.h"

#define DUNGEON_WIDTH 48
#define DUNGEON_HEIGHT 16
int dungeon[DUNGEON_WIDTH][DUNGEON_HEIGHT];
int entities[DUNGEON_WIDTH][DUNGEON_HEIGHT];

int main(void) {
    srand(time(0));

    generate_dungeon(DUNGEON_WIDTH, DUNGEON_HEIGHT, entities, dungeon);
    spawn_entities(DUNGEON_WIDTH, DUNGEON_HEIGHT, entities, dungeon);

    while (1) {
        printf("\033[H");
        draw_dungeon(DUNGEON_WIDTH, DUNGEON_HEIGHT, entities, dungeon);
        console_settings();
        get_user_input(DUNGEON_WIDTH, DUNGEON_HEIGHT, entities, dungeon);
        update_game(DUNGEON_WIDTH, DUNGEON_HEIGHT, entities, dungeon);
    }
}
