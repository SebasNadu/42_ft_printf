/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:01:25 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/20 21:55:52 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		print_char((int)*str);
		count++;
		str++;
	}
	return (count);
}

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base);
		return (count + print_digit(n % base, base));
	}
}

int	print_f(char mode, va_list ap)
{
	int	count;

	count = 0;
	if (mode == 'c')
		count = print_char(va_arg(ap, int));
	else if (mode == 's')
		count += print_str(va_arg(ap, char *));
	else if (mode == 'd')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (mode == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);
	else
		count += write(1, &mode, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
			count += print_f(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
