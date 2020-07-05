#include "fractol.h"

void	zoom(int x, int y, t_fractal_area *fa, double zoom)
{
	double width;
	double height;
	double new_width;
	double new_height;

	width = (fa->max_r - fa->min_r) / (fa->zoom);
	height = (fa->max_i - fa->min_i) / (fa->zoom);
	new_width = (fa->max_r - fa->min_r) / (fa->zoom * zoom);
	new_height = (fa->max_i - fa->min_i) / (fa->zoom * zoom);
	fa->zoom *= zoom;
	fa->offset_x -= ((double)x / WIDTH) * (new_width - width);
	fa->offset_y -= ((double)y / HEIGHT) * (new_height - height);
}
