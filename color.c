/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:23:18 by alamy             #+#    #+#             */
/*   Updated: 2018/03/14 10:45:17 by alamy            ###   ########.fr       */
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

static void		init_color(t_color *color, double h)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	while (h < 0)
	{
		h += 360;
	}
	while (h >= 360)
	{
		h -= 360;
	}
}

static t_color	*ft_choose_color(t_color *color, double v, int i)
{
	if (i == 0)
	{
		color->r = v;
		color->g = color->t;
		color->b = color->p;
	}
	else if (i == 1)
	{
		color->r = color->q;
		color->g = v;
		color->b = color->p;
	}
	else if (i == 2)
	{
		color->r = color->p;
		color->g = v;
		color->b = color->t;
	}
	else if (i == 3)
	{
		color->r = color->p;
		color->g = color->q;
		color->b = v;
	}
	else if (i == 4)
	{
		color->r = color->t;
		color->g = color->p;
		color->b = v;
	}
	else
	{
		color->r = v;
		color->g = color->p;
		color->b = color->q;
	}
	return (color);
}

t_colorrgb		hsv_to_rgb(double h, double s, double v)
{
	t_colorrgb	rgb;
	t_color		color;
	int			i;

	init_color(&color, h);
	if (s <= 0)
	{
		color.r = v;
		color.g = v;
		color.b = v;
	}
	else
	{
		h = h / 60;
		i = (int)floor(h);
		color.f = h - i;
		color.p = v * (1.0 - s);
		color.q = v * (1.0 - (s * color.f));
		color.t = v * (1.0 - (s * (1.0 - color.f)));
		ft_choose_color(&color, v, i);
	}
	rgb.r = color.r * 255;
	rgb.g = color.g * 255;
	rgb.b = color.b * 255;
	return (rgb);
}
