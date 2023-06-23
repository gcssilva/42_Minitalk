/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:28:22 by gsilva            #+#    #+#             */
/*   Updated: 2023/06/23 17:23:58 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(char *str);
void	ft_putchar(int c);
int		ft_putstr(char *str);
void	ft_putnbr(int nbr);

int	ft_atoi(char *str)
{
	long int	s;
	long int	nbr;

	s = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -s;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nbr = nbr * 10 + (*str++ - 48);
		if (nbr > 2147483648 || (nbr == 2147483648 && s == 1))
			return (0);
	}
	return (nbr * s);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
	return (i);
}

void	ft_putnbr(int nbr)
{
	if (nbr == INT_MIN)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putstr("-");
	}
	if (nbr < 10)
	{
		ft_putchar(nbr + 48);
		return ;
	}
	ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}
