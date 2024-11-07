#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MINIMUM_NUMBER_OF_ROOMS 3
#define MAXIMUM_NUMBER_OF_ROOMS 6
#define MINIMUM_ROOM_WIDTH 3
#define MINIMUM_ROOM_HEIGHT 3

#define MINIMUM_NUMBER_OF_POOLS 3
#define MAXIMUM_NUMBER_OF_POOLS 8
#define MAXIMUM_POOL_SIZE 3

void generate_dungeon(const int width, const int height, int dungeon[width][height]) {
    // Create a border.
    add_border(width, height, dungeon);

    // Add random walls.
    add_walls(width, height, dungeon);

    // Add random rooms.
    add_rooms(width, height, dungeon);

    // Add random pools of water.
    add_pools(width, height, dungeon);

    // Add chests.
    add_chests(width, height, dungeon);
}

void add_border(const int width, const int height, int dungeon[width][height]) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i == 0 || j == 0 || i == width - 1 || j == height - 1) {
                dungeon[i][j] = 1;
            } else {
                dungeon[i][j] = 0;
            }
        }
    }
}

void add_walls(const int width, const int height, int dungeon[width][height]) {
    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            if (rand() % 2 == 0) {
                dungeon[i][j] = 0;
            } else {
                dungeon[i][j] = 1;
            }
        }
    }
}

void add_rooms(const int width, const int height, int dungeon[width][height]) {
    const int number_of_rooms = rand() % (MAXIMUM_NUMBER_OF_ROOMS - MINIMUM_NUMBER_OF_ROOMS + 1) + MINIMUM_NUMBER_OF_ROOMS;
    for (int i = 0; i < number_of_rooms; i++) {
        const int room_width = rand() % 6 + MINIMUM_ROOM_WIDTH + 1;
        const int room_height = rand() % 6 + MINIMUM_ROOM_HEIGHT + 1;
        const int room_x = rand() % (width - room_width);
        const int room_y = rand() % (height - room_height);
        for (int x = room_x; x <= room_x + room_width; x++) {
            for (int y = room_y; y <= room_y + room_height; y++) {
                if (x == room_x || y == room_y || x == room_x + room_width || y == room_y + room_height) {
                    dungeon[x][y] = 1;
                } else {
                    dungeon[x][y] = 0;
                }
            }
        }
    }
}

void add_pools(const int width, const int height, int dungeon[width][height]) {
    const int number_of_pools = rand() % (MAXIMUM_NUMBER_OF_POOLS - MINIMUM_NUMBER_OF_POOLS + 1) + MINIMUM_NUMBER_OF_POOLS;
    for (int i = 0; i < number_of_pools; i++) {
        const int pool_snake_length = rand() % 21 + 3;
        const int pool_snake_diameter = rand() % MAXIMUM_POOL_SIZE + 1;
        int pool_y = rand() % (height - pool_snake_diameter - 1) + 1;
        int pool_x = rand() % (width - pool_snake_diameter - 1) + 1;

        for (int l = 0; l < pool_snake_length; l++) {
            const int direction = rand() % 8;
            switch (direction) {
                case 0:
                    pool_y--;
                    break;
                case 1:
                    pool_y--;
                    pool_x++;
                    break;
                case 2:
                    pool_x++;
                    break;
                case 3:
                    pool_x++;
                    pool_y++;
                    break;
                case 4:
                    pool_y++;
                    break;
                case 5:
                    pool_y++;
                    pool_x--;
                    break;
                case 6:
                    pool_x--;
                    break;
                case 7:
                    pool_x--;
                    pool_y--;
                    break;
                default:
                    printf("Unknown pool direction!");
                    exit(EXIT_FAILURE);
                    break;
            }
        }

        for (int x = pool_x; x < pool_x + pool_snake_diameter; x++) {
            for (int y = pool_y; y < pool_y + pool_snake_diameter; y++) {
                dungeon[x][y] = 2;
            }
        }
    }
}

