/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astutz <astutz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:01:57 by astutz            #+#    #+#             */
/*   Updated: 2022/11/22 17:27:49 by astutz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
// ** Description
// ** Alloue (avec malloc(3)) et
// ** retourne un tableau de chaines de caractères “fraiches”
// ** (toutes terminées par un ’\0’, le tableau également donc)
// ** résultant de la découpe de s selon le caractère c.
// ** Si l’allocation echoue, la fonction retourne NULL.
// ** Exemple : ft_strsplit("*salut*les***etudiants*", ’*’)
// ** renvoie le tableau ["salut", "les", "etudiants"].
// ** Param. #1
// ** La chaine de caractères à découper.
// ** Param. #2
// ** Le caractère selon lequel découper la chaine.
// ** Retour
// ** Le tableau de chaines de caractères “fraiches” résultant de la découpe.
// */

#include "libft.h"

// static unsigned int	ft_is_c(const char c, const char t)
// {
// 	return (c == t);
// }

// static size_t	ft_count(char const *s, char const c)
// {
// 	size_t	count;
// 	size_t	i;

// 	if (s[0] != 0)
// 	{
// 		i = 1;
// 		if (ft_is_c(s[0], c) == 0)
// 			count = 1;
// 		else
// 			count = 0;
// 		while (s[i])
// 		{
// 			if (ft_is_c(s[i - 1], c) == 1
// 				&& ft_is_c(s[i], c) == 0)
// 				count++;
// 			i++;
// 		}
// 		return (count);
// 	}
// 	else
// 		return (0);
// }

// static size_t	ft_wordlen(const char *str, const char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] && !ft_is_c(str[i], c))
// 		i++;
// 	return (i);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**sp;
// 	size_t	i;
// 	size_t	j;
// 	size_t	k;

// 	sp = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
// 	if (!s || !sp)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	while ((k = 0) || s[i])
// 	{
// 		while (s[i] && ft_is_c(s[i], c))
// 			i++;
// 		if (s[i])
// 		{	
// 			sp[j] = (char *)malloc(sizeof(char) * (ft_wordlen(s + i, c) + 1));
// 			if (!sp[j])
// 				return (NULL);
// 			while (s[i] && !ft_is_c(s[i], c))
// 				sp[j][k++] = s[i++];
// 			sp[j++][k] = '\0';
// 		}
// 	}
// 	sp[j] = '\0';
// 	return (sp);
// }

static int	ft_count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	ft_size(char const *s, char c, int i)
{
	int	t;

	t = 0;
	while (s[i] != c && s[i])
	{
		t++;
		i++;
	}
	return (t);
}

static char	**ft_free(char **final, int j)
{
	while (j-- > 0)
		free(final[j]);
	free(final);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		word;
	char	**final;
	int		size;
	int		i;

	i = 0;
	word = ft_count(s, c);
	final = (char **)malloc(sizeof(char *) * (word + 1));
	if (!final)
		return (NULL);
	j = -1;
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size(s, c, i);
		final[j] = ft_substr(s, i, size);
		if (!final[j])
			return (ft_free(final, j));
		i += size;
	}
	final[j] = 0;
	return (final);
}
