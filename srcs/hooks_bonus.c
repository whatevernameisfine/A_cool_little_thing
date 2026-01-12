#include "../includes/fractol_bonus.h"

static void	move_view(t_data *data, double speed, int *moved)
{
	if (data->move_up)
	{
		data->offset_y -= speed;
		*moved = 1;
	}
	if (data->move_down)
	{
		data->offset_y += speed;
		*moved = 1;
	}
	if (data->move_left)
	{
		data->offset_x -= speed;
		*moved = 1;
	}
	if (data->move_right)
	{
		data->offset_x += speed;
		*moved = 1;
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		handle_close(data);
	if (keycode == 65362)
		data->move_up = 1;
	if (keycode == 65364)
		data->move_down = 1;
	if (keycode == 65361)
		data->move_left = 1;
	if (keycode == 65363)
		data->move_right = 1;
	if (keycode == 99)
	{
		data->color_shift = (data->color_shift + 1) % 6;
		draw_fractal(data);
	}
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == 65362)
		data->move_up = 0;
	if (keycode == 65364)
		data->move_down = 0;
	if (keycode == 65361)
		data->move_left = 0;
	if (keycode == 65363)
		data->move_right = 0;
	return (0);
}

int	handle_frame(t_data *data)
{
	int		moved;
	double	speed;

	moved = 0;
	speed = 0.1 / data->zoom;
	move_view(data, speed, &moved);
	if (moved)
		draw_fractal(data);
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	data->mouse_x = x;
	data->mouse_y = y;
	return (0);
}
