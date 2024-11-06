#include "library.h"

#include <stdio.h>
#include <stdlib.h>

void draw_dungeon(const unsigned int width, const unsigned int height, int dungeon[width][height]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            draw_wall(get_wall_type(j, i, width, height, dungeon));
        }
        printf("\n");
    }
}

int get_wall_type(const int x, const int y, const unsigned int width, const unsigned int height, int dungeon[width][height]) {
    int type = 0;

    if (dungeon[x][y] == 0) {
        return type;
    }

    // Check wall north.
    if (y - 1 >= 0 && dungeon[x][y - 1] == 1) {
        type += 1;
    }

    // Check wall east.
    if (x + 1 < width && dungeon[x + 1][y] == 1) {
        type += 2;
    }

    // Check wall south.
    if (y + 1 < height && dungeon[x][y + 1] == 1) {
        type += 4;
    }

    // Check wall west.
    if (x - 1 >= 0 && dungeon[x - 1][y] == 1) {
        type += 8;
    }

    return type;
}

void draw_wall(const unsigned int wall) {
    switch (wall) {
        case 0:
            printf(" ");
            break;
        case 1:
            printf("%c", 178); // Invalid wall.
            break;
        case 2:
            printf("%c", 178); // Invalid wall.
            break;
        case 3:
            printf("%c", 200);
            break;
        case 4:
            printf("%c", 178); // Invalid wall.
            break;
        case 5:
            printf("%c", 186);
            break;
        case 6:
            printf("%c", 201);
            break;
        case 7:
            printf("%c", 204);
            break;
        case 8:
            printf("%c", 178); // Invalid wall.
            break;
        case 9:
            printf("%c", 188);
            break;
        case 10:
            printf("%c", 205);
            break;
        case 11:
            printf("%c", 202);
            break;
        case 12:
            printf("%c", 187);
            break;
        case 13:
            printf("%c", 185);
            break;
        case 14:
            printf("%c", 203);
            break;
        case 15:
            printf("%c", 206);
            break;
        default:
            printf("Unknown wall type!");
            exit(EXIT_FAILURE);
    }
}
