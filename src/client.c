/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/16 13:23:20 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Params from client:
-The server PID.
-The string that should be sent
- Validate quantity of arguments
*/

#include "../includes/minitalk.h"
#include <stdio.h>
#include <unistd.h>

char	*binaryString(unsigned short n)
{
	static char bin[8];
	int x;
	x = 6;

	while(x >= 0)
	{
		bin[x] = (n % 2) + '0';
		n = n / 2;
		x--;
	}

	bin[7] = '\0';
	return(bin);
}

static void send_binaries(pid_t processid, int character)
{
	char *binString;

	binString = binaryString(character);
	printf("bin result: %s\n", binString);
	while (*binString)
	{
		if (*binString == '0')
		{
			kill(processid, SIGUSR1);
			usleep(1000);
		}
		else if (*binString == '1')
		{
			kill(processid, SIGUSR2);
			usleep(1000);
		}
		binString++;
	}
}

int main(int argc, char *argv[])
{
	int pid_i;
	char *string_param;
	if (argc != 3)
	{
		printf("Invalid number of arguments\n");
		return 0;
	}
	pid_i = ft_atoi(argv[1]);
	string_param = argv[2];
	// Not allow init process and catcher to all proccess
	if (pid_i <= 1)
	{
		printf("Not allowed PID\n");
		return 0;
	}

	while (*string_param)
	{
		printf("c: %c", *string_param);
		send_binaries(pid_i, (*string_param - 0));
		string_param++;
	}
	return 0;
}

/*
printf("binaryString: %s\n", binaryString(1));
printf("binaryString: %s\n", binaryString(42));
printf("binaryString: %s\n", binaryString(127));

int kill(pid_t pid, int sig );
kill(pid_i, SIGUSR1);
kill(pid_i, SIGUSR2);

On kill success  (at least one signal was sent), zero is returned.
On error, -1 is returned, and errno is set appropriately.
*/
