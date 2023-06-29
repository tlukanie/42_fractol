/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:51:11 by tlukanie          #+#    #+#             */
/*   Updated: 2023/01/19 12:38:48 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	int		end;
	int		s_len;

	s_len = ft_strlen(s);
	end = 0;
	if (s == NULL)
		return (NULL);
	if ((int)start < s_len)
		end = s_len - start;
	if (end > (int)len)
		end = len;
	substring = (char *)malloc(sizeof(char) * (end + 1));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, end + 1);
	return (substring);
}
