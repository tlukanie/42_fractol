/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:05:24 by tlukanie          #+#    #+#             */
/*   Updated: 2023/01/20 14:34:13 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*my_dest;
	char	*my_src;
	int		i;

	if (!dest && !src)
		return (NULL);
	my_dest = (char *)dest;
	my_src = (char *)src;
	i = 0;
	while (i < (int)n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (dest);
}
