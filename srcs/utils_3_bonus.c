/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramana <riramana@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:00:00 by riramana          #+#    #+#             */
/*   Updated: 2025/07/29 10:54:21 by riramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"
#include "../minilibx-linux/mlx.h"

void	write_usage(void)
{
	ssize_t ignored;

	ignored = write(1, "Usage:\n  ./fractol mandelbrot\n", 31);
	(void)ignored;
	ignored = write(1, "  ./fractol julia [<real> <imag>]\n", 33);
	(void)ignored;
	ignored = write(1, "  ./fractol burning_ship\n", 24);
	(void)ignored;
}

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

int	get_color_scheme_1(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (iter * 15) % 256;
	g = (iter * 9) % 256;
	b = (iter * 2) % 256;
	return (r << 16 | g << 8 | b);
}

int	get_color_scheme_2(int iter)
{
	int	r;
	int	g;
	int	b;

	r = (iter * 2) % 256;
	g = (iter * 15) % 256;
	b = (iter * 9) % 256;
	return (r << 16 | g << 8 | b);
}
int	init_window(t_data *data)
{
	char	*title;

	if (data->fractal_type == 1)
		title = "mandelbrot";
	else if (data->fractal_type == 2)
		title = "julia";
	else
		title = "burning_ship";
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->window = mlx_new_window(data->mlx, data->width, data->height, title);
	if (!data->window)
		return (1);
	return (init_image(data));
}
