/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:01:10 by tlukanie          #+#    #+#             */
/*   Updated: 2023/06/29 14:56:23 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_scroll(double xdelta, double ydelta, void *param)
{
	t_init	*box;

	box = param;
	box->scroll.ydelta = ydelta;
	(void)xdelta;
	if (ydelta != 0)
		box->display(box->mlx, \
		box->img, &box->scroll, &box->mouse);
}

void	resize_img(int32_t width, int32_t height, void *param)
{
	t_init	*box;
	bool	try;

	box = param;
	try = mlx_resize_image(box->img, width, height);
	if (try == false)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_close_window(box->mlx);
	}
	else
	{
		box->mlx->width = width;
		box->mlx->height = height;
		box->display(box->mlx, \
		box->img, &box->scroll, &box->mouse);
	}
}

void	cursor_pos(double xpos, double ypos, void *param)
{
	t_init	*box;

	box = param;
	box->mouse.ypos = 0;
	box->mouse.xpos = 0;
	if (xpos >= 0 && xpos < box->mlx->width
		&& ypos >= 0 && ypos < box->mlx->height)
	{
		box->mouse.ypos = ypos - (box->mlx->height / 2);
		box->mouse.xpos = xpos - (box->mlx->width / 2);
		box->display(box->mlx, \
		box->img, &box->scroll, &box->mouse);
	}
}
