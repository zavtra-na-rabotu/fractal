#include "fractol.h"

char	*get_f_name(int id)
{
	if (id == MANDELBROT_ID)
		return (MANDELBROT_NAME);
	else if (id == JULIA_ID)
		return (JULIA_NAME);
	else if (id == BURNINGSHIP_ID)
		return (BURNINGSHIP_NAME);
	else if (id == UNKNOWN_ID)
		return (UNKNOWN_NAME);
	else if (id == SPIDER_ID)
		return (SPIDER_NAME);
	else if (id == THORN_ID)
		return (THORN_NAME);
	else if (id == FROTHY_ID)
		return (FROTHY_NAME);
	else if (id == BIOMORPH_ID)
		return (BIOMORPH_NAME);
	return ("");
}

int		get_fractal_id(char *fractal_name)
{
	if (ft_strequ(fractal_name, MANDELBROT_NAME))
		return (MANDELBROT_ID);
	else if (ft_strequ(fractal_name, JULIA_NAME))
		return (JULIA_ID);
	else if (ft_strequ(fractal_name, BURNINGSHIP_NAME))
		return (BURNINGSHIP_ID);
	else if (ft_strequ(fractal_name, UNKNOWN_NAME))
		return (UNKNOWN_ID);
	else if (ft_strequ(fractal_name, SPIDER_NAME))
		return (SPIDER_ID);
	else if (ft_strequ(fractal_name, THORN_NAME))
		return (THORN_ID);
	else if (ft_strequ(fractal_name, FROTHY_NAME))
		return (FROTHY_ID);
	else if (ft_strequ(fractal_name, BIOMORPH_NAME))
		return (BIOMORPH_ID);
	return (0);
}
