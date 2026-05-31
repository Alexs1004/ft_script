/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:43:26 by astutz            #+#    #+#             */
/*   Updated: 2022/11/12 09:15:54 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
// 	{
// 		if (s1[i] > s2[i])
// 		{
// 			return (1);
// 		}
// 		else if (s1[i] < s2[i])
// 		{
// 			return (-1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	while (n--)
// 	{
// 		if (*s1 != *s2)
// 			return ((unsigned char)*s1 - (unsigned char)*s2);
// 		if (*s1 == '\0' || *s2 == '\0')
// 			return (0);
// 		s1++;
// 		s2++;
// 	}
// 	return (0);
// }
