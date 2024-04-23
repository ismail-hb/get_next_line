/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:05:02 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/15 07:53:19 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char const *set, char c)
{
	size_t		i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	makestrimsmall(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	i = ft_strlen((char *)s1);
	while (checkset(set, s1[j]) == 1)
		j++;
	if (!s1[j])
		return (-1);
	while (checkset(set, s1[--i]) == 1)
		k++;
	return (j + k);
}

static char	*themalloc(int size, char const *s1, char const *set)
{
	char	*finalstr;
	size_t	i;
	size_t	k;
	size_t	j;

	j = 0;
	i = 0;
	finalstr = malloc(sizeof(char) * (ft_strlen((char *)s1) - size + 1));
	if (!finalstr)
		return (NULL);
	while (checkset(set, s1[i]) == 1)
		i++;
	k = size - i;
	while (i < (ft_strlen((char *)s1) - k))
	{
		finalstr[j] = s1[i];
		i++;
		j++;
	}
	finalstr[j] = '\0';
	return (finalstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*finalstr;
	long int	j;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	j = makestrimsmall(s1, set);
	if (j == -1)
		return (ft_strdup(""));
	finalstr = themalloc(j, s1, set);
	if (!finalstr)
		return (NULL);
	return (finalstr);
}
