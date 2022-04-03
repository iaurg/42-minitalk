/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaureli <itaureli@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:22:32 by itaureli          #+#    #+#             */
/*   Updated: 2021/08/24 23:58:42 by itaureli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"
int	ft_printf(const char *type, ...);
int	ft_parse_flag(const char *format, va_list ap);
int	ft_printf_c(int c);
int	ft_printf_s(char *s);
int	ft_printf_p(size_t number);
int	ft_printf_d(int number);
int	ft_printf_i(int number);
int	ft_printf_u(unsigned int number);
int	ft_printf_x(unsigned int number, char flag);
#endif
