/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 08:50:17 by astutz            #+#    #+#             */
/*   Updated: 2022/11/09 20:47:19 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src == dest || !len)
		return (dest);
	if (dest < src)
	{
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dest)[len - 1]
				= ((const unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dest);
}

// int main()
// {
// 	char dest[] = "deja bien fait";
// 	char src[] = "bien";

// 	ft_memmove(dest, src, sizeof(src));
// 	printf("%s", dest);
// }
//MAIN
/* char dest[2] = "he";
// char src[3] = "you";

// char dest[] = "";
char src[] = "";*/

//ELSE
/*{
// 	i = 0;
// 	while (len > 0)
// 	{
// 		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
// 		i++;
// 	}
}*/