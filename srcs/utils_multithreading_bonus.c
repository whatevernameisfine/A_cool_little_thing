#include "../includes/fractol_bonus.h"
#include "../minilibx-linux/mlx.h"
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 8

typedef struct s_thread_data
{
	t_data	*data;
	int		start_y;
	int		end_y;
	int		thread_id;
}	t_thread_data;

static void	*render_section_bonus(void *arg)
{
	t_thread_data	*thread_data;
	int				x;
	int				y;
	int				iter;
	int				color;

	thread_data = (t_thread_data *)arg;
	y = thread_data->start_y;
	while (y < thread_data->end_y)
	{
		x = 0;
		while (x < thread_data->data->width)
		{
			if (thread_data->data->fractal_type == 1)
				iter = mandelbrot_at(x, y, thread_data->data);
			else if (thread_data->data->fractal_type == 2)
				iter = julia_at(x, y, thread_data->data);
			else
				iter = burning_ship_at(x, y, thread_data->data);
			color = get_color(iter, thread_data->data->color_shift);
			put_pixel_to_image(thread_data->data, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	draw_fractal_threaded(t_data *data)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				rows_per_thread;
	int				i;

	rows_per_thread = data->height / NUM_THREADS;
	i = 0;
	while (i < NUM_THREADS)
	{
		thread_data[i].data = data;
		thread_data[i].start_y = i * rows_per_thread;
		thread_data[i].end_y = (i == NUM_THREADS - 1) ? 
			data->height : (i + 1) * rows_per_thread;
		thread_data[i].thread_id = i;
		pthread_create(&threads[i], NULL, render_section_bonus, &thread_data[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
