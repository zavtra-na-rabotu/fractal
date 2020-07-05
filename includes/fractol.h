#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "colors.h"

# define WIDTH 1000
# define HEIGHT 1000

# define ITERATIONS 50
# define ITERATIONS_MAX 100000
# define ITERATIONS_STEP 5
# define NUM_OF_COLORS 16
# define BAILOUT 16

# define MANDELBROT_NAME "mandelbrot"
# define JULIA_NAME "julia"
# define BURNINGSHIP_NAME "burningship"
# define UNKNOWN_NAME "unknown"
# define SPIDER_NAME "spider"
# define THORN_NAME "thorn"
# define FROTHY_NAME "frothy"
# define BIOMORPH_NAME "biomorph"

# define MANDELBROT_ID 1000
# define JULIA_ID 1001
# define BURNINGSHIP_ID 1002
# define UNKNOWN_ID 1003
# define SPIDER_ID 1004
# define THORN_ID 1005
# define FROTHY_ID 1006
# define BIOMORPH_ID 1007

# define MAX_THREADS 24

# define ZOOM_COEFF 1.1

# define FRACTALS_COUNT 8

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_complex_num
{
	double			r;
	double			i;
}					t_c_num;

typedef struct		s_fractal_area
{
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			zoom;
	int				iterations;
	double			offset_x;
	double			offset_y;
	t_c_num			mouse_pos;
	int				fractal_id;
}					t_fractal_area;

typedef struct		s_package
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	void			*img_ptr;
	int				color_depth;
	t_fractal_area	fractal_area;
	int				wins;
	int				palette[NUM_OF_COLORS];
	int				locked;
}					t_package;

typedef struct		s_meta
{
	t_package		packs[FRACTALS_COUNT];
	int				ids[FRACTALS_COUNT];
	int				f_num;
	void			*mlx_ptr;
}					t_meta;

typedef struct		s_thread_data
{
	int				x_start;
	int				x_end;
	t_package		*pack;
}					t_thread_data;

void				set_image_pixel(t_package *pack, int x, int y, int color);
int					delete_window(t_package *pack, int first_time);
void				create_image(t_package *pack);

int					init_drawer(t_package *pack, char *name);
void				redraw(t_package *pack);

int					get_fractal_id(char *fractal_name);
char				*get_f_name(int id);

int					mouse_handler(int key, int x, int y, t_package *pack);
int					mouse_move(int x, int y, t_package *pack);

int					keyboard_handler(int key, t_package *pack);

void				zoom(int x, int y, t_fractal_area *fa, double z);

t_c_num				point_to_complex(int x, int y, t_fractal_area *fa);

void				verify_and_parse_args(int ac, char **av, t_meta *meta);
void				init_meta(t_meta *meta);

void				init_mandelbrot_area(t_package *pack);
void				init_julia_area(t_package *pack);
void				init_burningship_area(t_package *pack);
void				init_unknown_area(t_package *pack);
void				init_spider_area(t_package *pack);
void				init_thorn_area(t_package *pack);
void				init_frothy_area(t_package *pack);
void				init_biomorph_area(t_package *pack);

void				draw_mandelbrot(t_package *pack);
void				draw_julia(t_package *pack);
void				draw_burningship(t_package *pack);
void				draw_unknown(t_package *pack);
void				draw_spider(t_package *pack);
void				draw_thorn(t_package *pack);
void				draw_frothy(t_package *pack);
void				draw_biomorph(t_package *pack);

void				colorize_pixel(int i, t_c_num n, t_point pt, t_package *p);

#endif
