/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:11:03 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/14 16:48:44 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void	signal_handler(int signal)
{
	char	buffer[8];
	int		i;

	i = 0;
	if (signal == SIGUSR1)
	{
		buffer[i] = '0';
	}
	else if (signal == SIGUSR2)
	{
		buffer[i] = '1';
	}
	if (i == 7)
	{
		i = 0;
		printf("%s", buffer);
	}
	i++;
}

int main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	printf("Server: Waiting for signals...\n");
	while (1) 
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}
	return (0);
}