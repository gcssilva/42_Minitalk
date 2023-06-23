/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:52:07 by gsilva            #+#    #+#             */
/*   Updated: 2023/06/23 18:29:31 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, int c)
{
	int	bin[8];
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & 1) == 0)
			bin[i] = 0;
		else
			bin[i] = 1;
		c = c >> 1;
		i--;
	}
	while (++i < 8)
	{
		if (bin[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_putstr("Invalid arguments\n"));
	pid = ft_atoi(argv[1]);
	while (*argv[2])
		send_sig(pid, *argv[2]++);
	send_sig(pid, '\n');
	return (0);
}
