/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:05:34 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/15 07:53:30 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*finalstr;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	finalstr = malloc(sizeof(char) * i);
	if (!finalstr)
		return (NULL);
	finalstr[0] = '\0';
	ft_strlcat(finalstr, s1, i);
	ft_strlcat(finalstr, s2, i);
	return (finalstr);
}
