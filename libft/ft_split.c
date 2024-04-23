/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 08:07:47 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/20 21:21:54 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *str, char c)
{
	size_t		i;
	size_t		words;

	words = 0;
	i = 0;
	if (str[0] != c && str[0] != '\0')
	{
		words++;
	}
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
		{
			words++;
		}
		i++;
	}
	return (words);
}

static int	ft_charlen(char const *str, char c, size_t *y)
{
	int	i;

	i = 0;
	while (str[y[0]] != c && str[y[0]] != '\0')
	{
		y[0]++;
		i++;
	}
	return (i);
}

static char	*duplicate(char const *src, char *dest, char c, size_t *y)
{
	size_t	i;
	size_t	j;
	size_t	v;

	v = 0;
	while (src[y[0]] == c)
		y[0]++;
	j = y[0];
	i = ft_charlen(src, c, y);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	while (v < i)
	{
		dest[v] = src[j];
		j++;
		v++;
	}
	dest[v] = '\0';
	return (dest);
}

static void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	words = countwords(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		tab[i] = duplicate(s, tab[i], c, &y);
		if (!tab[i])
			return (ft_free(tab), NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
