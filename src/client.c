/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/18 22:59:06 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Params from client:
-The server PID.
-The string that should be sent
- Validate quantity of arguments

[] Validate params are number and string
[] Allow pass special characters like \n
*/

#include "../includes/minitalk.h"

void char_to_bin(unsigned short n, pid_t process_id)
{
	char	bin;
	// int			x;

	while (n > 1)
	{
		bin = (n % 2) + '0';
		ft_printf("N: %d Bin: %c\n", n, bin);
		if (bin == '0')
		{
			kill(process_id, SIGUSR1);
			usleep(1000);
		}
		else if (bin == '1')
		{
			kill(process_id, SIGUSR2);
			usleep(1000);
		}
		n = n / 2;
	}
	//bin[7] = '\0';
	return ;
}

static void	send_binaries(pid_t process_id, char *string_param)
{
	while (*string_param)
	{
		char_to_bin(*string_param - 0, process_id);
		string_param++;
	}
}


int	main(int argc, char *argv[])
{
	int		process_id;
	char	*string_param;

	process_id = ft_atoi(argv[1]);
	if (argc != 3 || process_id <= 1)
	{
		ft_printf("Invalid arguments, use: ./client <process_id> <string>\n");
		return (0);
	}
	string_param = argv[2];
	send_binaries(process_id, string_param);
	return (0);
}
