/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:46:08 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/17 21:30:52 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*str;

	if (n == 0 || size == 0)
		return (malloc(0));
	if (n > __SIZE_MAX__ / size)
		return (NULL);
	str = malloc(size * n);
	if (!str)
		return (0);
	ft_bzero(str, n * size);
	return (str);
}
