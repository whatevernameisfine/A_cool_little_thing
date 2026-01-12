#include "../includes/fractol.h"

int	get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000);
	return (get_color_scheme_0(iter));
}
