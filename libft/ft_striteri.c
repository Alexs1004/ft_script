/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:24:46 by astutz            #+#    #+#             */
/*   Updated: 2022/11/19 07:58:14 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre en précisant son index en pre- mier argument.
** Chaque caractère est passé par adresse à la fonction f afin de
** pouvoir être modifié si nécéssaire.
** Param. #1
** La chaine de caractères sur laquelle itérer.
** Param. #2
** La fonction à appeler sur chaque caractère de s et son index.
** Retour
** Rien.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			(*f)(i, s + i);
			i++;
		}
	}
}
