/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:44:28 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/17 16:26:35 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_minimum(long int nbr, char *str, int i)
{
	if (nbr < 0)
	{
		str[i] = '-';
		nbr = -nbr;
		i++;
	}
	if (nbr >= 0 && nbr <= 9)
	{
		str[i] = nbr + 48;
		i++;
	}
	if (nbr > 9)
	{
		i = ft_minimum(nbr / 10, str, i);
		i = ft_minimum(nbr % 10, str, i);
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	i;
	long int	j;

	j = 0;
	i = n;
	if (i < 0)
	{
		i = -i;
		j++;
	}
	while (i > 9)
	{
		i /= 10;
		j++;
	}
	str = malloc(sizeof(char) * j + 2);
	if (!str)
		return (0);
	i = 0;
	i = ft_minimum((long)n, str, i);
	str[i] = '\0';
	return (str);
}
