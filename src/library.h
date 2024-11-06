#ifndef LIBRARY_H
#define LIBRARY_H

void draw_dungeon(unsigned int width, unsigned int height, int dungeon[width][height]);

int get_wall_type(int x, int y, unsigned int width, unsigned int height, int dungeon[width][height]);

void draw_wall(unsigned int wall);

#endif
