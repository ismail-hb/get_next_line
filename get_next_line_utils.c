/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:14:36 by ishouche          #+#    #+#             */
/*   Updated: 2023/12/07 03:24:26 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
	return (i);
}

void	ft_strcpy2(char *src, char *dest, ssize_t i)
{
	ssize_t	j;

	j = 0;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
}

char	*ft_strcpy(char *src, char *dest, ssize_t i)
{
	ssize_t	j;

	j = 0;
	while (j < i && src[j != '\0'])
	{
		dest[j] = src[j];
		j++;
	}
	j = 0;
	while (src[i] != '\0')
	{
		src[j] = src[i];
		j++;
		i++;
	}
	src[j] = '\0';
	return (dest);
}
