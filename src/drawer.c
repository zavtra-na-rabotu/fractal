#include "fractol.h"
#include "events.h"

static void	init_fractal(t_package *pack)
{
	if (pack->fractal_area.fractal_id == MANDELBROT_ID)
		init_mandelbrot_area(pack);
	if (pack->fractal_area.fractal_id == JULIA_ID)
		init_julia_area(pack);
	if (pack->fractal_area.fractal_id == BURNINGSHIP_ID)
		init_burningship_area(pack);
	if (pack->fractal_area.fractal_id == UNKNOWN_ID)
		init_unknown_area(pack);
	if (pack->fractal_area.fractal_id == SPIDER_ID)
		init_spider_area(pack);
	if (pack->fractal_area.fractal_id == THORN_ID)
		init_thorn_area(pack);
	if (pack->fractal_area.fractal_id == FROTHY_ID)
		init_frothy_area(pack);
	if (pack->fractal_area.fractal_id == BIOMORPH_ID)
		init_biomorph_area(pack);
	redraw(pack);
}

void		redraw(t_package *pack)
{
	mlx_clear_window(pack->mlx_ptr, pack->win_ptr);
	if (pack->fractal_area.fractal_id == MANDELBROT_ID)
		return (draw_mandelbrot(pack));
	else if (pack->fractal_area.fractal_id == JULIA_ID)
		return (draw_julia(pack));
	else if (pack->fractal_area.fractal_id == BURNINGSHIP_ID)
		return (draw_burningship(pack));
	else if (pack->fractal_area.fractal_id == UNKNOWN_ID)
		return (draw_unknown(pack));
	else if (pack->fractal_area.fractal_id == SPIDER_ID)
		return (draw_spider(pack));
	else if (pack->fractal_area.fractal_id == THORN_ID)
		return (draw_thorn(pack));
	else if (pack->fractal_area.fractal_id == FROTHY_ID)
		return (draw_frothy(pack));
	else if (pack->fractal_area.fractal_id == BIOMORPH_ID)
		return (draw_biomorph(pack));
}

int			init_drawer(t_package *pack, char *name)
{
	pack->locked = 1;
	pack->win_ptr = mlx_new_window(pack->mlx_ptr, WIDTH, HEIGHT, name);
	create_image(pack);
	if (pack->img_ptr == NULL)
		return (1);
	init_fractal(pack);
	mlx_hook(pack->win_ptr, 17, 0L, delete_window, pack);
	mlx_hook(pack->win_ptr, MS_EVENT, MS_MASK, mouse_handler, pack);
	mlx_hook(pack->win_ptr, KB_EVENT, KB_MASK, keyboard_handler, pack);
	mlx_hook(pack->win_ptr, MS_MOVE_EVENT, MS_MOVE_MASK, mouse_move, pack);
	return (0);
}
