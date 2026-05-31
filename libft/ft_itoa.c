/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:27:11 by astutz            #+#    #+#             */
/*   Updated: 2022/11/15 14:11:38 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long nb)
{
	int	l;

	l = 0;
	if (nb == 0)
		l = 1;
	else if (nb < 0)
	{
		nb = -nb;
		l++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*string;
	int		i;

	nb = n;
	i = len(nb);
	string = (char *)malloc (sizeof(char) * (len(nb) + 1));
	if (!string)
		return (NULL);
	string[i--] = '\0';
	if (nb == 0)
		string[0] = '0';
	if (nb < 0)
	{
		string[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		string[i--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (string);
}

// #include "libft.h"

// char		*ft_strrev(char *str)
// {
// 	int				idx;
// 	int				size;
// 	char			tmp;

// 	size = ft_strlen(str);
// 	idx = 0;
// 	while (idx < (size / 2))
// 	{
// 		tmp = str[idx];
// 		str[idx] = str[size - idx - 1];
// 		str[size - idx - 1] = tmp;
// 		idx++;
// 	}
// 	return (str);
// }

// int			ft_intlen(int n)
// {
// 	int				idx;
// 	long long		tmp;

// 	tmp = n;
// 	idx = 1;
// 	if (tmp < 0)
// 	{
// 		tmp = tmp * -1;
// 		idx++;
// 	}
// 	while (tmp >= 10)
// 	{
// 		tmp = tmp / 10;
// 		idx++;
// 	}
// 	return (idx);
// }

// char		*ft_itoa(int n)
// {
// 	int				idx;
// 	int				is_negative;
// 	unsigned int	positive_n;
// 	char			*value;

// 	if (n == 0)
// 		return (ft_strdup("0"));
// 	if (!(value = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1))))
// 		return (NULL);
// 	ft_memset(value, '\0', (ft_intlen(n) + 1));
// 	is_negative = n < 0 ? 1 : 0;
// 	positive_n = n < 0 ? -n : n;
// 	idx = 0;
// 	while (positive_n != 0)
// 	{
// 		value[idx++] = (positive_n % 10) + '0';
// 		positive_n = positive_n / 10;
// 	}
// 	if (is_negative)
// 		value[idx++] = '-';
// 	return (ft_strrev(value));
// }