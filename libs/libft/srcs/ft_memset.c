/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:46:05 by tlukanie          #+#    #+#             */
/*   Updated: 2023/01/10 15:23:20 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ch;
	int				i;

	ch = s;
	i = 0;
	while (n > 0)
	{
		ch[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
