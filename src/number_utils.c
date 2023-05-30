/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasnadu <johnavar@student.42berlin.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:39:30 by sebasnadu         #+#    #+#             */
/*   Updated: 2023/05/30 11:40:00 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
