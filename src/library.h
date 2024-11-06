#ifndef LIBRARY_H
#define LIBRARY_H

void generate_dungeon(int width, int height, int dungeon[width][height]);

void add_border(int width, int height, int dungeon[width][height]);

void add_walls(int width, int height, int dungeon[width][height]);

void add_rooms(int width, int height, int dungeon[width][height]);

void add_pools(int width, int height, int dungeon[width][height]);

void draw_dungeon(unsigned int width, unsigned int height, int dungeon[width][height]);

int get_tile_type(int x, int y, unsigned int width, unsigned int height, int dungeon[width][height]);

void draw_tiles(unsigned int tile);

#endif
