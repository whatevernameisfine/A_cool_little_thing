/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramana <riramana@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:22:00 by riramana          #+#    #+#             */
/*   Updated: 2025/08/23 13:45:00 by riramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define MIN_RE -2.0
# define MAX_RE 2.0
# define MIN_IM -2.0
# define MAX_IM 2.0
# define MAX_ITER 100

typedef struct s_complex
{
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	int		iter;
}	t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		fractal_type;
	double	julia_re;
	double	julia_im;
	int		move_up;
	int		move_down;
	int		move_left;
	int		move_right;
	int		color_shift;
	int		mouse_x;
	int		mouse_y;
}	t_data;

// Existing function declarations
int		ft_strcmp(char *s1, char *s2);
void	init_data(t_data *data);
void	draw_fractal(t_data *data);
int		mandelbrot_at(int x, int y, t_data *data);
int		julia_at(int x, int y, t_data *data);
int		burning_ship_at(int x, int y, t_data *data);
int		get_color(int iter, int color_shift);
int		get_color_scheme_0(int iter);
int		get_color_scheme_1(int iter);
int		get_color_scheme_2(int iter);
int		handle_keypress(int keycode, t_data *data);
int		handle_keyrelease(int keycode, t_data *data);
int		handle_frame(t_data *data);
int		handle_close(t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
int		is_valid_double(char *str);
double	ft_atod(char *str);
void	put_pixel_to_image(t_data *data, int x, int y, int color);
int		init_image(t_data *data);
void	write_usage(void);
int		init_window(t_data *data);

// New multithreading function
void	draw_fractal_threaded(t_data *data);

#endif
