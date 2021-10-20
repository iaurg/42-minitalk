/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:35 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/20 06:59:53 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	bit_to_char(int bit)
{
	static int	holder = 0;
	static int	g_counter = 6;

	holder += bit << g_counter;
	g_counter--;
	if (g_counter < 0)
	{
		ft_printf("%c", holder);
		holder = 0;
		g_counter = 6;
	}
}

static void	handler_zero(int sig)
{
	if (!sig)
		return ;
	bit_to_char(0);
}

static void	handler_one(int sig)
{
	if (!sig)
		return ;
	bit_to_char(1);
}

int	main(void)
{
	struct sigaction	action_zero;
	struct sigaction	action_one;

	ft_printf("Server PID: %d\n", getpid());
	action_zero.sa_handler = &handler_zero;
	action_one.sa_handler = &handler_one;
	sigaction(SIGUSR1, &action_zero, NULL);
	sigaction(SIGUSR2, &action_one, NULL);
	while (1)
		pause();
	return (0);
}
