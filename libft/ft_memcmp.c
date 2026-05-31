/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:30:18 by astutz            #+#    #+#             */
/*   Updated: 2022/11/12 08:14:49 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s1)[i] != ((const unsigned char *)s2)[i])
			return (((const unsigned char *)s1)[i]
				- ((const unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// int	ft_memcmp(const void *s1, const void *s2, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		if (((const unsigned char *)s1)[i] != ((const unsigned char *)s2)[i])
// 			return (((const unsigned char *)s1)[i]
// 				- ((const unsigned char *)s2)[i]);
// 		i++;
// 	}
// 	return (0);
// }

// int main()
// {
// 	const unsigned char s1[] = "a";
// 	const unsigned char s2[] = "";

// 	int res = ft_memcmp(s1, s2, sizeof(s1));
// 	printf("%d", res);
// }