/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppinedo- <ppinedo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:09:40 by ppinedo-          #+#    #+#             */
/*   Updated: 2024/08/05 20:49:57 by ppinedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void handler(int x) {
    static unsigned char bits = 0;
    static int bit_count = 0;

    if (x == SIGUSR2) {
        bits = bits << 1;  // Shift bit left
    } else if (x == SIGUSR1) {
        bits = (bits << 1) | 1;  // Shift bit left and add 1
    }
    bit_count++;

    if (bit_count == 8) {  // After receiving 8 bits (1 byte)
        if (bits == 0) {  // End of message
            ft_printf("\n");
        } else {
            ft_printf("%c", bits);
        }
        bit_count = 0;
        bits = 0;
    }
}

int main(void) {
    struct sigaction act;

    ft_printf("Welcome to Pedro's server.\n");
    ft_printf("My PID is %d\n", getpid());
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGUSR1, &act, NULL);
    sigaction(SIGUSR2, &act, NULL);
    while (1)
        pause();
}
