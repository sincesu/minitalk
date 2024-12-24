/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saincesu <saincesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:30:09 by saincesu          #+#    #+#             */
/*   Updated: 2024/12/24 14:30:10 by saincesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ft_sig(unsigned char a, int pid)
{
	int	c;

	c = 0;
	while (c++ < 8)
	{
		if ((a & 1) == 1)
			kill(pid, SIGUSR1);
		if ((a & 1) == 0)
			kill(pid, SIGUSR2);
		a = a >> 1;
		usleep(700);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
	{
		write(1, "wrong input", 11);
	}
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_sig(av[2][i], pid);
			i++;
		}
	}
}
