#ifndef _SLIDE_LINE_H
#define _SLIDE_LINE_H

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

void slide_line_left(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);
void invert(int *line, size_t size);

#endif
