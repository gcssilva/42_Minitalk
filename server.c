/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:52:04 by gsilva            #+#    #+#             */
/*   Updated: 2023/06/28 16:21:40 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	int			bit;
	static int	chr;
	static int	bin;

	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	chr = (chr << 1) + bit;
	bin++;
	if (bin == 8)
	{
		ft_putchar(chr);
		chr = 0;
		bin = 0;
	}
}

int	main(void)
{
	struct sigaction	sig_act;

	sig_act.sa_handler = &handler;
	sig_act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig_act, 0);
	sigaction(SIGUSR2, &sig_act, 0);
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
