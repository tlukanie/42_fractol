/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:33:30 by tlukanie          #+#    #+#             */
/*   Updated: 2023/06/29 15:55:11 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include "MLX42/MLX42.h"
# define WINDOW_W 600
# define WINDOW_H 600
# define MAX_ITER 500

typedef union s_color
{
	uint32_t	rgba;
	struct
	{
		uint8_t	a;
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	};
}	t_color;

typedef struct mouse
{
	double	xpos;
	double	ypos;
	double	cx;
	double	cy;
}	t_mouse;

typedef struct s_movement
{
	double	ydelta;
	int32_t	key;
}	t_move;

typedef void	(*t_fractal)(mlx_t *mlx, mlx_image_t *img, \
				t_move *movement, t_mouse *mousepos);

typedef struct s_init
{
	t_fractal		display;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_mouse			mouse;
	t_move			scroll;
	t_move			arrows;
}	t_init;

typedef struct s_xy
{
	long double		xmin;
	long double		xmax;
	long double		ymin;
	long double		ymax;
	long double		dx;
	long double		dy;
	long double		y0;
	long double		x0;
	long double		x;
	long double		y;
	long double		tempx;
	uint32_t		w;
	uint32_t		h;
}	t_xy;

uint32_t	color_management(t_xy *z, float iter);
uint32_t	set_color(int32_t iter, int option);
int			color_option(void);
void		julia(mlx_t *mlx, mlx_image_t *img, \
			t_move *movement, t_mouse *mousepos);
void		mandelbrot(mlx_t *mlx, mlx_image_t *img, \
			t_move *movement, t_mouse *mousepos);
void		burning_ship(mlx_t *mlx, mlx_image_t *img, \
			t_move *movement, t_mouse *mousepos);

void		cursor_pos(double xpos, double ypos, void *param);
void		mouse_scroll(double xdelta, double ydelta, void *param);
void		resize_img(int32_t width, int32_t height, void *param);
void		set_viewport(mlx_t *mlx, t_xy *z);
void		zoom_in_out(double *zoom, long double *zoomfactor, \
			t_xy *z, t_mouse *mousepos);
void		moving_view_with_keys(uint32_t key, t_xy *z, \
			long double zoomfactor);

#endif
