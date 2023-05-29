/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:11:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/29 22:03:43 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_flag_left(t_print *flags)
{
	flags->left = 1;
	flags->zero = 0;
}

int	ft_flag_prec(const char *format, int i, va_list *ap, t_print *flags)
{
	int	j;

	j = i + 1;
	if (flags->zero == 1)
		flags->zero = 0;
	if (format[j] == '*')
	{
		flags->precision = va_arg(*ap, int);
		return (i++);
	}
	flags->precision = 0;
	while (ft_isdigit(format[i]))
	{
		flags->precision = (flags->precision * 10) + (format[i] - '0');
		i++;
	}
	return (i);
}

void	ft_flag_star(va_list *ap, t_print *flags)
{
	flags->star = 1;
	flags->width = va_arg(*ap, int);
	if (flags->width < 0)
	{
		flags->left = 1;
		flags->width = -flags->width;
	}
}

void	ft_flag_digit(char c, t_print *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - '0');
}

t_print	ft_initialize_tab(void)
{
	t_print	flags;

	flags.spec = 0;
	flags.width = 0;
	flags.left = 0;
	flags.zero = 0;
	flags.precision = -1;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.star = 0;
	return (flags);
}
