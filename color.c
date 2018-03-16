/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:23:18 by alamy             #+#    #+#             */
/*   Updated: 2018/03/16 17:12:04 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			fill_pixel(t_env *t, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WINDOW_L && y < WINDOW_H)
	{
		((int*)t->img.data)[(y * WINDOW_L) + x] = color;
	}
}

int				create_rgb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

static void		init_color(t_color *color, double hue)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	while (hue < 0)
	{
		hue += 360;
	}
	while (hue >= 360)
	{
		hue -= 360;
	}
}

static t_color	*ft_choose_color(t_color *color, double value, int i)
{
	if (i == 0)
	{
		color->r = value;
		color->g = color->t;
		color->b = color->p;
	}
	else if (i == 1)
	{
		color->r = color->q;
		color->g = value;
		color->b = color->p;
	}
	else if (i == 2)
	{
		color->r = color->p;
		color->g = value;
		color->b = color->t;
	}
	else if (i == 3)
	{
		color->r = color->p;
		color->g = color->q;
		color->b = value;
	}
	else if (i == 4)
	{
		color->r = color->t;
		color->g = color->p;
		color->b = value;
	}
	else
	{
		color->r = value;
		color->g = color->p;
		color->b = color->q;
	}
	return (color);
}

t_colorrgb		hsv_to_rgb(t_env *tmp, double hue, double sat, double value)
{
	t_colorrgb	rgb;
	t_color		color;
	int			i;

	init_color(&color, hue);
	if (sat <= 0)
	{
		color.r = value;
		color.g = value;
		color.b = value;
	}
	else
	{
		hue = hue / 60;
		i = (int)floor(hue);
		color.f = hue - i;
		color.p = value * (1.0 - sat);
		color.q = value * (1.0 - (sat * color.f));
		color.t = value * (1.0 - (sat * (1.0 - color.f)));
		ft_choose_color(&color, value, i);
	}
	rgb.r = color.r * 255 + tmp->barn.move_r;
	rgb.g = color.g * 255 + tmp->barn.move_g;
	rgb.b = color.b * 255 + tmp->barn.move_b;
	return (rgb);
}
