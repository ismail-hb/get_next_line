/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:10:44 by ishouche          #+#    #+#             */
/*   Updated: 2024/01/23 18:33:22 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharF(char c, int *j)
{
	write(1, &c, 1);
	(*j)++;
}

void	ft_putstrF(char *str, int *j)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstrF("(null)", j);
		return ;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		(*j)++;
	}
}

void	putnbr_baseF(unsigned long int nbr, char *base, int *j)
{
	unsigned long int	base_len;
	int					i;

	base_len = 0;
	i = -1;
	while (base[++i])
		base_len++;
	if (nbr >= 0 && nbr < base_len)
	{
		write(1, &base[nbr], 1);
		(*j)++;
	}
	if (nbr >= base_len)
	{
		putnbr_baseF(nbr / base_len, base, j);
		putnbr_baseF(nbr % base_len, base, j);
	}
}

void	ft_putaddressF(void *nb, int *j)
{
	if (nb == 0)
	{
		ft_putstrF("(nil)", j);
		return ;
	}
	write(1, "0x", 2);
	*j += 2;
	putnbr_baseF((unsigned long int) nb, "0123456789abcdef", j);
}

void	ft_putnbrF(int nb, int *j)
{
	if (nb == INT_MIN)
	{
		ft_putstrF("-2", j);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putcharF('-', j);
		nb = -nb;
	}
	putnbr_baseF((int) nb, "0123456789", j);
}
