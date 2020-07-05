#include "fractol.h"

void	set_image_pixel(t_package *pack, int x, int y, int color)
{
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
		*((int *)(pack->img + (x + y * WIDTH) * pack->color_depth)) = color;
}

void	create_image(t_package *pack)
{
	int depth;
	int sz_line;
	int endian;

	depth = 0;
	sz_line = 0;
	endian = 0;
	if ((pack->img_ptr = mlx_new_image(pack->mlx_ptr, WIDTH, HEIGHT)) == NULL)
		mlx_destroy_image(pack->mlx_ptr, pack->img_ptr);
	pack->img = mlx_get_data_addr(pack->img_ptr, &depth, &sz_line, &endian);
	pack->color_depth = depth / 8;
}
