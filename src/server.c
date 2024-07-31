#include "../includes/minitalk.h"

void	print_bits(int x)
{
	static int	bit = 7;
	static int	set = 0;

	set += (x << bit);
	if (bit == 0)
	{
		ft_printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	handler(int a)
{
	if (a == SIGUSR1)
	{
		print_bits(1);
	}
	else if (a == SIGUSR2)
	{
		print_bits(0);
	}
}

int main(void)
{
	struct sigaction	signal_received;

	ft_printf("Welcome to Pedro's server.\n");
	ft_printf("My PID is %d\n", getpid());
	sigaction(SIGUSR1, (int)handler, NULL);
	sigaction(SIGUSR2, (int)handler, NULL);
	while (1)
		pause();
}