/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:08:11 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/08/06 17:39:11 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void send_signal(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			i--;
		}
	}
}

int main(int argc, char **argv)
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("[Error]: wrong arguments\n");
        ft_printf("[Usage]: ./client <PID> <MESSAGE>\n");
		return (0);
	}
	else if (pid <= 0)
	{
		ft_printf("[Error]: Wrong PID!\n");
		return (0);
	}
	send_signal(pid, argv[2]);
}