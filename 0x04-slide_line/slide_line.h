#ifndef INC_0X04_SLIDE_LINE_SLIDE_LINE_H
#define INC_0X04_SLIDE_LINE_SLIDE_LINE_H

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

int squish_line_left(int **line, size_t size);
int squish_line_right(int **line, size_t size);
int slide_line_left(int *line, size_t size, size_t number_length);
int slide_line_right(int *line, size_t size, size_t number_length);
int slide_line(int *line, size_t size, int direction);

#endif
