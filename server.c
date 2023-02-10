/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:28:21 by haarab            #+#    #+#             */
/*   Updated: 2023/02/08 15:18:38 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handl_message(int sig, siginfo_t *info, void *j)
{
	static int	signal;
	static int	c;
	static int	str[8];

	(void)j;
	if (signal != info->si_pid)
	{
		c = 0;
	}
	if (sig == 30)
	{
		str[c] = 1;
		c++;
	}
	else if (sig == 31)
	{
		str[c] = 0;
		c++;
	}
	if (c == 8)
	{
		counvert (str);
		c = 0;
	}
	signal = info->si_pid;
}

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	if (power > 1)
	{
		return (nb * ft_recursive_power(nb, power -1));
	}
	return (result);
}

void	counvert(int *nb)
{
	int		i;
	int		b;
	char	result;

	i = 0;
	result = 0;
	b = 7;
	while (i <= 7)
	{
		result += nb[b] * ft_recursive_power(2, i);
		i++;
		b--;
	}
	ft_putchar(result);
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sig.sa_sigaction = handl_message;
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
	}
}
