/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:48:47 by tlukanie          #+#    #+#             */
/*   Updated: 2023/06/29 14:49:43 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	algorithm_j(t_xy *z, mlx_image_t *img, t_mouse *cursor)
{
	int32_t	iter;
	t_color	color_limit;

	z->x = z->x0;
	z->y = z->y0;
	cursor->cx = sin(cursor->xpos / 100);
	cursor->cy = sin(cursor->ypos / 100);
	iter = 0;
	color_limit = (t_color){.rgba = 0x000000FF};
	while ((z->x * z->x) + (z->y * z->y) <= (1 << 16) && iter < MAX_ITER)
	{
		z->tempx = z->x * z->x - z->y * z->y + cursor->cx;
		z->y = 2.0 * z->x * z->y + cursor->cy;
		z->x = z->tempx;
		iter++;
	}
	if (z->w >= 0 && z->w < img->width
		&& z->h >= 0 && z->h < img->height)
	{
		if (iter < MAX_ITER)
			mlx_put_pixel(img, z->w, z->h, color_management(z, iter));
		else
			mlx_put_pixel(img, z->w, z->h, color_limit.rgba);
	}
}

void	julia(mlx_t *mlx, mlx_image_t *img, \
		t_move *movement, t_mouse *cursor)
{
	static t_xy			z;
	static long double	zoomparam = 1;

	if (zoomparam == 1)
		set_viewport(mlx, &z);
	if (movement->key > 0)
		moving_view_with_keys(movement->key, &z, zoomparam);
	if (movement->ydelta != 0)
		zoom_in_out(&movement->ydelta, &zoomparam, &z, cursor);
	z.y0 = z.ymin;
	while (z.h < (uint32_t)mlx->height)
	{
		z.x0 = z.xmin;
		while (z.w < (uint32_t)mlx->width)
		{
			algorithm_j(&z, img, cursor);
			z.x0 += z.dx * zoomparam;
			z.w++;
		}
		z.y0 += z.dy * zoomparam;
		z.h++;
		z.w = 0;
	}
	z.h = 0;
}
