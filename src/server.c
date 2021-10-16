/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:35 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/16 11:38:46 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Starts and show his PID
*/

#include "../includes/minitalk.h"
#include <stdio.h>
#include <unistd.h>

int counter = 6;

// a = 110000 = 48
/*
holder += 1 << 6;
holder += 0 << 5;
holder += 0 << 4;
holder += 0 << 3;
holder += 0 << 2;
holder += 0 << 1;
holder += 1 << 0;
*/
static void bit_to_char(int bit)
{
	static int holder = 0;
	holder += bit << counter;
	counter--;
	if (counter < 0)
	{
		write(STDOUT_FILENO, &holder, 2);
		holder = 0;
		counter = 6;
		return;
	}
	return;
}

static void handler_zero(int sig)
{
	bit_to_char(0);
	if(!sig)
		return;
}

static void handler_one(int sig)
{
	bit_to_char(1);
	if(!sig)
		return;
}

int main()
{
	struct sigaction	action_zero;
	struct sigaction	action_one;

	printf("Server PID: %d\n", getpid());
	action_zero.sa_handler = &handler_zero;
	action_one.sa_handler = &handler_one;

	sigaction(SIGUSR1, &action_zero, NULL);
	sigaction(SIGUSR2, &action_one, NULL);
	while (1)
	{
		pause();
	}
	return 0;
}
