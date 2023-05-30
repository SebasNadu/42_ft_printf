/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:43:12 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/30 11:48:15 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_i_wzero(long n, t_print *flags)
{
	int	count;

	count = 0;
	if (n < 0 && flags->precision == -1)
	{
		count += write(1, "-", 1);
		flags->width--;
	}
	else if (flags->plus == 1)
		count += write(1, "+", 1);
	else if (flags->space == 1)
	{
		count += write(1, " ", 1);
		flags->width--;
	}
	return (count);
}

static int	ft_print_i(long n, char spec, t_print *flags)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flags->zero == 0 || flags->precision >= 0)
			count += write(1, "-", 1);
	}
	else if (flags->plus == 1 && flags->zero == 0)
		count += write(1, "+", 1);
	else if (flags->space == 1 && flags->zero == 0)
		count += write(1, "+", 1);
	if (flags->precision >= 0)
		count += ft_print_pad(flags->precision - 1, ft_nbr_len(n, 10) - 1, 1);
	if (n < 0)
		count += ft_print_digit(-n, 10, spec);
	else
		count += ft_print_digit(n, 10, spec);
	return (count);
}

int	ft_print_int(long n, char spec, t_print *flags)
{
	int		count;

	count = 0;
	if (flags->precision == 0 && n == 0)
	{
		count += ft_print_pad(flags->width, 0, flags->zero);
		return (count);
	}
	if (flags->zero == 1)
		count += ft_print_i_wzero(n, flags);
	if (flags->left == 1)
		count += ft_print_i(n, spec, flags);
	if (flags->precision >= 0 && flags->precision < ft_nbr_len(n, 10))
		flags->precision = ft_nbr_len(n, 10);
	if (flags->precision >= 0)
	{
		flags->width -= flags->precision;
		if (n < 0 && flags->left == 0)
			flags->width -= 1;
		count += ft_print_pad(flags->width, 0, 0);
	}
	else
		count += ft_print_pad(flags->width - flags->plus - flags->space,
				ft_nbr_len(n, 10), flags->zero);
	if (flags->left == 0)
		count += ft_print_i(n, spec, flags);
	return (count);
}
