#include "fractol.h"

void	verify_and_parse_args(int ac, char **av, t_meta *meta)
{
	int i;
	int tmp;
	int k;

	i = 0;
	k = 0;
	while (i < ac)
	{
		tmp = get_fractal_id(av[i]);
		if (tmp)
		{
			meta->f_num++;
			if (meta->f_num > FRACTALS_COUNT)
			{
				meta->f_num = -1;
				return ;
			}
			meta->ids[k] = tmp;
			k++;
		}
		i++;
	}
	if (!meta->f_num)
		return ;
}

void	init_meta(t_meta *meta)
{
	int i;

	i = 0;
	meta->mlx_ptr = mlx_init();
	while (i < meta->f_num)
	{
		meta->packs[i].fractal_area.fractal_id = meta->ids[i];
		meta->packs[i].mlx_ptr = meta->mlx_ptr;
		meta->packs[i].wins = meta->f_num;
		init_drawer(&meta->packs[i], get_f_name(meta->ids[i]));
		i++;
	}
	mlx_loop(meta->mlx_ptr);
}
