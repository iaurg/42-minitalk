/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:07:53 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/25 22:02:39 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	size_t	hex_size(unsigned int number)
{
	size_t	size;

	size = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number = number / 16;
		size++;
	}
	return (size);
}

int	ft_printf_x(unsigned int number, char flag)
{
	int		iterator;
	int		remainder;
	char	*hex_table;
	size_t	size;

	size = hex_size(number);
	hex_table = malloc(size * sizeof(char));
	if (!hex_table)
		return (0);
	iterator = size;
	while (iterator)
	{
		remainder = number % 16;
		if (remainder < 10)
			hex_table[--iterator] = 48 + remainder;
		else if (flag == 'X')
			hex_table[--iterator] = 55 + remainder;
		else if (flag == 'x')
			hex_table[--iterator] = 87 + remainder;
		number = number / 16;
	}
	write(1, hex_table, size);
	free(hex_table);
	return (size);
}
