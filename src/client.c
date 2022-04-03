/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:06 by itaureli          #+#    #+#             */
/*   Updated: 2022/04/03 13:13:10 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_signal(int process_id, int signal)
{
	kill(process_id, signal);
	usleep(9000);
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

static void	handler_action_client(int sig_number)
{
	if (sig_number == SIGUSR2)
		return ;
	ft_printf("End communication");
	exit(0);
}

int	main(int argc, char *argv[])
{
	int					process_id;
	char				*string_param;
	struct sigaction	action;

	if (argc != 3)
	{
		ft_printf("Invalid arguments, use: ./client <process_id> <string>\n");
		return (0);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_handler = handler_action_client;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	string_param = argv[2];
	process_id = ft_atoi(argv[1]);
	send_binaries(process_id, string_param);
	return (0);
}
