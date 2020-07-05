#include "fractol.h"

int	error(char *e)
{
	ft_putendl(e);
	ft_putendl("Usage: fractol [mandelbrot, julia, \
burningship, unknown, spider, thorn, frothy, biomorph]");
	ft_putendl("Max valid args: 8");
	return (1);
}

int	main(int argc, char **argv)
{
	t_meta		meta;

	if (argc < 2)
		return (error("Error: not enough arguments"));
	meta.f_num = 0;
	verify_and_parse_args(argc, argv, &meta);
	if (!meta.f_num)
		return (error("Error: invalid argument"));
	if (meta.f_num == -1)
		return (error("Error: too many arguments"));
	init_meta(&meta);
	return (0);
}