void add_chests(const int width, const int height, int dungeon[width][height]) {
    const int number_of_chests = rand() % 6 + 3;
    for (int i = 0; i < number_of_chests; i++) {
        const int chest_x = rand() % (width - 2) + 1;
        const int chest_y = rand() % (height - 2) + 1;
        dungeon[chest_x][chest_y] = 3;
    }
}

void spawn_entities(const int width, const int height, int entities[width][height], int dungeon[width][height]) {
    // Make all tiles empty.
    clear_entities(width, height, entities);

    // Add zombies.
    add_zombies(width, height, entities, dungeon);
}

void clear_entities(const int width, const int height, int entities[width][height]) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            entities[i][j] = 0;
        }
    }
}

void add_zombies(const int width, const int height, int entities[width][height], int dungeon[width][height]) {
    const int number_of_zombies = rand() % 11 + 10;
    for (int i = 0; i < number_of_zombies; i++) {
        int zombie_x = 0;
        int zombie_y = 0;

        while (dungeon[zombie_x][zombie_y] != 0 || entities[zombie_x][zombie_y] != 0) {
            zombie_x = rand() % (width - 2) + 1;
            zombie_y = rand() % (height - 2) + 1;
        }

        entities[zombie_x][zombie_y] = 2;
    }
}

void set_console_color(const int c) {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, c);
}

void draw_dungeon(const unsigned int width, const unsigned int height, int entities[width][height], int dungeon[width][height]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (entities[j][i] == 0) {
                draw_tile(get_tile_type(j, i, width, height, dungeon));
            } else {
                draw_entity(j, i, width, height, entities);
            }
        }
        printf("\n");
    }
}

void draw_tile(const unsigned int tile) {
    switch (tile) {
        case -1: // Empty tile.
            printf("%c", 250);
            break;
        case 0:
            printf("%c", 215);
            break;
        case 1:
            printf("%c", 208);
            break;
        case 2:
            printf("%c", 198);
            break;
        case 3:
            printf("%c", 200);
            break;
        case 4:
            printf("%c", 210);
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
            printf("%c", 181);
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
        case 16: // Water.
            printf("%c", 247);
            break;
        case 17: // Chest.
            printf("%c", 216);
            break;
        default:
            printf("Unknown wall type!");
            exit(EXIT_FAILURE);
    }
}

int get_tile_type(const int x, const int y, const unsigned int width, const unsigned int height, int dungeon[width][height]) {
    int type = 0;

    // If the tile is empty.
    if (dungeon[x][y] == 0) {
        set_console_color(0x87);
        return -1;
    }

    // If the tile is a normal wall.
    if (dungeon[x][y] == 1) {
        set_console_color(0x8f);
        // Check north tile.
        if (y - 1 >= 0 && dungeon[x][y - 1] == 1) {
            type += 1;
        }
        // Check east.
        if (x + 1 < width && dungeon[x + 1][y] == 1) {
            type += 2;
        }
        // Check south.
        if (y + 1 < height && dungeon[x][y + 1] == 1) {
            type += 4;
        }
        // Check west.
        if (x - 1 >= 0 && dungeon[x - 1][y] == 1) {
            type += 8;
        }
    }

    // If the tile is water.
    if (dungeon[x][y] == 2) {
        set_console_color(0x19);
        return 16;
    }

    // If the tile is a chest.
    if (dungeon[x][y] == 3) {
        set_console_color(0xce);
        return 17;
    }

    return type;
}

void draw_entity(const int x, const int y, const unsigned int width, const unsigned int height, int entities[width][height]) {
    switch (entities[x][y]) {
        case 1: // Player.
            set_console_color(0x6d);
            printf("%c", 232);
            break;
        case 2: // Zombie.
            set_console_color(0x8a);
            printf("%c", 234);
            break;
        default:
            printf("Unknown entity type!");
            exit(EXIT_FAILURE);
    }
}
