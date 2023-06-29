/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:23:50 by tlukanie          #+#    #+#             */
/*   Updated: 2023/06/28 22:29:11 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_viewport(mlx_t *mlx, t_xy *z)
{
	(*z) = (t_xy){.xmin = -2.00, .xmax = 2.00, .ymin = -2.00, .ymax = 2.00};
	z->dx = ((z->xmax - z->xmin) / mlx->width);
	z->dy = ((z->ymax - z->ymin) / mlx->height);
	z->w = 0;
	z->h = 0;
}

void	moving_view_with_keys(uint32_t key, t_xy *z, long double zoomparam)
{
	if (key == MLX_KEY_UP)
	{
		z->ymin -= zoomparam;
		z->ymax -= zoomparam;
	}
	if (key == MLX_KEY_DOWN)
	{
		z->ymin += zoomparam;
		z->ymax += zoomparam;
	}
	if (key == MLX_KEY_LEFT)
	{
		z->xmin -= zoomparam;
		z->xmax -= zoomparam;
	}
	if (key == MLX_KEY_RIGHT)
	{
		z->xmin += zoomparam;
		z->xmax += zoomparam;
	}
}

void	zoom_in_out(double *zoom, long double *zoomparam, \
		t_xy *z, t_mouse *cursor)
{
	if (*zoom > 0)
	{
		*zoomparam *= 0.9;
		z->xmin += cursor->xpos * 0.005 * *zoomparam;
		z->xmax += cursor->xpos * 0.005 * *zoomparam;
		z->ymin += cursor->ypos * 0.005 * *zoomparam;
		z->ymax += cursor->ypos * 0.005 * *zoomparam;
	}
	else if (*zoom < 0)
	{
		*zoomparam *= 1.1;
		z->xmin -= cursor->xpos * 0.005 * *zoomparam;
		z->xmax -= cursor->xpos * 0.005 * *zoomparam;
		z->ymin -= cursor->ypos * 0.005 * *zoomparam;
		z->ymax -= cursor->ypos * 0.005 * *zoomparam;
	}
	*zoom = 0;
}
