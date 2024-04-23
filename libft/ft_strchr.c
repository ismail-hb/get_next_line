/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:04:15 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/15 07:53:34 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while ((unsigned char)c != s[i] && s[i] != '\0')
		i++;
	if ((unsigned char)c == s[i])
		return (&((char *)s)[i]);
	return (0);
}
