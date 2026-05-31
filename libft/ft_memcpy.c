/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:09:48 by astutz            #+#    #+#             */
/*   Updated: 2022/11/09 20:39:05 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (src == dest || !len)
		return (dest);
	i = 0;
	while (i < len)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int main()
// {
// 	const char src[] = "hello";
// 	char dest[] = "hi";

// 	ft_memcpy(dest, src, sizeof(src));
// 	printf("%s\n", src);
// 	printf("%s\n", dest);
// }

// int main()
// {
// 	const int src[] = {1, 3, 4, 5};
// 	int dest[] = {7, 6, 8, 9};

// 	ft_memcpy(dest, src, 4 * sizeof(int));
// 	printf("%d // %d // %d // %d", dest[0], dest[1], dest[2], dest[3]);
// 	return (0);
// }