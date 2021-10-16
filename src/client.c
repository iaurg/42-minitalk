/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:35:06 by itaureli          #+#    #+#             */
/*   Updated: 2021/10/16 16:12:44 by itaureli         ###   ########.fr       */
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

char	*char_to_bin(unsigned short n)
{
	static char	bin[8];
	int			x;

	x = 6;
	while (x >= 0)
	{
		bin[x] = (n % 2) + '0';
		n = n / 2;
		x--;
	}
	bin[7] = '\0';
	return (bin);
}

static void	send_binaries(pid_t process_id, int character)
{
	char	*bin_string;

	bin_string = char_to_bin(character);
	while (*bin_string)
	{
		if (*bin_string == '0')
		{
			kill(process_id, SIGUSR1);
			usleep(1000);
		}
		else if (*bin_string == '1')
		{
			kill(process_id, SIGUSR2);
			usleep(1000);
		}
		bin_string++;
	}
}

static void	map_string(char *string_param, pid_t process_id)
{
	while (*string_param)
	{
		send_binaries(process_id, (*string_param - 0));
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
		ft_printf("Invalid arguments: ./client <process_id> <string>\n");
		return (0);
	}
	string_param = argv[2];
	map_string(string_param, process_id);
	return (0);
}
