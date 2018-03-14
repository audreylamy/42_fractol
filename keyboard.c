/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:46:20 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/14 10:38:10 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#

void		ft_redraw_image(t_env *tmp)
{
	mlx_clear_window(tmp->mlx, tmp->win);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp,
			&tmp->img.size_bits, &tmp->img.endian);
	if (tmp->num_f == 1)
		ft_create_julia(tmp);
	else if (tmp->num_f == 2)
		ft_create_mandelbrot(tmp);
	else if (tmp->num_f == 3)
		ft_burn_ship(tmp);
	else if (tmp->num_f == 4)
		ft_create_barnsleyfern(tmp);
	else if (tmp->num_f == 5)
		ft_create_tricorn(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
	ft_create_string(tmp);
}

static void	ft_move(t_env *tmp, int keycode)
{
	if (keycode == LEFT)
		tmp->f.move_x += 0.1;
	else if (keycode == RIGHT)
		tmp->f.move_x -= 0.1;
	else if (keycode == UP)
		tmp->f.move_y += 0.1;
	else if (keycode == DOWN)
		tmp->f.move_y -= 0.1;
	else if (keycode == ITER_UP)
		tmp->f.iter += 50;
	else if (keycode == ITER_DOWN)
		tmp->f.iter -= 50;
	else if (keycode == COLOR_UP)
		tmp->c += 5;
	else if (keycode == COLOR_DOWN)
		tmp->c -= 5;
	else if (keycode == STOP)
	{
		if (tmp->f.stop == 0)
			tmp->f.stop = 1;
		else if (tmp->f.stop == 1)
			tmp->f.stop = 0;
	}
}

static void	ft_choose_fractal(t_env *tmp, int keycode)
{
	if (keycode == JULIA)
	{
		init_fractal(tmp);
		init_julia(tmp);
		tmp->num_f = 1;
	}
	else if (keycode == MANDELBROT)
	{
		init_fractal(tmp);
		tmp->num_f = 2;
	}
	else if (keycode == BURNSHIP)
	{
		init_fractal(tmp);
		tmp->num_f = 3;
	}
	else if (keycode == TRICORN)
	{
		init_fractal(tmp);
		tmp->num_f = 5;
	}
}

int			my_key_funct(int keycode, t_env *tmp)
{
	if (keycode == EXIT)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		exit(1);
	}
	ft_move(tmp, keycode);
	ft_choose_fractal(tmp, keycode);
	if (keycode == BARNSLEY)
	{
		init_fractal(tmp);
		tmp->num_f = 4;
	}
	else if (keycode == 8)
	{
		tmp->barn.zoom_b += 5;
		tmp->f.iter += 500000;
	}
	ft_redraw_image(tmp);
	return (0);
}
