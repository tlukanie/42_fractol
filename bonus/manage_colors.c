/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:47:36 by tlukanie          #+#    #+#             */
/*   Updated: 2023/06/29 15:17:11 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_option(void)
{
	int	i;

	i = 1;
	return (i);
}

uint32_t	set_color(int32_t iter, int option)
{
	t_color	color;

	if (option == 1)
	{
		color.a = 255;
		color.b = (uint8_t)(sin(0.2 * iter) * 67 + 10);
		color.g = (uint8_t)(sin(0.3 * iter + 2) * 127 + 130);
		color.r = (uint8_t)(sin(0.3 * iter + 4) * 127 + 110);
	}
	return (color.rgba);
}

static uint32_t	insert_colors(uint32_t first_color, uint32_t second_color, \
			float fmod_remainder)
{
	t_color	c_1;
	t_color	c_2;

	c_1.r = (first_color >> 24) & 0xff;
	c_2.r = (second_color >> 24) & 0xff;
	c_1.g = (first_color >> 16) & 0xff;
	c_2.g = (second_color >> 16) & 0xff;
	c_1.b = (first_color >> 8) & 0xff;
	c_2.b = (second_color >> 8) & 0xff;
	return ((uint32_t)(((c_2.r - c_1.r) * fmod_remainder) + c_1.r) << 24 | \
			(uint32_t)(((c_2.g - c_1.g) * fmod_remainder) + c_1.g) << 16 | \
			(uint32_t)(((c_2.b - c_1.b) * fmod_remainder) + c_1.b) << 8 | 255);
}

uint32_t	color_management(t_xy *z, float iter)
{
	double			log_of_z;
	uint32_t		first_color;
	uint32_t		second_color;

	log_of_z = log((z->x * z->x) + (z->y * z->y)) / 2;
	first_color = set_color(iter, color_option());
	second_color = set_color(iter + 1, color_option());
	return (insert_colors(first_color, second_color, \
		fmod((iter - (log(log_of_z / log(2)) / log(2))), 1)));
}
