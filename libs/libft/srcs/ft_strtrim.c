/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:49:57 by tlukanie          #+#    #+#             */
/*   Updated: 2023/01/17 14:07:25 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*arr;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (check_set(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	len = ft_strlen(s1);
	while (len != 0)
	{
		if (check_set(s1[len - 1], set) == 1)
			len--;
		else
			break ;
	}
	arr = (char *)malloc(len * sizeof(char) + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, (char *)s1, len + 1);
	return (arr);
}
