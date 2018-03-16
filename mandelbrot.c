/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:21:25 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/16 16:21:13 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mandelbrot(t_env *tmp)
{
	tmp->f.n_re = 0;
	tmp->f.n_im = 0;
	tmp->f.o_re = 0;
	tmp->f.o_im = 0;
}

static void	ft_transformation(t_env *t, int max_iter, int x, int y)
{
	t_colorrgb	rgb;
	int			i;

	t->f.c_re = t->f.xmin + ((t->f.xmax -
				t->f.xmin) / WINDOW_L * x) + t->f.move_x;
	t->f.c_im = t->f.ymin + ((t->f.ymax -
				t->f.ymin) / WINDOW_H * y) + t->f.move_y;
	init_mandelbrot(t);
	i = 0;
	while (i < max_iter)
	{
		t->f.o_re = t->f.n_re;
		t->f.o_im = t->f.n_im;
		t->f.n_re = t->f.o_re * t->f.o_re - t->f.o_im *
				t->f.o_im + t->f.c_re;
		t->f.n_im = 2 * t->f.o_re * t->f.o_im + t->f.c_im;
		if ((t->f.n_re * t->f.n_re + t->f.n_im * t->f.n_im) > 4)
			break ;
		i++;
	}
	rgb = hsv_to_rgb(t, i % 256 + t->c, 1, i + t->max);
	fill_pixel(t, x, y, create_rgb(rgb.r, rgb.g, rgb.b));
}

void		ft_create_mandelbrot(t_env *tmp)
{
	int max_iter;
	int x;
	int y;

	max_iter = 300 + tmp->f.iter;
	x = 0;
	if (max_iter == 50)
		tmp->f.iter = 0;
	while (x < WINDOW_L)
	{
		y = 0;
		while (y < WINDOW_H)
		{
			ft_transformation(tmp, max_iter, x, y);
			y++;
		}
		x++;
	}
}
