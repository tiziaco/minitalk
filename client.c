/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:55:41 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/13 16:47:17 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	pid_t server_pid;
	int result;

	server_pid = 38693;
	printf("Client: Sending SIGUSR1 to server.\n");
	result = kill(server_pid, SIGUSR1);
	if (result == 0) {
		printf("Client: Signal sent successfully.\n");
	} else {
		perror("Client: Error sending signal");
	}
	sleep(1);
	return (0);
}