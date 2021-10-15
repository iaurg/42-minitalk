/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:35 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/15 06:25:09 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Starts and show his PID
*/

#include "../includes/minitalk.h"
#include <stdio.h>
#include <unistd.h>

void handler(int sig)
{
	write(STDOUT_FILENO, "1\n", 2);
	if(!sig)
		return;
}

void handler2(int sig)
{
	write(STDOUT_FILENO, "0\n", 2);
	if(!sig)
		return;
}

int main()
{
	struct sigaction	action;
	struct sigaction	action2;

	action.sa_handler = &handler;
	action2.sa_handler = &handler2;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action2, NULL);
	printf("My PID: %d\n", getpid());


	while(1)
	{
		printf("My PID: %d\n", getpid());
		sleep(1);
	}

	return 0;
}
