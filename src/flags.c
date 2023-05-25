/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/25 10:23:57 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	ft_flag_left(t_print flags)
{
	flags.left = 1;
	flags.zero = 0;
	return (flags);
}

const char	*ft_flag_precision(const char *format, va_list ap, t_print *flags)
{
	if (flags->zero == 1)
		flags->zero = 0;
	if (*(++format) == '*')
	{
		flags->precision = va_arg(ap, int);
		return (++format);
	}
	flags->precision = 0;
	while (ft_isdigit(*(format)))
	{
		flags->precision = (flags->precision * 10) + (*(format) - '0');
		format++;
	}
	return (format);
}

t_print	ft_flag_star(va_list ap, t_print flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.left = 1;
		flags.width *= -1;
	}
	return (flags);
}

t_print	ft_flag_digit(char c, t_print flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}
