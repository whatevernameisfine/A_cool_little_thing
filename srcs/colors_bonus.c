#include "../includes/fractol_bonus.h"

static int	get_color_scheme_345(int iter, int color_shift)
{
	int	r;
	int	g;
	int	b;

	if (color_shift == 3)
	{
		r = (255 - (iter * 5) % 256);
		g = (iter * 7) % 256;
		b = (iter * 11) % 256;
	}
	else if (color_shift == 4)
	{
		r = (iter * 3) % 256;
		g = (255 - (iter * 6) % 256);
		b = (iter * 12) % 256;
	}
	else
	{
		r = (iter * 8) % 256;
		g = (iter * 4) % 256;
		b = (255 - (iter * 10) % 256);
	}
	return (r << 16 | g << 8 | b);
}

int	get_color(int iter, int color_shift)
{
	if (iter == MAX_ITER)
		return (0x000000);
	if (color_shift == 0)
		return (get_color_scheme_0(iter));
	else if (color_shift == 1)
		return (get_color_scheme_1(iter));
	else if (color_shift == 2)
		return (get_color_scheme_2(iter));
	else
		return (get_color_scheme_345(iter, color_shift));
}
