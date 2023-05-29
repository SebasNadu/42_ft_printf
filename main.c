/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:41:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/29 20:57:03 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdint.h>

int	main(void)
{
	int	count;
	int	num;

	count = -1;
	num = 5;
	printf("printf char simple=>%c\n", 'c');
	ft_printf("fprint char simple=>%c\n", 'c');
	printf("printf char *=>%*c\n", num, 'c');
	ft_printf("fprint char *=>%*c\n", num, 'c');
	printf("printf char -=>%-5c\n", 'c');
	ft_printf("fprint char -=>%-5c\n", 'c');
	printf("printf char -*=>%-*c\n", num, 'c');
	ft_printf("fprint char -*=>%-*c\n", num, 'c');
	printf("printf char 0=>%05c\n", 'c');
	ft_printf("fprint char 0=>%05c\n", 'c');
	printf("printf char 0*=>%0*c\n", num, 'c');
	ft_printf("fprint char 0*=>%0*c\n", num, 'c');
	printf("printf char .=>%.5c\n", 'c');
	ft_printf("fprint char .=>%.5c\n", 'c');
	printf("printf char .*=>%.*c\n", num, 'c');
	ft_printf("fprint char .*=>%.*c\n", num, 'c');
	printf("printf char *=>%*c\n", num, 'c');
	ft_printf("fprint char *=>%*c\n", num, 'c');
	return (count);
}
