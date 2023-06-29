/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:19:37 by tlukanie          #+#    #+#             */
/*   Updated: 2023/01/20 13:10:21 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*convert_to_string(char *str, int num, int len)
{
	while (num > 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

static int	count_num_length(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		l = 1;
	while (n != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		num_len;
	int		num;

	num_len = count_num_length(n);
	string = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!string)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	string[num_len--] = '\0';
	if (n == 0)
		string[0] = '0';
	if (n < 0)
	{
		num = n * -1;
		string[0] = '-';
	}
	else
		num = n;
	string = convert_to_string(string, num, num_len);
	return (string);
}
