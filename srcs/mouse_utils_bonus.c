/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramana <riramana@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:45:00 by riramana          #+#    #+#             */
/*   Updated: 2025/07/29 10:54:03 by riramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static void	calculate_mouse_coords(int x, int y, t_data *data, double coords[2])
{
	coords[0] = MIN_RE + x * ((MAX_RE - MIN_RE) / data->width);
	coords[1] = MIN_IM + y * ((MAX_IM - MIN_IM) / data->height);
	coords[0] = (coords[0] - (MAX_RE + MIN_RE) / 2.0) / data->zoom
		+ data->offset_x;
	coords[1] = (coords[1] - (MAX_IM + MIN_IM) / 2.0) / data->zoom
		+ data->offset_y;
}

static void	zoom_in(t_data *data, double mouse_re, double mouse_im,
		double zoom_factor)
{
	data->offset_x = mouse_re - (mouse_re - data->offset_x) / zoom_factor;
	data->offset_y = mouse_im - (mouse_im - data->offset_y) / zoom_factor;
	data->zoom *= zoom_factor;
}

static void	zoom_out(t_data *data, double mouse_re, double mouse_im,
		double zoom_factor)
{
	data->offset_x = mouse_re - (mouse_re - data->offset_x) * zoom_factor;
	data->offset_y = mouse_im - (mouse_im - data->offset_y) * zoom_factor;
	data->zoom /= zoom_factor;
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	coords[2];
	double	zoom_factor;

	zoom_factor = 1.05;
	if (button == 4 || button == 5)
	{
		calculate_mouse_coords(x, y, data, coords);
		if (button == 4)
			zoom_in(data, coords[0], coords[1], zoom_factor);
		else if (button == 5)
			zoom_out(data, coords[0], coords[1], zoom_factor);
		if (data->zoom < 0.01)
			data->zoom = 0.01;
		draw_fractal(data);
	}
	return (0);
}
