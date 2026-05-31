/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:03:47 by astutz            #+#    #+#             */
/*   Updated: 2022/11/12 09:56:20 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;

	if (*little == '\0')
		return ((char *)big);
	i = ft_strlen((char *)little);
	while (*big != '\0' && len-- >= i)
	{
		if (*big == *little && ft_memcmp(big, little, i) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}

// char	*ft_strnstr(const char	*big, const char *little, size_t len)
// {
// 	size_t		i;
// 	size_t		i2;
// 	size_t		l_len;

// 	i = 0;
// 	l_len = ft_strlen(little);
// 	if (little[0] == '\0' || big == little)
// 		return ((char *) big);
// 	while (big[i] != '\0' && i < len)
// 	{
// 		i2 = 0;
// 		while (big[i + i2] != '\0' && little[i2] != '\0'
// 			&& big[i + i2] == little[i2] && i + i2 < len)
// 			i2++;
// 		if (i2 == l_len)
// 			return ((char *) big + i);
// 		i++;
// 	}
// 	return (NULL);
// }

// int main()
// {
// 	char s[] = "hello world zoo";
// 	char s1[] = "world";
// 	char *res;
// 	res = ft_strnstr(s, s1, 2);
// 	printf("%s", res);
// }

//len = len de haystack

// ###### Python tutor try ######

// #include "string.h"

// char    *ft_strnstr(const char *str, const char *to_find, size_t len)
// {
//     size_t        position;

//     if (*to_find == '\0')
//         return ((char *)str);
//     position = strlen((char *)to_find);
//     while (*str != '\0' && len-- >= position)
//     {
//         if (*str == *to_find && memcmp(str, to_find, position) == 0)
//             return ((char *)str);
//         str++;
//     }
//     return (NULL);
// }

// int main()
// {
//     char s[] = "hello world zoo";
//     char s1[] = "world";
//     char *res;
//     res = ft_strnstr(s, s1, 5);
//     printf("%s", res);
// }
