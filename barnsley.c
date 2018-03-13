/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:29:37 by alamy             #+#    #+#             */
/*   Updated: 2018/03/13 18:29:52 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>
#include <limits.h>

static void	ft_transformation(t_env *t, int random, int zoom)
{
	t_colorrgb		rgb;

	if (random == 0)
	{
		t->barn.x1 = 0;
		t->barn.y1 = 0.16 * t->barn.y0;
	}
	else if (random >= 1 && random <= 7)
	{
		t->barn.x1 = -0.15 * t->barn.x0 + 0.28 * t->barn.y0;
		t->barn.y1 = 0.26 * t->barn.x0 + 0.24 * t->barn.y0 + 0.44;
	}
	else if (random >= 8 && random <= 15)
	{
		t->barn.x1 = 0.2 * t->barn.x0 - 0.26 * t->barn.y0;
		t->barn.y1 = 0.23 * t->barn.x0 + 0.22 * t->barn.y0 + 1.6;
	}
	else
	{
		t->barn.x1 = 0.85 * t->barn.x0 + 0.04 * t->barn.y0;
		t->barn.y1 = -0.04 * t->barn.x0 + 0.85 * t->barn.y0 + 1.6;
	}
	rgb = HSVtoRGB(323 + t->c, 1 + t->c, 0.46 + t->c);
	fill_pixel(t, (zoom + t->barn.zoom_b) * t->barn.x1 + WINDOW_L /
	2.0, (zoom + t->barn.zoom_b) * t->barn.y1, createRGBA(rgb.r, rgb.g, rgb.b));
}

void		ft_create_barnsleyfern(t_env *tmp)
{
	unsigned long	iter;
	int				zoom;
	int				random;

	iter = 9050000 + tmp->f.iter;
	tmp->barn.x0 = 0;
	tmp->barn.y0 = 0;
	zoom = 110;
	if (iter == 50)
		tmp->f.iter = 0;
	while (iter > 0)
	{
		random = rand() % 100;
		ft_transformation(tmp, random, zoom);
		tmp->barn.x0 = tmp->barn.x1;
		tmp->barn.y0 = tmp->barn.y1;
		iter--;
	}
}
