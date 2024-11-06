#include <math.h>
#include <stdio.h>

#include "library.h"

int main(void) {
    const unsigned int width = 5;
    const unsigned int height = 5;

    int dungeon[width][height];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i == 1 && j == 1 || i == 1 && j == 3 || i == 3 && j == 1 || i == 3 && j == 3) {
                dungeon[i][j] = 0;
            } else {
                dungeon[i][j] = 1;
            }
        }
    }

    draw_dungeon(width, height, dungeon);

    return 0;
}
