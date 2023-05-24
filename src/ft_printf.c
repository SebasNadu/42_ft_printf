/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:01:25 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/24 16:24:20 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_spec(char spec, va_list ap, t_print flags)
{
	int	count;

	count = 0;
	if (spec == '%')
		count += ft_print_char(spec, flags);
	else if (spec == 'c')
		count = ft_print_char(va_arg(ap, int), flags);
	else if (spec == 's')
		count += ft_print_str(va_arg(ap, char *), flags);
	else if (spec == 'p')
		count += ft_print_ptr((unsigned long int)va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_print_digit((long)(va_arg(ap, int)), 10, spec);
	else if (spec == 'x' || spec == 'X')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), 16, spec);
	else if (spec == 'u')
		count += ft_print_digit((long)(va_arg(ap, unsigned int)), 10, spec);
	return (count);
}

t_print	ft_initialize_tab(void)
{
	t_print	flags;

	flags.spec = 0;
	flags.width = 0;
	flags.left = 0;
	flags.zero = 0;
	flags.prc = -1;
	flags.hash = 0;
	flags.spc = 0;
	flags.plus = 0;
	flags.star = 0;
	return (flags);
}

const char	*ft_parse_flags(const char *format, va_list ap, t_print *flags)
{
	while (*(++format) && ft_isflag(*(format)))
	{
		if (*(format) == '-')
			*flags = ft_flag_left(*flags);
		if (*(format) == ' ')
			flags->spc = 1;
		if (*(format) == '+')
			flags->plus = 1;
		if (*(format) == '#')
			flags->hash = 1;
		if (*(format) == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (*(format) == '.')
			format = ft_flag_prc(format, ap, flags);
		if (*(format) == '*')
			*flags = ft_flag_star(ap, *flags);
		if (ft_isdigit(*(format)))
			*flags = ft_flag_digit(*(format), *flags);
		if (ft_istype(*(format)))
		{
			flags->spec = *(format);
			break ;
		}
	}
	return (format);
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
			flags = ft_initialize_tab();
			format = ft_parse_flags(format, ap, &flags);
			count += ft_print_spec(flags.spc, ap, flags);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
