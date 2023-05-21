/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:43:12 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/21 22:44:11 by johnavar         ###   ########.fr       */
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

int	print_digit(long n, int base, char mode)
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
		return (print_digit(-n, base, mode) + 1);
	}
	else if (n < base)
		return (print_char(symbols[n]));
	else
	{
		count = print_digit(n / base, base, mode);
		return (count + print_digit(n % base, base, mode));
	}
}

int	print_addr(unsigned long int addr)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (addr < 16)
		return (print_char(symbols[addr]));
	else
	{
		count = print_addr(addr / 16);
		return (count + print_addr(addr % 16));
	}
}

int	print_ptr(unsigned long int ptr)
{
	int	count;

	count = write(1, "0x", 2);
	if (ptr == 0)
		count += write(1, "0", 1);
	else
		count += print_addr(ptr);
	return (count);
}
