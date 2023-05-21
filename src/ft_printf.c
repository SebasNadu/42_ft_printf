/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:01:25 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/21 22:45:00 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_spec(char mode, va_list ap)
{
	int	count;

	count = 0;
	if (mode == '%')
		count += write(1, &mode, 1);
	else if (mode == 'c')
		count = print_char(va_arg(ap, int));
	else if (mode == 's')
		count += print_str(va_arg(ap, char *));
	else if (mode == 'p')
		count += print_ptr((unsigned long int)va_arg(ap, void *));
	else if (mode == 'd' || mode == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10, mode);
	else if (mode == 'x' || mode == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, mode);
	else if (mode == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, mode);
	return (count);
}

t_print	initialize_tab(void)
{
	t_print	flags;

	flags.spec = 0;
	flags.width = 0;
	flags.left = 0;
	flags.zero = 0;
	flags.prc = 0;
	flags.hash = 0;
	flags.spc = 0;
	flags.plus = 0;
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	t_print	flags;
	va_list	ap;

	if (!format)
		return (0);
	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			flags = initialize_tab();
			count += print_spec(*(++format), ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
