/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:38:50 by astutz            #+#    #+#             */
/*   Updated: 2022/11/13 10:05:43 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strdup(const char *str)
// {
// 	char	*ptr;
// 	size_t	i;

// 	ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(str) + 1));
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		ptr[i] = str[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }

// on peut utiliser strlcpy ou memcpy

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s, (ft_strlen(s) + 1) * sizeof(char));
	return (ptr);
}
