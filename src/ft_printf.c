/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:01:25 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/24 12:01:12 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_spec(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == '%')
		count += write(1, &spec, 1);
	else if (spec == 'c')
		count = print_char(va_arg(ap, int));
	else if (spec == 's')
		count += print_str(va_arg(ap, char *));
	else if (spec == 'p')
		count += print_ptr((unsigned long int)va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10, spec);
	else if (spec == 'x' || spec == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, spec);
	else if (spec == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, spec);
	return (count);
}

t_print	initialize_tab(void)
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

const char	*parse_flags(const char *format, va_list ap, t_print *flags)
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
			*flags = ft_flag_width(ap, *flags);
		if (ft_isdigit(*(format)))
			*flags = ft_flag_digit(*(format), *flags);
		if (ft_istype(*(format)))
		{
			flags->spec = *(format);
			break ;
		}
	}
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
			format = parse_flags(format, ap, &flags);
			count += parse_spec(flags.spc, ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
