/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/10 19:47:32 by itaureli         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
	if (argc < 3)
		return 0;
	printf("argv: %s", argv[1]);
	//  int kill(pid_t pid, int sig );
	kill(ft_atoi(argv[1]), 10);
	return 0;
}
