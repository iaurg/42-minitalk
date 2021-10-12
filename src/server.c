/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:35 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/12 19:12:10 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Starts and show his PID
*/

#include "../includes/minitalk.h"
#include <stdio.h>
#include <unistd.h>

void handler(int num)
{
	write(STDOUT_FILENO, "HI!\n", 4);
	printf("NUM:%d\n", num);
	if(!num) return;
}

int main()
{
	struct sigaction	action;

	action.sa_handler = &handler;

	sigaction(SIGUSR1, &action, NULL);
	while(1)
	{
		printf("My PID: %d\n", getpid());
		sleep(1);
	}
	return 0;
}
