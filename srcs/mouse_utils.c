/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramana <riramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:45:00 by riramana          #+#    #+#             */
/*   Updated: 2025/07/30 13:48:56 by riramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	zoom_factor;

	(void)x;
	(void)y;
	zoom_factor = 1.05;
	if (button == 4)
	{
		data->zoom *= zoom_factor;
		draw_fractal(data);
	}
	else if (button == 5)
	{
		data->zoom /= zoom_factor;
		if (data->zoom < 0.01)
			data->zoom = 0.01;
		draw_fractal(data);
	}
	return (0);
}
