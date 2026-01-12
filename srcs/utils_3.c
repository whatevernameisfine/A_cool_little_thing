#include "../includes/fractol.h"
#include "../minilibx-linux/mlx.h"

int	init_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		return (1);
	data->img_data = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->img_data)
		return (1);
	return (0);
}

int	get_color_scheme_0(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (iter * 9) % 256;
	g = (iter * 2) % 256;
	b = (iter * 15) % 256;
	return (r << 16 | g << 8 | b);
}
