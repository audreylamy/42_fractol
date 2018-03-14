/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:33:52 by alamy             #+#    #+#             */
/*   Updated: 2018/03/14 10:41:51 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_fractal(t_env *tmp)
{
	tmp->f.xmax = 2.4;
	tmp->f.xmin = -2.4;
	tmp->f.ymax = 1.5;
	tmp->f.ymin = -1.5;
	tmp->f.stop = 0;
	tmp->f.iter = 0;
	tmp->c = 0;
}

void		init_julia(t_env *tmp)
{
	tmp->f.c_re = -0.7;
	tmp->f.c_im = 0.27015;
}

static void	ft_transformation(t_env *tmp, int max_iter, int x, int y)
{
	int			i;
	t_colorrgb	rgb;

	tmp->f.n_re = tmp->f.xmin + ((tmp->f.xmax -
	tmp->f.xmin) / WINDOW_L * x) + tmp->f.move_x;
	tmp->f.n_im = tmp->f.ymin + ((tmp->f.ymax -
	tmp->f.ymin) / WINDOW_H * y) + tmp->f.move_y;
	i = 0;
	while (i < max_iter)
	{
		tmp->f.o_re = tmp->f.n_re;
		tmp->f.o_im = tmp->f.n_im;
		tmp->f.n_re = tmp->f.o_re * tmp->f.o_re - tmp->f.o_im *
		tmp->f.o_im + tmp->f.c_re;
		tmp->f.n_im = 2 * tmp->f.o_re * tmp->f.o_im + tmp->f.c_im;
		if ((tmp->f.n_re * tmp->f.n_re + tmp->f.n_im * tmp->f.n_im) > 4)
			break ;
		i++;
	}
	rgb = hsv_to_rgb(i % 256 + tmp->c, 1, i < max_iter);
	fill_pixel(tmp, x, y, create_rgb(rgb.r, rgb.g, rgb.b));
}

void		ft_create_julia(t_env *tmp)
{
	int			y;
	int			x;
	int			max_iter;

	max_iter = 300 + tmp->f.iter;
	if (max_iter == 50)
		tmp->f.iter = 0;
	x = 0;
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
