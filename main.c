/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/03/16 17:09:12 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractal2(t_env *tmp, char *str)
{
	if (ft_strcmp(str, "tricorn") == 0)
	{
		tmp->num_f = 5;
		ft_create_tricorn(tmp);
	}
	else
	{
		ft_putstr("usage:./fractol [julia|mandelbrot|burnship|tricorn]");
		exit(0);
	}
}

void	ft_fractal1(t_env *tmp, char *str)
{
	if (ft_strcmp(str, "julia") == 0)
	{
		tmp->num_f = 1;
		init_julia(tmp);
		ft_create_julia(tmp);
	}
	else if (ft_strcmp(str, "mandelbrot") == 0)
	{
		tmp->num_f = 2;
		ft_create_mandelbrot(tmp);
	}
	else if (ft_strcmp(str, "burnship") == 0)
	{
		tmp->num_f = 3;
		ft_burn_ship(tmp);
	}
	else
		ft_fractal2(tmp, str);
}

void	ft_create_image(t_env *tmp, char *str)
{
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp,
	&tmp->img.size_bits, &tmp->img.endian);
	init_fractal(tmp);
	ft_fractal1(tmp, str);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
	ft_create_string(tmp);
}

int		main(int argc, char **argv)
{
	t_env tmp;

	if (argc != 2)
	{
		ft_putstr("usage:./fractol [julia|mandelbrot|burnship|tricorn]");
		exit(0);
	}
	else
	{
		tmp.mlx = mlx_init();
		tmp.win = mlx_new_window(tmp.mlx, WINDOW_L, WINDOW_H, "mlx 42");
		ft_create_image(&tmp, argv[1]);
		mlx_hook(tmp.win, 2, 0, my_key_funct, &tmp.mlx);
		mlx_hook(tmp.win, 4, 0, my_mouse_funct, &tmp.mlx);
		mlx_hook(tmp.win, 6, 0, my_motion_hook, &tmp.mlx);
		mlx_loop(tmp.mlx);
	}
	return (0);
}
