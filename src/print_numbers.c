/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:43:12 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/25 11:43:21 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(unsigned long int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n >= 1)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_print_pad(int width, int size, int zero)
{
	int	count;

	count = 0;
	while (width - size > 0)
	{
		if (zero)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
		width--;
	}
	return (count);
}

int	ft_print_digit(long n, int base, char mode)
{
	int		count;
	char	*symbols;

	if (mode == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base, mode) + 1);
	}
	else if (n < base)
		return (write(1, &symbols[n], 1));
	else
	{
		count = ft_print_digit(n / base, base, mode);
		return (count + ft_print_digit(n % base, base, mode));
	}
}

int	ft_print_i_wzero(long n, t_print *flags)
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

int	ft_print_i(long n, t_print flags)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			count += write(1, "-", 1);
	}
	else if (flags.plus == 1 && flags.zero == 0)
		count += write(1, "+", 1);
	else if (flags.space == 1 && flags.zero == 0)
		count += write(1, "+", 1);
	if (flags.precision >= 0)
		count += ft_print_pad(flags.precision - 1, ft_nbr_len(n, 10) - 1, 1);
	if (n < 0)
		count += ft_print_digit(-n, 10, 'i');
	else
		count += ft_print_digit(n, 10, 'i');
	return (count);
}

int	ft_print_int(long n, t_print flags)
{
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_print_pad(flags.width, 0, flags.zero);
		return (count);
	}
	if (flags.zero == 1)
		count += ft_print_i_wzero(n, &flags);
	if (flags.left == 1)
		count += ft_print_i(n, flags);
	if (flags.precision >= 0 && flags.precision < ft_nbr_len(n, 10))
		flags.precision = ft_nbr_len(n, 10);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		if (n < 0 && flags.left == 0)
			flags.width -= 1;
		count += ft_print_pad(flags.width, 0, 0);
	}
	else
		count += ft_print_pad(flags.width - flags.plus - flags.space,
				ft_nbr_len(n, 10), flags.zero);
	if (flags.left == 0)
		count += ft_print_i(n, flags);
	return (count);
}

int	ft_print_addr(unsigned long int addr)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (addr < 16)
		return (write(1, &symbols[addr], 1));
	else
	{
		count = ft_print_addr(addr / 16);
		return (count + ft_print_addr(addr % 16));
	}
}

int	ft_print_p(unsigned long int p)
{
	int	count;

	count = 0;
	if (p == 0)
	{
		count += ft_print_s(NNULL);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_print_addr(p);
	return (count);
}

int	ft_print_ptr(unsigned long int ptr, t_print flags)
{
	int	count;

	count = 0;
	if (ptr == 0)
		flags.width -= ft_strlen(NNULL) - 1;
	else
		flags.width -= 2;
	if (flags.left == 1)
		count += ft_print_p(ptr);
	count += ft_print_pad(flags.width, ft_nbr_len(ptr, 16), 0);
	if (flags.left == 0)
		count += ft_print_p(ptr);
	return (count);
}
