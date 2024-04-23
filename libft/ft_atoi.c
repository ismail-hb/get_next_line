/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:34:20 by ishouche          #+#    #+#             */
/*   Updated: 2023/11/17 21:18:27 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	result;
	int			sign;

	sign = 1;
	result = 0;
	while ((str[0] >= 9 && str[0] <= 13) || str[0] == 32)
		str++;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign = -sign;
		str++;
	}
	while (str[0] >= '0' && str[0] <= '9' && str[0] != '\0')
	{
		if (result > (LONG_MAX - (str[0] - '0')) / 10)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		result = result * 10 + (str[0] - 48);
		str++;
	}
	return (sign * result);
}
