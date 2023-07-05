/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:04:16 by tlukanie          #+#    #+#             */
/*   Updated: 2023/07/05 07:21:24 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_press(mlx_key_data_t keydata, void *param)
{
	t_init	*box;

	box = param;
	box->arrows.key = keydata.key;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(box->mlx);
	if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN || \
		keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT) && \
		keydata.action == MLX_PRESS)
		box->display(box->mlx, \
		box->img, &box->arrows, &box->mouse);
}

static	t_fractal	get_set(int32_t argc, char **input)
{
	char	option;

	if (argc == 2)
	{
		option = input[1][0];
		if (option == 'M' && input[1][1] == '\0')
		{
			return (mandelbrot);
		}
		else if (option == 'J' && input[1][1] == '\0')
			return (julia);
		else if (option == 'B' && input[1][1] == '\0')
			return (burning_ship);
	}
	else
		return (NULL);
	return (NULL);
}

bool	execute_fractol(t_init *param)
{
	if (!param->display)
	{
		ft_putendl_fd("try: \
		./fractol M for Mandelbrot Set\n \
		./fractol J for Julia Set\n \
		./fractol B for Burning Ship Set", \
		STDERR_FILENO);
		return (true);
	}
	param->mlx = mlx_init(WINDOW_W, WINDOW_H, "Fractol", true);
	if (!param->mlx)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		return (true);
	}
	param->img = mlx_new_image(param->mlx, WINDOW_W, WINDOW_H);
	if (!param->img)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_terminate(param->mlx);
		return (true);
	}
	param->display(param->mlx, param->img, \
	&param->scroll, &param->mouse);
	return (false);
}

int	main(int32_t argc, char **argv)
{
	t_init	box;

	box.display = get_set(argc, argv);
	if (execute_fractol(&box))
		return (EXIT_FAILURE);
	if (mlx_image_to_window(box.mlx, box.img, 0, 0) == -1)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), STDERR_FILENO);
		mlx_terminate(box.mlx);
		return (EXIT_FAILURE);
	}
	mlx_key_hook(box.mlx, key_press, &box);
	mlx_cursor_hook(box.mlx, cursor_pos, &box);
	mlx_scroll_hook(box.mlx, mouse_scroll, &box);
	mlx_resize_hook(box.mlx, resize_img, &box);
	mlx_loop(box.mlx);
	mlx_terminate(box.mlx);
	return (0);
}
