/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/03/14 10:35:31 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_L 1500
# define WINDOW_H 1200
# define PI 3.14159265359

# include "minilibx/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include <pthread.h>

# define PTHREAD_MUTEX_INITIALIZER {_PTHREAD_MUTEX_SIG_init, {0}}

# define EXIT 53
# define STOP 49
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ITER_UP 69
# define ITER_DOWN 78
# define COLOR_UP 36
# define COLOR_DOWN 258
# define CLIC_RIGHT 2
# define CLIC_LEFT 1
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define JULIA 83
# define MANDELBROT 84
# define BURNSHIP 85
# define BARNSLEY 86
# define TRICORN 87

typedef struct	s_colorrgb
{
	int			r;
	int			g;
	int			b;
}				t_colorrgb;

typedef struct	s_colorhsv
{
	double		h;
	double		s;
	double		v;
}				t_colorhsv;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	double		f;
	double		p;
	double		q;
	double		t;
}				t_color;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_bits;
	int			endian;
	int			color;
}				t_img;

typedef struct	s_barn
{
	double		zoom_b;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
}				t_barn;

typedef struct	s_fractal
{
	double		c_re;
	double		c_im;
	double		n_re;
	double		n_im;
	double		o_re;
	double		o_im;
	float		move_x;
	float		move_y;
	double		xmin;
	double		ymin;
	double		xmax;
	double		ymax;
	int			iter;
	int			stop;
}				t_fractal;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			num_f;
	t_barn		barn;
	t_fractal	f;
	double		c;
}				t_env;

typedef struct	s_thread
{
	int var;
	pthread_mutex_t mutex;
}				t_thread;

int				main(int argc, char **argv);
void			ft_create_image(t_env *tmp, char *str);
void			ft_fractal(t_env *tmp, char *str);
void			ft_fractal2(t_env *tmp, char *str);
void			ft_redraw_image(t_env *tmp);
void			fill_pixel(t_env *t, int x, int y, int color);
int				create_rgb(int r, int g, int b);
t_colorrgb		hsv_to_rgb(double r, double g, double b);
void			ft_create_string(t_env *t);

/*
**EVENTS
*/

int				my_key_funct(int keycode, t_env *tmp);
int				my_mouse_funct(int button, int x, int y, t_env *tmp);
int				my_motion_hook(int x, int y, t_env *tmp);

/*
** FRACTALs
*/

void			init_fractal(t_env *tmp);
void			init_julia(t_env *tmp);
void			ft_create_julia(t_env *tmp);
void			ft_create_mandelbrot(t_env *tmp);
void			ft_burn_ship(t_env *tmp);
void			ft_create_tricorn(t_env *tmp);
void			ft_create_barnsleyfern(t_env *tmp);

#endif
