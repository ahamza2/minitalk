/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:25:28 by haarab            #+#    #+#             */
/*   Updated: 2023/02/08 13:18:30 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	niga(int nbr, int pid)
{
	int	k;

	if (nbr == 1)
	{
		k = kill(pid, SIGUSR1);
		if (k == -1)
			exit(-1);
	}
	else if (nbr == 0)
	{
		k = kill(pid, SIGUSR2);
		if (k == -1)
			exit(-1);
	}
}

void	send_signal(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] & (1 << j))
			{
				niga(1, pid);
			}
			else
			{
				niga(0, pid);
			}
			usleep(500);
			j--;
		}
		i++;
	}
}

int	check(char *str)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			b++;
			break ;
		}
		i++;
	}
	if (b == 1)
	{
		return (0);
	}
	else
	{
		return (1);
	}	
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		if (check(av[1]))
		{
			pid = ft_atoi(av[1]);
			if (pid == 0)
			{
				return (0);
			}
			send_signal(pid, av[2]);
		}
	}
	return (0);
}
