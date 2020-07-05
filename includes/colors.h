#ifndef FDF_COLORS_H

# define FDF_COLORS_H

# define MAX_INTENSITY 255

# define RED_SHIFT 16
# define GREEN_SHIFT 8
# define BLUE_SHIFT 0

# define RED_COLOR MAX_INTENSITY << RED_SHIFT
# define GREEN_COLOR MAX_INTENSITY << GREEN_SHIFT
# define BLUE_COLOR MAX_INTENSITY << BLUE_SHIFT

# define BASE_COLOR 0x000000

void			change_palette(int palette[], int palette_num);
void			make_palette(int palette[], int base_points[]);
void			palette1(int palette[]);
void			palette2(int palette[]);
void			palette3(int palette[]);
void			palette4(int palette[]);
void			palette5(int palette[]);
void			palette6(int palette[]);
void			palette7(int palette[]);
void			get_colors(int base, int *r, int *g, int *b);
int				gradient_color(int from, int to, float part);
int				rgb(int r, int g, int b);

#endif
