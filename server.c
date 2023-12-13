/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:11:03 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/13 16:48:39 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

volatile sig_atomic_t signal_received = 0;

void signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		printf("Signal 1 recived/n");
		signal_received = 1;
	}
	else if (signal == SIGUSR2)
	{
		printf("Signal 2 recived/n");
		signal_received = 1;
	}
}

int main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	//signal(SIGUSR2, signal_handler);
	printf("Server: Waiting for signals...\n");
	while (1) 
	{
		pause();
	}
	return (0);
}