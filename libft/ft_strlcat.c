/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:34:09 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/15 07:53:29 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;

	i = 0;
	dlen = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[dlen] && dlen < size)
	{
		dlen++;
	}
	if (size > 0)
	{
		while (src[i] && dlen + i < size - 1)
		{
			dest[dlen + i] = src[i];
			i++;
		}
		if (dlen < size)
			dest[dlen + i] = 0;
	}
	i = 0;
	while (src[i])
		i++;
	return (dlen + i);
}
