/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riramana <riramana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:35:45 by riramana          #+#    #+#             */
/*   Updated: 2025/07/30 18:39:37 by riramana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	validate_number_format(char *str, int *i, int *has_digit_before_dot)
{
	int	has_digit_after_dot;
	int	has_dot;

	has_digit_after_dot = 0;
	has_dot = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*has_digit_before_dot = 1;
		(*i)++;
	}
	if (str[*i] == '.')
	{
		has_dot = 1;
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			has_digit_after_dot = 1;
			(*i)++;
		}
	}
	if (str[*i] != '\0')
		return (0);
	if (has_dot)
		return (*has_digit_before_dot && has_digit_after_dot);
	return (*has_digit_before_dot);
}

int	is_valid_double(char *str)
{
	int	i;
	int	has_digit_before_dot;

	if (!str || !*str)
		return (0);
	i = 0;
	has_digit_before_dot = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (validate_number_format(str, &i, &has_digit_before_dot));
}

static int	parse_integer_part(char *str, int *i, int *sign)
{
	int	value;

	*i = 0;
	*sign = 1;
	value = 0;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		value = value * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (value);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	result;
	double	frac;

	if (!is_valid_double(str))
		return (0.0);
	result = parse_integer_part(str, &i, &sign);
	frac = 0.1;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') * frac;
			frac *= 0.1;
			i++;
		}
	}
	return (sign * result);
}

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
	{
		dst = data->img_data + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
