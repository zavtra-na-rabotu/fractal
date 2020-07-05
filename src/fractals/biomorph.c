#include <pthread.h>
#include <math.h>
#include "fractol.h"

void	init_biomorph_area(t_package *pack)
{
	pack->fractal_area.min_r = -2.0f;
	pack->fractal_area.max_r = 2.0f;
	pack->fractal_area.min_i = -2.0f;
	pack->fractal_area.max_i = 2.0f;
	pack->fractal_area.zoom = 1.0f;
	pack->fractal_area.iterations = ITERATIONS;
	pack->fractal_area.offset_x = 0;
	pack->fractal_area.offset_y = 0;
	pack->fractal_area.mouse_pos.r = 0.5;
	pack->fractal_area.mouse_pos.i = 0;
	palette1(pack->palette);
}

void	biomorph_iteration(int x, int y, t_package *pack)
{
	t_c_num		z;
	t_c_num		c;
	t_c_num		tmp;
	int			i;

	z = point_to_complex(x, y, &pack->fractal_area);
	c = pack->fractal_area.mouse_pos;
	i = 0;
	while (z.r * z.r + z.i * z.i < BAILOUT && i < pack->fractal_area.iterations)
	{
		tmp.r = z.r * (z.r * z.r - 3 * z.i * z.i) + c.r;
		tmp.i = z.i * (3 * z.r * z.r - z.i * z.i) + c.i;
		if (z.r == tmp.r && z.i == tmp.i)
		{
			i = pack->fractal_area.iterations;
			break ;
		}
		z.r = tmp.r;
		z.i = tmp.i;
		i++;
	}
	colorize_pixel(i, z, (t_point){x, y}, pack);
}

void	*draw_biomorph_part(void *arg)
{
	t_thread_data	*data;
	int				x;
	int				y;

	data = (t_thread_data *)arg;
	y = 0;
	while (y < HEIGHT)
	{
		x = data->x_start;
		while (x < data->x_end)
		{
			biomorph_iteration(x, y, data->pack);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	draw_biomorph(t_package *pack)
{
	pthread_t		threads[MAX_THREADS];
	t_thread_data	data[MAX_THREADS];
	int				i;
	int				thread_x_part;

	thread_x_part = WIDTH / MAX_THREADS;
	i = 0;
	while (i < MAX_THREADS)
	{
		data[i].pack = pack;
		data[i].x_start = i * thread_x_part;
		if (i == MAX_THREADS - 1)
			data[i].x_end = WIDTH;
		else
			data[i].x_end = i * thread_x_part + thread_x_part;
		pthread_create(&threads[i], NULL, draw_biomorph_part, &data[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(pack->mlx_ptr, pack->win_ptr, pack->img_ptr, 0, 0);
}
