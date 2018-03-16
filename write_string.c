/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:53:21 by alamy             #+#    #+#             */
/*   Updated: 2018/03/16 16:44:40 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_string(t_env *t)
{
	mlx_string_put(t->mlx, t->win, 10, 0, 16777215, "Quit : esc");
	mlx_string_put(t->mlx, t->win, 10, 20, 16777215, "Stop Julia : space");
	mlx_string_put(t->mlx, t->win, 10, 40, 16777215, "Julia : 1");
	mlx_string_put(t->mlx, t->win, 10, 60, 16777215, "Mandelbrot : 2");
	mlx_string_put(t->mlx, t->win, 10, 80, 16777215, "Burnship : 3");
	mlx_string_put(t->mlx, t->win, 10, 100, 16777215, "Barnsley : 4");
	mlx_string_put(t->mlx, t->win, 10, 120, 16777215, "Tricorn : 5");
	mlx_string_put(t->mlx, t->win, 10, 140, 16777215,
	"Zoom or scroll + : Right clic");
	mlx_string_put(t->mlx, t->win, 10, 160, 16777215,
	"Zoom or scroll - : Left clic");
	mlx_string_put(t->mlx, t->win, 10, 200, 16777215, "Color + : Return");
	mlx_string_put(t->mlx, t->win, 10, 220, 16777215, "Color - : Shift");
	mlx_string_put(t->mlx, t->win, 10, 240, 16777215, "Color R : R");
	mlx_string_put(t->mlx, t->win, 10, 260, 16777215, "Color G : G");
	mlx_string_put(t->mlx, t->win, 10, 280, 16777215, "Color B : B");
}
