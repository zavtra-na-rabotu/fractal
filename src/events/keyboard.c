#include "fractol.h"
#include "events.h"

static void	fract_move(int key, t_package *pack)
{
	if (key == KEY_LEFT)
		pack->fractal_area.offset_x += 0.1 / pack->fractal_area.zoom;
	if (key == KEY_UP)
		pack->fractal_area.offset_y += 0.1 / pack->fractal_area.zoom;
	if (key == KEY_RIGHT)
		pack->fractal_area.offset_x -= 0.1 / pack->fractal_area.zoom;
	if (key == KEY_DOWN)
		pack->fractal_area.offset_y -= 0.1 / pack->fractal_area.zoom;
}

static void	fract_palette(int key, t_package *pack)
{
	if (key == KEY_1)
		change_palette(pack->palette, 1);
	if (key == KEY_2)
		change_palette(pack->palette, 2);
	if (key == KEY_3)
		change_palette(pack->palette, 3);
	if (key == KEY_4)
		change_palette(pack->palette, 4);
	if (key == KEY_5)
		change_palette(pack->palette, 5);
	if (key == KEY_6)
		change_palette(pack->palette, 6);
	if (key == KEY_7)
		change_palette(pack->palette, 7);
}

int			keyboard_handler(int key, t_package *pack)
{
	static int first_time = 1;

	if (key == KEY_LEFT || key == KEY_UP || key == KEY_RIGHT || key == KEY_DOWN)
		fract_move(key, pack);
	if (key == KEY_ESC)
	{
		delete_window(pack, first_time);
		first_time--;
		return (0);
	}
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 || key
	== KEY_5 || key == KEY_6 || key == KEY_7)
		fract_palette(key, pack);
	if (key == KEY_SPACE)
		pack->locked = !pack->locked;
	redraw(pack);
	return (0);
}
