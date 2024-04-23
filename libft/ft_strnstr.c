/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:12:43 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/15 07:53:23 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*checknull(const char *s1, const char *s2, size_t len)
{
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	else if (len == 0)
		return (NULL);
	return (NULL);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;

	i = 0;
	if (ft_strlen(s2) == 0 || len == 0)
		return (checknull(s1, s2, len));
	length = len;
	if (ft_strlen(s1) < len)
		len = ft_strlen(s1);
	while (i < len)
	{
		j = 0;
		if (s1[i] == s2[0])
		{
			while (s1[i + j] == s2[j] && j < ft_strlen(s2) && i + j < length)
				j++;
			if (j == ft_strlen(s2))
				return ((char *)s1 + i);
			i++;
		}
		else
			i++;
	}
	return (NULL);
}
