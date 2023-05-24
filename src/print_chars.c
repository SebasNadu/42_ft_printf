/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:17:32 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/24 16:27:59 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

int	ft_print_char(int c, t_print flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += write(1, &c, 1);
	count += ft_print_pad(flags.width, 1, flags.zero);
	if (flags.left == 0)
		count += write(1, &c, 1);
	return (count);
}

static int	ft_print_str2(const char *str, t_print flags)
{
	int	count;

	count = 0;
	if (flags.prc >= 0)
	{
		count += ft_print_pad(flags.prc, ft_strlen(str), 0);
		count += ft_print_s_pre(str, flags.prc);
	}
	else
		count += ft_print_s_pre(str, ft_strlen(str));
	return (count);
}

int	ft_print_str(char *str, t_print flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags.prc >= 0 && flags.prc < 6)
	{
		count += ft_print_pad(flags.width, 0, 0);
		return (count);
	}
	if (str == NULL)
		str = "(null)";
	if (flags.prc >= 0 && flags.prc > ft_strlen(str))
		flags.prc = ft_strlen(str);
	if (flags.left == 1)
		count += ft_print_str2(str, flags);
	if (flags.prc >= 0)
		count += ft_print_pad(flags.width, flags.prc, 0);
	else
		count *= ft_print_pad(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		count += ft_print_str2(str, flags);
	return (count);
}
