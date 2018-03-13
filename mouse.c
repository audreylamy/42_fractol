/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:59:39 by alamy             #+#    #+#             */
/*   Updated: 2018/03/13 18:54:35 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	t_zoom(t_env *tmp, double mouse_re, double mouse_im, double zoom_factor)
{
	double interpolation;

	interpolation = 1.0 / zoom_factor;
	tmp->f.xmin = interpolate(mouse_re, tmp->f.xmin, interpolation);
	tmp->f.ymin = interpolate(mouse_im, tmp->f.ymin, interpolation);
	tmp->f.xmax = interpolate(mouse_re, tmp->f.xmax, interpolation);
	tmp->f.ymax = interpolate(mouse_im, tmp->f.ymax, interpolation);
}

int		my_mouse_funct(int button, int x, int y, t_env *tmp)
{
	double mouse_re;
	double mouse_im;

	mouse_re = (double)x / (WINDOW_L / (tmp->f.xmax - tmp->f.xmin))
	+ tmp->f.xmin;
	mouse_im = (double)y / (WINDOW_H / (tmp->f.ymax - tmp->f.ymin))
	+ tmp->f.ymin;
	if (button == CLIC_LEFT)
		t_zoom(tmp, mouse_re, mouse_im, 2);
	if (button == CLIC_RIGHT)
		t_zoom(tmp, mouse_re, mouse_im, 0.5);
	if (button == SCROLL_UP)
		t_zoom(tmp, mouse_re, mouse_im, 2);
	if (button == SCROLL_DOWN)
		t_zoom(tmp, mouse_re, mouse_im, 0.5);
	if (button == 8)
		t_zoom(tmp, mouse_re, mouse_im, 0.5);
	ft_redraw_image(tmp);
	return (0);
}

int		my_motion_hook(int x, int y, t_env *tmp)
{
	int largeur;

	y = 0;
	largeur = WINDOW_L / 2;
	if (x >= 0 && y >= 0 && x <= WINDOW_L && y <= WINDOW_H && tmp->f.stop != 1)
	{
		if (x > 0 && x < largeur)
		{
			tmp->f.c_re -= 0.05;
			tmp->f.c_im -= 0.05;
		}
		else if (x > largeur && x < WINDOW_L)
		{
			tmp->f.c_re += 0.05;
			tmp->f.c_im += 0.05;
		}
	}
	ft_redraw_image(tmp);
	return (0);
}
