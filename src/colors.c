#include <math.h>
#include "fractol.h"
#include "colors.h"

void	change_palette(int palette[], int num)
{
	if (num == 1)
		palette1(palette);
	else if (num == 2)
		palette2(palette);
	else if (num == 3)
		palette3(palette);
	else if (num == 4)
		palette4(palette);
	else if (num == 5)
		palette5(palette);
	else if (num == 6)
		palette6(palette);
	else if (num == 7)
		palette7(palette);
}

int		gradient_color(int from, int to, float part)
{
	int rgbs[3];
	int rgbe[3];
	int rgbd[3];
	int retval;

	get_colors(from, rgbs + 0, rgbs + 1, rgbs + 2);
	get_colors(to, rgbe + 0, rgbe + 1, rgbe + 2);
	rgbd[0] = (rgbe[0] - rgbs[0]) * part;
	rgbd[1] = (rgbe[1] - rgbs[1]) * part;
	rgbd[2] = (rgbe[2] - rgbs[2]) * part;
	retval = rgb((rgbd[0] + rgbs[0]), (rgbd[1] + rgbs[1]), (rgbd[2] + rgbs[2]));
	return (retval);
}

void	get_colors(int base, int *r, int *g, int *b)
{
	int red;
	int green;
	int blue;

	red = base & RED_COLOR;
	green = base & GREEN_COLOR;
	blue = base & BLUE_COLOR;
	*r = red >> RED_SHIFT;
	*g = green >> GREEN_SHIFT;
	*b = blue >> BLUE_SHIFT;
}

void	colorize_pixel(int i, t_c_num n, t_point pt, t_package *p)
{
	float	log_zn;
	float	new_i;
	int		color1;
	int		color2;
	int		color;

	log_zn = log(n.r * n.r + n.i * n.i) / 2;
	new_i = i + 1 - log(log_zn / log(2)) / log(2);
	color1 = p->palette[(int)floor(new_i) % NUM_OF_COLORS];
	color2 = p->palette[(int)floor(new_i + 1) % NUM_OF_COLORS];
	color = gradient_color(color1, color2, (new_i - (int)new_i));
	if (i < p->fractal_area.iterations)
		set_image_pixel(p, pt.x, pt.y, color);
	else
		set_image_pixel(p, pt.x, pt.y, BASE_COLOR);
}
