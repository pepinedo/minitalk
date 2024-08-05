/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:09:40 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/08/05 16:14:28 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int g_call;

void	print_bits(int x)
{
	static unsigned char	bits;
	int i;

	if (!bits)
		bits = 0;
	if (x == SIGUSR2)
		bits = bits << 1;
	if (x == SIGUSR1)
	{
		bits == bits << 1;
		bits |= 1;
	}
	if ()
	g_call++;
}

void	handler(int a)
{
	if (a == SIGUSR1)
	{
		ft_printf("Soy el 1\n");
		// print_bits(1);
	}
	else if (a == SIGUSR2)
	{
		ft_printf("Soy el 1\n");
		// print_bits(0);
	}
}

int	main(void)
{
	struct sigaction act;

	ft_printf("Welcome to Pedro's server.\n");
	ft_printf("My PID is %d\n", getpid());
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	g_call = 0;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
