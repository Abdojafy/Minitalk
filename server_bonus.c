/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:50:14 by ajafy             #+#    #+#             */
/*   Updated: 2022/05/14 15:50:17 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include"printf/libftprintf.h"

int	g_glob;

void	ft_printchar_bonus(char *str, int pid)
{
	int	i;
	int	x;
	int	c;

	i = 0;
	x = 128;
	c = 0;
	while (str[i])
	{
		c += (str[i] - 48) * x;
		x /= 2;
		i++;
	}
	ft_printf("%c", c);
	if (c == '\0')
		if (kill (pid, SIGUSR1) == -1)
			exit(0);
}

void	ft_traiter_bonus(int sig, siginfo_t *info, void *content)
{
	static int	pid = 0;
	static char	str[9];

	(void)content;
	if (pid == 0)
		pid = info->si_pid;
	else if (pid != info->si_pid)
	{
		if (str[0] == '1')
			ft_printf("\b");
		g_glob = 0;
		pid = 0;
	}
	if (sig == SIGUSR1)
		str[g_glob++] = '1';
	if (sig == SIGUSR2)
		str[g_glob++] = '0';
	if (g_glob == 8)
	{
		str[g_glob] = '\0';
		ft_printchar_bonus(str, pid);
		g_glob = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_glob = 0;
	ft_printf("PID du serveur : %d\n", getpid());
	sa.sa_sigaction = &ft_traiter_bonus;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
