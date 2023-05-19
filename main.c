/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:41:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/20 00:52:56 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("hello %s\n", "me");
	ft_printf("The chars written are %d\n", count);
	count = ft_printf("%d\n", INT32_MIN);
	ft_printf("The chars written are %d\n", count);
	count = printf("%d\n", INT32_MIN);
	printf("The chars written are %d\n", count);
	count = ft_printf("%x\n", INT32_MIN);
	ft_printf("The chars written are %d\n", count);
	count = printf("%x\n", INT32_MIN);
	printf("The chars written are %d\n", count);
	return (count);
}
