#include "../includes/fractol.h"

int	mandelbrot_at(int x, int y, t_data *data)
{
	t_complex	c;
	double		zr2;
	double		zi2;

	c.cr = MIN_RE + x * ((MAX_RE - MIN_RE) / data->width);
	c.ci = MIN_IM + y * ((MAX_IM - MIN_IM) / data->height);
	c.cr = (c.cr - (MAX_RE + MIN_RE) / 2.0) / data->zoom + data->offset_x;
	c.ci = (c.ci - (MAX_IM + MIN_IM) / 2.0) / data->zoom + data->offset_y;
	c.zr = 0.0;
	c.zi = 0.0;
	c.iter = 0;
	while (c.iter < MAX_ITER)
	{
		zr2 = c.zr * c.zr;
		zi2 = c.zi * c.zi;
		if ((zr2 + zi2) > 4.0)
			break ;
		c.zi = 2.0 * c.zr * c.zi + c.ci;
		c.zr = zr2 - zi2 + c.cr;
		c.iter++;
	}
	return (c.iter);
}

int	julia_at(int x, int y, t_data *data)
{
	t_complex	z;
	double		zr2;
	double		zi2;
	int			iter;

	z.zr = MIN_RE + x * ((MAX_RE - MIN_RE) / data->width);
	z.zi = MIN_IM + y * ((MAX_IM - MIN_IM) / data->height);
	z.zr = (z.zr - (MAX_RE + MIN_RE) / 2.0) / data->zoom + data->offset_x;
	z.zi = (z.zi - (MAX_IM + MIN_IM) / 2.0) / data->zoom + data->offset_y;
	z.cr = data->julia_re;
	z.ci = data->julia_im;
	iter = 0;
	while (iter < MAX_ITER)
	{
		zr2 = z.zr * z.zr;
		zi2 = z.zi * z.zi;
		if ((zr2 + zi2) > 4.0)
			break ;
		z.zi = 2.0 * z.zr * z.zi + z.ci;
		z.zr = zr2 - zi2 + z.cr;
		iter++;
	}
	return (iter);
}
