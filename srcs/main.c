#include "../includes/fractol.h"
#include "../minilibx-linux/mlx.h"
#include <unistd.h>

static int	validate_julia_args(char **argv, t_data *data)
{
	ssize_t ignored;
	if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
	{
		ignored = write(1, "Error: Invalid number format\n", 29);
		(void)ignored;
		ignored = write(1, "Usage: ./fractol julia <real> <imag>\n", 37);
		(void)ignored;
		return (1);
	}
	data->julia_re = ft_atod(argv[2]);
	data->julia_im = ft_atod(argv[3]);
	return (0);
}

static int	handle_julia(t_data *data, int argc, char **argv)
{
	ssize_t ignored;
	data->fractal_type = 2;
	if (argc == 4)
	{
		return (validate_julia_args(argv, data));
	}
	else if (argc == 2)
	{
		data->julia_re = -0.8;
		data->julia_im = 0.156;
	}
	else
	{
		ignored = write(1, "Usage:\n ./fractol julia <real> <imag>\n", 39);
		(void)ignored;
		return (1);
	}
	return (0);
}

static int	parse_args(t_data *data, int argc, char **argv)
{
	ssize_t ignored;
	if (argc >= 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		if (argc != 2)
		{
			ignored = write(1, "Usage:\n  ./fractol mandelbrot\n", 30);
			(void)ignored;
			return (1);
		}
		data->fractal_type = 1;
		return (0);
	}
	else if (argc >= 2 && ft_strcmp(argv[1], "julia") == 0)
	{
		return (handle_julia(data, argc, argv));
	}
	ignored = write(1, "Usage:\n  ./fractol mandelbrot\n", 31);
	(void)ignored;
	ignored = write(1, "  ./fractol julia [<real> <imag>]\n", 33);
	(void)ignored;
	return (1);
}

static int	init_window(t_data *data)
{
	char	*title;

	if (data->fractal_type == 1)
		title = "mandelbrot";
	else
		title = "julia";
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->window = mlx_new_window(data->mlx, data->width, data->height, title);
	if (!data->window)
		return (1);
	return (init_image(data));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_args(&data, argc, argv))
		return (1);
	init_data(&data);
	if (init_window(&data))
		return (1);
	draw_fractal(&data);
	mlx_hook(data.window, 2, 1L << 0, handle_keypress, &data);
	mlx_mouse_hook(data.window, handle_mouse, &data);
	mlx_hook(data.window, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
