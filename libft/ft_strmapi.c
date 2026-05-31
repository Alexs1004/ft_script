/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:11:34 by astutz            #+#    #+#             */
/*   Updated: 2022/11/08 14:02:41 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Appliquer la chaîne de caractères de la fonction 
'f' à chaque caractère de l'échantillon. 
 * de caractères 's' pour créer une nouvelle 
chaîne de caractères (avec malloc(3)) 
 * résultant en des applications successives de 'f'.*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newchain;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	newchain = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!newchain)
		return (NULL);
	while (s[i])
	{
		newchain[i] = f(i, s[i]);
		i++;
	}
	newchain[i] = '\0';
	return (newchain);
}
