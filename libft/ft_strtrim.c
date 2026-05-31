/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:17:42 by astutz            #+#    #+#             */
/*   Updated: 2022/11/14 18:51:22 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Réserve de la mémoire (avec malloc(3)) et 
renvoie la chaîne de caractères qui est 
 * une copie de 's1', sans les caractères 
indiqués par 'set' au début et 'set' à la fin.
 * à la fin de la chaîne. */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newchain;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
		end--;
	newchain = ft_substr((char *)s1, 0, end + 1);
	return (newchain);
}
