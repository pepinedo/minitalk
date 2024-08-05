/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:08:11 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/08/05 13:08:12 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signals(int pid, char *str)
{
	int i;
	int	j;

    i = 0;
	while (str[i])
	{
        j = -1;
        while (++j < 8)
        {
            if (((unsigned char)(str[i] >> (7 - j)) & 1) == 0)
                kill(pid, SIGUSR1);
            else if (((unsigned char)(str[i] >> (7 - j)) & 1) == 1)
                kill(pid, SIGUSR2);
            usleep(50);
        }
    i++;
	}
    j = 0;
    while(j++ < 8)
    {
        kill(pid, SIGUSR1);
        usleep(50);
    }
}

int main(int argc, char **argv)
{
    char    *message;
    int     pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
        if (!pid)
        {
            ft_printf("[ERROR]. Wrong pid\n");
            return(0);
        }
        message = argv[2];
        if (message[0] == 0)
            return(ft_printf("[ERROR]. No message\n"), 0);
        send_signals(pid, message);
    }
    else
    {
        ft_printf("[ERROR]. Wrong arguments\n");
        ft_printf("This is the format: ./client <PID> <MESSAGE>\n");
    }
    return(0);
}