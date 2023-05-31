/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:17:32 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/31 17:18:41 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_c(char c)
{
	if (write(1, &c, 1) == -1)
		return (0);
	return (1);
}

int	ft_print_char(char c, t_print *flags)
{
	int	count;

	count = 0;
	if (flags->left == 1)
		count += ft_print_c(c);
	if (flags->width > 1)
		count += ft_print_pad(flags->width, 1, flags->zero);
	if (flags->left == 0)
		count += ft_print_c(c);
	return (count);
}

static int	ft_print_s_precision(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		count++;
	write(1, str, count);
	return (count);
}

static int	ft_print_str(const char *str, t_print *flags)
{
	int	count;

	count = 0;
	if (flags->precision >= 0)
	{
		count += ft_print_pad(flags->precision, ft_strlen(str), 0);
		count += ft_print_s_precision(str, flags->precision);
	}
	else
		count += ft_print_s_precision(str, ft_strlen(str));
	return (count);
}

int	ft_print_string(char *str, t_print *flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags->precision >= 0 && flags->precision < 6)
	{
		count += ft_print_pad(flags->width, 0, 0);
		return (count);
	}
	if (str == NULL)
		str = "(null)";
	if (flags->precision >= 0 && (size_t)flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->left == 1)
		count += ft_print_str(str, flags);
	if (flags->precision >= 0)
		count += ft_print_pad(flags->width, flags->precision, 0);
	else
		count += ft_print_pad(flags->width, ft_strlen(str), 0);
	if (flags->left == 0)
		count += ft_print_str(str, flags);
	return (count);
}
