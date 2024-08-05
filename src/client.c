/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:08:11 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/08/05 20:51:15 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void send_signals(int pid, char *str) {
    int i, j;

    i = 0;
    while (str[i]) {
        j = 7;
        while (j >= 0) {
            if (((str[i] >> j) & 1) == 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(300);  // Incrementado para mayor estabilidad
            j--;
        }
        i++;
    }
    // Send end of message signal
    j = 0;
    while (j < 8) {
        kill(pid, SIGUSR1);
        usleep(300);  // Incrementado para mayor estabilidad
        j++;
    }
}

int main(int argc, char **argv) {
    char *message;
    int pid;

    if (argc == 3) {
        pid = ft_atoi(argv[1]);
        if (pid <= 0) {
            ft_printf("[ERROR]. Wrong PID\n");
            return(0);
        }
        message = argv[2];
        if (message[0] == 0) {
            ft_printf("[ERROR]. No message\n");
            return(0);
        }
        send_signals(pid, message);
    } else {
        ft_printf("[ERROR]. Wrong arguments\n");
        ft_printf("Usage: ./client <PID> <MESSAGE>\n");
    }
    return(0);
}

