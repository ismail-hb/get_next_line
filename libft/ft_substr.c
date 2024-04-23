/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:49:43 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/15 07:53:17 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
		return (ft_calloc(1, 1));
	if (j - start <= len)
		j -= start;
	else
		j = len;
	newstr = ft_calloc((j + 1), sizeof(char));
	if (!newstr)
		return (NULL);
	while (i < j)
	{
		newstr[i] = s[start + i];
		i++;
	}
	return (newstr);
}
