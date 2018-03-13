/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet_serpinski.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:20:54 by alamy             #+#    #+#             */
/*   Updated: 2018/03/08 16:24:33 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_create_serpinski(t_env *tmp)
{
	int x;
	int y;
	t_colorrgb rgb;
	
	x = 0;
	while(x < WINDOW_L)
	{
		y = 0;
  		while(y < WINDOW_H)
  		{
			if(!((x / 1) % 2 == 1 && (y / 1) % 3 == 1) && 
				!((x / 3) % 3 == 1 && (y / 3) % 3 == 1) &&
				!((x / 9) % 3 == 1 && (y / 9) % 3 == 1) &&
				!((x / 27) % 3 == 1 && (y / 27) % 3 == 1) &&
				!((x / 81) % 3 == 1 && (y / 81) % 3 == 1))
				{
				rgb = HSVtoRGB(256, 1, 1);
				fill_pixel(tmp, x, y, createRGBA(rgb.r, rgb.g, rgb.b));
				}
			y++;
		}	
		x++;
	}
}