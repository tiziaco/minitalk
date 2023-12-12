/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:11:03 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/12 16:57:14 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
} 

int main(int argc, char **argv)
{
	pid_t	pid;

    pid = getpid();
	signal(SIGQUIT, handle_sigint); 
	while (1) 
	{
		printf("hello world\n");
		sleep(1); 
	}
	return (0);
}