/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:48:09 by astutz            #+#    #+#             */
/*   Updated: 2022/11/12 17:56:17 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

// return (&dstsize[i])

	// unsigned int	i;
	// unsigned int	j;
	// unsigned int	dlen;
	// unsigned int	slen;

	// i = 0;
	// j = 0;
	// while (dest[j] != '\0')
	// {
	// 	j++;
	// }
	// dlen = j;
	// slen = ft_strlen(src);
	// if (size == 0 || size <= dlen)
	// 	return (slen + size);
	// while (src [i] != '\0' && i < size - dlen - 1)
	// {
	// 	dest[j] = src[i];
	// 	i++;
	// 	j++;
	// }
	// dest[j] = '\0';
	// return (dlen + slen);

// int main()
// {
// 	char src[] = "hello";
// 	char dest[] = "you";
// 	size_t num;

// 	num  = ft_strlcat(dest, src, ft_strlen(dest));
// 	printf("%ld", num);
// }