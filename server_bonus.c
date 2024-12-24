/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:32:03 by saincesu          #+#    #+#             */
/*   Updated: 2024/12/24 14:32:04 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int pid)
{
	if (pid > 9)
	{
		ft_putnbr(pid / 10);
		ft_putnbr(pid % 10);
	}
	else
	{
		pid += 48;
		write(1, &pid, 1);
	}
}

void	ft_handle(int sig)
{
	static int	a = 0;
	static int	b = 1;

	if (sig == SIGUSR1)
		a = a + b;
	b = b * 2;
	if (b > 128)
	{
		write(1, &a, 1);
		b = 1;
		a = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
	{
		pause();
	}
}
