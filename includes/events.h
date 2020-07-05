#ifndef FRACTOL_EVENTS_H
# define FRACTOL_EVENTS_H

# ifdef __linux__
#  define MS_EVENT 4
#  define MS_MASK 4
#  define MS_MOVE_EVENT 6
#  define MS_MOVE_MASK 64
#  define KB_EVENT 2
#  define KB_MASK 1
#  define KEY_ESC 65307
#  define KEY_LEFT 65361
#  define KEY_UP 65362
#  define KEY_RIGHT 65363
#  define KEY_DOWN 65364
#  define KEY_SPACE 32
#  define MOUSE_IN 4
#  define MOUSE_OUT 5
#  define KEY_1 49
#  define KEY_2 50
#  define KEY_3 51
#  define KEY_4 52
#  define KEY_5 53
#  define KEY_6 54
#  define KEY_7 55
# else
#  define MS_EVENT 4
#  define MS_MASK 4
#  define MS_MOVE_EVENT 6
#  define MS_MOVE_MASK 64
#  define KB_EVENT 2
#  define KB_MASK 1
#  define KEY_ESC 53
#  define KEY_LEFT 123
#  define KEY_UP 126
#  define KEY_RIGHT 124
#  define KEY_DOWN 125
#  define KEY_SPACE 49
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_4 21
#  define KEY_5 22
#  define KEY_6 23
#  define KEY_7 26
#  define MOUSE_IN 4
#  define MOUSE_OUT 5
# endif

#endif
