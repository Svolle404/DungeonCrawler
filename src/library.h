#ifndef LIBRARY_H
#define LIBRARY_H

void generate_dungeon(int width, int height, int dungeon[width][height]);

void add_border(int width, int height, int dungeon[width][height]);

void add_walls(int width, int height, int dungeon[width][height]);

void add_rooms(int width, int height, int dungeon[width][height]);

void add_pools(int width, int height, int dungeon[width][height]);

void add_chests(int width, int height, int dungeon[width][height]);

void spawn_entities(int width, int height, int entities[width][height], int dungeon[width][height]);

void clear_entities(int width, int height, int entities[width][height]);

void add_zombies(int width, int height, int entities[width][height], int dungeon[width][height]);

void draw_dungeon(unsigned int width, unsigned int height, int entities[width][height], int dungeon[width][height]);

int get_tile_type(int x, int y, unsigned int width, unsigned int height, int dungeon[width][height]);

void draw_tile(unsigned int tile);

void draw_entity(int x, int y, unsigned int width, unsigned int height, int entities[width][height]);

#endif
