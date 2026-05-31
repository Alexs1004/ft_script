/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:52:22 by astutz            #+#    #+#             */
/*   Updated: 2022/11/12 07:52:31 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Scans the initial n bytes of the memory area pointed to by s for the first 
 * instance of c.  Both c and the bytes of the memory area pointed to by s are 
 * interpreted as unsigned char. */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	unsigned char	*ptrs;
// 	size_t			i;

// 	ptrs = (unsigned char *)s;
// 	i = 0;
// 	while (n--)
// 	{
// 		if (ptrs[i] == (unsigned char)c)
// 			return (ptrs + i);
// 		i++;
// 	}
// 	return (NULL);
// }
// #include "libft.h"
// #include "stdio.h"

// void	*ft_memchr(const void *s, int c, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		if (((unsigned char *)s)[i] == ((unsigned char)c))
// 			return ((void *)(s + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	size_t		i;

// 	idx = 0;
// 	while (idx < n)
// 	{
// 		if (*((unsigned char *)s + idx) == (unsigned char)c)
// 			return ((void *)s + idx);
// 		idx++;
// 	}
// 	return (NULL);
// }

// int main()
// {
// 	char s[] = "hello world";

// 	printf("%s", ft_memchr(s, 'l', sizeof(s)));
// }