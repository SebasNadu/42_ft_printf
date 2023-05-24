/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/24 12:00:53 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	ft_flag_left(t_print flags)
{
	flags.left = 1;
	flags.zero = 0;
	return (flags);
}

const char	*ft_flag_prc(const char *format, va_list ap, t_print *flags)
{
	if (*(++format) == '*')
	{
		flags->prc = va_arg(ap, int);
		return (++format);
	}
	flags->prc = 0;
	while (ft_isdigit(*(format)))
	{
		flags->prc = (flags->prc * 10) + (*(format) - '0');
		format++;
	}
	return (format);
}
