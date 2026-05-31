/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:42:35 by astutz            #+#    #+#             */
/*   Updated: 2022/10/30 15:20:34 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main()
// {
// 	// char s[] = "hello";
// 	printf("hi");
// }

	// size_t i;

	// i = 0;
	// while (i < len)
	// {
	// 	((unsigned char *)s)[i] = '\0';
	// 	i++;
	// }