/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:43:49 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/23 21:43:16 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	to_c(int c)
{
	return (c + '0');
}

static unsigned int	count_elements(unsigned int n)
{
	int	counter;

	counter = 1;
	while (n / 10)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_uitoa(unsigned int n)
{
	char	*final_string;
	int		counter;

	counter = count_elements(n);
	final_string = (char *) malloc(sizeof(char) * (counter + 1));
	if (!final_string)
		return (NULL);
	final_string[counter] = '\0';
	while (counter--)
	{
		final_string[counter] = to_c(n % 10);
		n = n / 10;
	}
	return (final_string);
}

int	ft_printf_u(unsigned int number)
{
	char	*str;
	int		len;

	if (number < 0)
		number = -number;
	str = ft_uitoa(number);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
