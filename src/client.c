/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:55:41 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/16 13:25:19 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	check_pid(char *pid)
{
	while (*pid)
	{
		if (is_num(*pid))
			pid++;
		else
		{
			ft_printf("Check PID!");
			exit (1);
		}
	}
}

void	send_string(int server_pid, char ch)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((ch & (1 << i)) != 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("ERROR: please check the input arguments!");
		return (1);
	}
	check_pid(argv[1]);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_string(server_pid, argv[2][i]);
		i++;
	}
	send_string(server_pid, '\0');
	return (0);
}
