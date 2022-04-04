/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:06 by itaureli          #+#    #+#             */
/*   Updated: 2022/04/04 04:34:32 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_signal(int process_id, int signal)
{
	kill(process_id, signal);
	usleep(10000);
}

static void	char_to_bin(unsigned int n, pid_t process_id)
{
	int		i;
	int		k;

	i = 6;
	while (i >= 0)
	{
		k = n >> i;
		if ((k & 1) > 0)
			send_signal(process_id, SIGUSR2);
		else
			send_signal(process_id, SIGUSR1);
		i--;
	}
	return ;
}

static void	send_binaries(pid_t process_id, char *string_param)
{
	while (*string_param)
	{
		char_to_bin(*string_param, process_id);
		string_param++;
	}
	char_to_bin(*string_param, process_id);
}

static void	handler_action_client(int sig, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (sig == SIGUSR1)
	{
		ft_printf("\033[32;1mMessage was successfully sent\n\n\033[0m");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	int					process_id;
	char				*string_param;
	struct sigaction	action;

	if (argc != 3)
	{
		ft_printf("\033[31;1mInvalid arguments, use: \033[0m\n");
		ft_printf("\033[31;1m./client <process_id> <string> \033[0m\n");
		exit(0);
	}
	process_id = ft_atoi(argv[1]);
	if (process_id <= 0)
	{
		ft_printf("\033[31;1mInvalid process id\033[0m\n");
		exit(0);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler_action_client;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	string_param = argv[2];
	send_binaries(process_id, string_param);
	while (1)
		pause();
}
