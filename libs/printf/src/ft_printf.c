/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 21:45:51 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/26 08:17:29 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_navigate(const char *format, va_list ap)
{
	int	len;

	if (!format)
		return (0);
	len = 0;
	while (*format)
	{
		if (*format == '%' && ft_strchr("cspdiuxX%", format[1]))
			len += ft_parse_flag(++format, ap);
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		len;

	if (!format)
		return (0);
	va_start(list, format);
	len = ft_navigate(format, list);
	va_end(list);
	return (len);
}
