#include "fractol.h"
#include "events.h"

int	mouse_handler(int key, int x, int y, t_package *pack)
{
	if (key == MOUSE_IN)
	{
		zoom(x, y, &pack->fractal_area, ZOOM_COEFF);
		if (pack->fractal_area.iterations < ITERATIONS_MAX)
			pack->fractal_area.iterations += ITERATIONS_STEP;
		redraw(pack);
	}
	if (key == MOUSE_OUT)
	{
		zoom(x, y, &pack->fractal_area, 1 / ZOOM_COEFF);
		if (pack->fractal_area.iterations > ITERATIONS)
			pack->fractal_area.iterations -= ITERATIONS_STEP;
		redraw(pack);
	}
	return (0);
}

int	mouse_move(int x, int y, t_package *pack)
{
	if (!pack->locked)
	{
		pack->fractal_area.mouse_pos = point_to_complex(x, y,
				&pack->fractal_area);
		redraw(pack);
	}
	return (0);
}
