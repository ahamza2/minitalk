/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:28:12 by haarab            #+#    #+#             */
/*   Updated: 2023/02/08 15:50:55 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	send_signal(int pid, char *str);

int		ft_atoi(const char *str);

int		ft_recursive_power(int nb, int power);

void	handl_message(int sig, siginfo_t *i, void *j);

void	ft_putchar(char c);

void	ft_putstr(char *s);

void	ft_putnbr(int n);

void	counvert(int *nb);

void	niga(int nbr, int pid);

#endif