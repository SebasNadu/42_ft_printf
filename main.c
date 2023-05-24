/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:41:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/24 15:53:48 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdint.h>

int	main(void)
{
	int	count;
	int	num;

	count = 123;
	printf("print 123 =>%.5d\n", count);
	printf("print 123 =>%.5x\n", count);
	printf("print 123 =>%.5c\n", 'h');
	printf("print 123 =>%.5s\n", NULL);
	printf("print 123 =>%.5p\n", &count);
	/*count = ft_printf("hello %s\n", "me");*/
	/*ft_printf("The chars written in ft_printf are %d\n", count);*/
	/*ft_printf("Now on Hexadecimal %x or %X\n", count, count);*/
	/*count = ft_printf("%d\n", INT32_MIN);*/
	/*ft_printf("The chars written in printf are %d\n", count);*/
	/*ft_printf("Now on Hexadecimal %x or %X\n", count, count);*/
	/*count = printf("%d\n", INT32_MIN);*/
	/*printf("The chars written in printf are %\n", count);*/
	/*printf("Now on Hexadecimal %x or %X\n", count, count);*/
	/*count = ft_printf("%u\n", UINT32_MAX);*/
	/*ft_printf("The chars written in ft_printf are %d\n", count);*/
	/*count = printf("%u\n", UINT32_MAX);*/
	/*printf("The chars written in printf are %d\n", count);*/
	/*ft_printf("The address of the counter is %p\n", &count);*/
	/*printf("The address of the counter is %p\n", &count);*/
	return (count);
}
