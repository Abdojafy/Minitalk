/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:49:58 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/14 15:50:04 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include"printf/libftprintf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	moins;
	int	res;

	i = 0;
	moins = 0;
	res = 0;
	while ((str[i]) && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if ((str[i]) && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			moins++;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (moins % 2 == 0)
		return (res);
	return (-res);
}

void	ft_traite_bonus(int sig)
{
	ft_printf("Votre message a été envoyé avec succès");
	exit(0);
}

void	ft_sendsignal_bonus(int sig, int pid)
{
	if (sig)
	{
		if (kill (pid, SIGUSR1) == -1)
			exit(0);
	}	
	else
		if (kill (pid, SIGUSR2) == -1)
			exit(0);
	usleep(500);
}

int	ft_protect_bonus(int ac, char *av, int pid)
{
	if (ac != 3)
	{
		ft_printf("Veuillez entrer 3 arguments !");
		exit(0);
	}
	pid = ft_atoi(av);
	if (pid <= 0)
	{
		ft_printf("Veuillez entrer un valid pid !");
		exit(0);
	}
	return (pid);
}

int	main(int ac, char *av[])
{
	int		pid;
	int		dec;
	int		i;
	char	c;

	pid = ft_protect_bonus(ac, av[1], pid);
	dec = 8;
	i = 0;
	signal(SIGUSR1, ft_traite_bonus);
	while (av[2][i] != '\0')
	{
		c = av[2][i++];
		while (--dec >= 0)
			ft_sendsignal_bonus(((c >> dec) & 1), pid);
		dec = 8;
	}
	while (--dec >= 0)
		ft_sendsignal_bonus(0, pid);
	while (1)
		pause();
	return (0);
}
