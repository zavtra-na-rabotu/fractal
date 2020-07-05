#include "fractol.h"

int			rgb(int r, int g, int b)
{
	return (r << RED_SHIFT | g << GREEN_SHIFT | b << BLUE_SHIFT);
}

t_c_num		point_to_complex(int x, int y, t_fractal_area *fa)
{
	t_c_num		num;
	double		range_r;
	double		range_i;

	range_r = fa->max_r - fa->min_r;
	num.r = (((double)x / WIDTH) * range_r) / fa->zoom + fa->min_r +
			fa->offset_x;
	range_i = fa->max_i - fa->min_i;
	num.i = (((double)y / HEIGHT) * range_i) / fa->zoom + fa->min_i +
			fa->offset_y;
	return (num);
}

int			delete_window(t_package *pack, int first_time)
{
	static int wins = -1;

	if (first_time > 0 && wins < 0)
		wins = pack->wins;
	if (pack->img_ptr != NULL)
	{
		mlx_destroy_image(pack->mlx_ptr, pack->img_ptr);
		mlx_destroy_window(pack->mlx_ptr, pack->win_ptr);
	}
	wins--;
	if (!wins)
		exit(0);
	return (0);
}
