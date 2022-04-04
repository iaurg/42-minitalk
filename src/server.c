/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:35 by itaureli          #+#    #+#             */
/*   Updated: 2022/04/04 04:37:19 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	bit_to_char(int bit, pid_t client_pid)
{
	static int	holder = 0;
	static int	g_counter = 6;

	holder += bit << g_counter;
	g_counter--;
	if (g_counter < 0)
	{
		if (holder == '\0')
		{
			ft_printf("\n");
			if (kill(client_pid, SIGUSR1) == -1)
				ft_printf("\033[31;1mError: kill failed \033[0m\n");
		}
		ft_printf("%c", holder);
		holder = 0;
		g_counter = 6;
	}
	kill(client_pid, SIGUSR2);
}

static void	handler_action(int sig_number, siginfo_t *act_info, void *context)
{
	(void)context;
	if (!sig_number)
		return ;
	bit_to_char(sig_number == SIGUSR2, act_info->si_pid);
}

int	main(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler_action;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("Server PID: \033[34;1m%d\033[0m\n", getpid());
	while (1)
		pause();
}
