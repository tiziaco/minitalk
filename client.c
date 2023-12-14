/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:55:41 by tiacovel          #+#    #+#             */
/*   Updated: 2023/12/14 17:09:32 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

static pid_t server_pid;

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (is_num(str[i])))
	{
		if (is_num(str[i]))
			result = result * 10 + (str[i] - '0');
		else
			return (result *= sign);
		i++;
	}
	return (result *= sign);
}

/* 
	********** Project functions ***********
*/

char binaryToChar(const char *binary) {
    int decimal = 0;
    int base = 1;

    // Iterate over the binary string from right to left
    for (int i = 7; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    // Convert decimal integer to character
    char character = (char)decimal;

    return character;
}

void	printBinary(char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((ch & (1 << i)) != 0) {
			printf("1");
			kill(server_pid, SIGUSR1);
		} else {
			printf("0");
			kill(server_pid, SIGUSR2);
		}
		i--;
		usleep(10000);
	}
}

int main(int argc, char **argv)
{
	// pid_t server_pid;
	int result;

	if (argc <= 1 && argc >3)
	{
		printf("ERROR: please check the input arguments!");
		return (0);
	}

	server_pid = ft_atoi(argv[1]);
	printf("Client: Sending signal to server ID %d.\n", server_pid);
	result = kill(server_pid, SIGUSR1);
	if (result == 0) {
		printf("Client: Signal sent successfully.\n");
	} else {
		perror("Client: Error sending signal");
	}
	printBinary('a');
	printf("\n%c", binaryToChar("01100001"));
	return (0);
}