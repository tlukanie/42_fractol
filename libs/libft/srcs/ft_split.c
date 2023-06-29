/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:59:47 by tlukanie          #+#    #+#             */
/*   Updated: 2023/01/20 15:15:22 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check_separator(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	count_strings(char const *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_separator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_separator(str[i], charset))
			i++;
	}
	return (count);
}

static int	ft_strlen_sep(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !check_separator(str[i], charset))
		i++;
	return (i);
}

static char	*ft_word(char const *str, char charset)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, charset);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**strings;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strings = (char **)malloc(sizeof(char *)
			* (count_strings(str, c) + 1));
	if (!strings)
		return (NULL);
	while (str[j] != '\0')
	{
		while (str[j] != '\0' && check_separator(str[j], c))
			j++;
		if (str[j] != '\0')
		{
			strings[i] = ft_word(&str[j], c);
			i++;
		}
		while (str[j] && !check_separator(str[j], c))
			j++;
	}
	strings[i] = 0;
	return (strings);
}
