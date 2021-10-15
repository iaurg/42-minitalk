/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/15 06:27:55 by itaureli         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	int pid_i;
	char *binString;

	if (argc != 3)
	{
		printf("Invalid number of arguments\n");
		return 0;
	}

	pid_i = ft_atoi(argv[1]);
	printf("argv: %s\n", argv[1]);
	printf("pid_i: %d\n", pid_i);

	// Not allow init process and catcher to all proccess
	if (pid_i <= 1)
	{
		printf("Not allowed PID\n");
		return 0;
	}

	binString = binaryString(42);
	while(*binString)
	{
		if (*binString == '1')
		{
			printf("1");
			kill(pid_i, SIGUSR1);
		}
		else
		{
			printf("0");
			kill(pid_i, SIGUSR2);
		}
		binString++;
	}
	printf("binaryString: %s\n", binaryString(1));
	printf("binaryString: %s\n", binaryString(42));
	printf("binaryString: %s\n", binaryString(127));
	//  int kill(pid_t pid, int sig );
	//kill(pid_i, SIGUSR1);
	//kill(pid_i, SIGUSR2);

	/*
	On kill success  (at least one signal was sent), zero is returned.
	On error, -1 is returned, and errno is set appropriately.
	*/
	return 0;
}
