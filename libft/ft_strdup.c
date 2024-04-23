/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:10:07 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/15 07:53:33 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*duplicata;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen((char *)str);
	duplicata = malloc(sizeof(char) * size + 1);
	if (!duplicata)
		return (NULL);
	while (str[i])
	{
		duplicata[i] = str[i];
		i++;
	}
	duplicata[i] = '\0';
	return (duplicata);
}
