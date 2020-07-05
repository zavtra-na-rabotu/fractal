#include "fractol.h"
#include "colors.h"

void	palette1(int palette[])
{
	palette[0] = BASE_COLOR;
	palette[1] = rgb(25, 7, 26);
	palette[2] = rgb(9, 1, 47);
	palette[3] = rgb(4, 4, 73);
	palette[4] = rgb(0, 7, 100);
	palette[5] = rgb(12, 44, 138);
	palette[6] = rgb(24, 82, 177);
	palette[7] = rgb(57, 125, 209);
	palette[8] = rgb(134, 181, 229);
	palette[9] = rgb(211, 236, 248);
	palette[10] = rgb(241, 233, 191);
	palette[11] = rgb(248, 201, 95);
	palette[12] = rgb(255, 170, 0);
	palette[13] = rgb(204, 128, 0);
	palette[14] = rgb(153, 87, 0);
	palette[15] = rgb(106, 52, 3);
}

void	palette2(int palette[])
{
	palette[15] = BASE_COLOR;
	palette[14] = rgb(25, 7, 26);
	palette[13] = rgb(9, 1, 47);
	palette[12] = rgb(4, 4, 73);
	palette[11] = rgb(0, 7, 100);
	palette[10] = rgb(12, 44, 138);
	palette[9] = rgb(24, 82, 177);
	palette[8] = rgb(57, 125, 209);
	palette[7] = rgb(134, 181, 229);
	palette[6] = rgb(211, 236, 248);
	palette[5] = rgb(241, 233, 191);
	palette[4] = rgb(248, 201, 95);
	palette[3] = rgb(255, 170, 0);
	palette[2] = rgb(204, 128, 0);
	palette[1] = rgb(153, 87, 0);
	palette[0] = rgb(106, 52, 3);
}

void	palette3(int palette[])
{
	palette[0] = BASE_COLOR;
	palette[1] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[2] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[3] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[4] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[5] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[6] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[7] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[8] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[9] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[10] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[11] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[12] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[13] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[14] = rgb(rand() % 256, rand() % 256, rand() % 256);
	palette[15] = rgb(rand() % 256, rand() % 256, rand() % 256);
}

void	palette4(int palette[])
{
	palette[0] = rgb(88, 24, 69);
	palette[1] = rgb(88, 24, 69);
	palette[2] = rgb(88, 24, 69);
	palette[3] = rgb(144, 12, 63);
	palette[4] = rgb(144, 12, 63);
	palette[5] = rgb(144, 12, 63);
	palette[6] = rgb(199, 0, 57);
	palette[7] = rgb(199, 0, 57);
	palette[8] = rgb(199, 0, 57);
	palette[9] = rgb(255, 87, 51);
	palette[10] = rgb(255, 87, 51);
	palette[11] = rgb(255, 87, 51);
	palette[12] = rgb(255, 195, 5);
	palette[13] = rgb(255, 195, 5);
	palette[14] = rgb(255, 195, 5);
	palette[15] = rgb(255, 195, 5);
}

void	palette5(int palette[])
{
	palette[0] = rgb(26, 19, 52);
	palette[1] = rgb(26, 19, 52);
	palette[2] = rgb(38, 41, 74);
	palette[3] = rgb(1, 84, 90);
	palette[4] = rgb(1, 115, 81);
	palette[5] = rgb(1, 115, 81);
	palette[6] = rgb(3, 195, 131);
	palette[7] = rgb(170, 217, 98);
	palette[8] = rgb(170, 217, 98);
	palette[9] = rgb(251, 191, 69);
	palette[10] = rgb(239, 106, 50);
	palette[11] = rgb(237, 3, 69);
	palette[12] = rgb(161, 42, 94);
	palette[13] = rgb(113, 1, 98);
	palette[14] = rgb(17, 1, 65);
	palette[15] = rgb(17, 1, 65);
}
