/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:41:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/30 12:19:45 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdint.h>

int	main(void)
{
	int	count;
	int	num;
	int	num2;

	count = -1;
	num = 5;
	num2 = 12;
	// Char tesst //
	printf("\nInit Print Char\n");
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
	// String Print
	printf("\nInit Print Str\n");
	printf("printf str =>%s\n", "Hello!!");
	ft_printf("fprint str =>%s\n", "Hello!!");
	printf("printf str 10=>%10s\n", "Hello!!");
	ft_printf("fprint str 10=>%10s\n", "Hello!!");
	printf("printf str -10=>%-10s\n", "Hello!!");
	ft_printf("fprint str -10=>%-10s\n", "Hello!!");
	printf("printf str .5=>%.5s\n", "Hello!!");
	ft_printf("fprint str .5=>%.5s\n", "Hello!!");
	printf("printf str *=>%*s\n", 10, "Hello!!");
	ft_printf("fprint str *=>%*s\n", 10, "Hello!!");
	printf("printf str .*=>%.*s\n", num, "Hello!!");
	ft_printf("fprint str .*=>%.*s\n", num, "Hello!!");
	printf("printf str 10.5=>%10.5s\n", "Hello!!");
	ft_printf("fprint str 10.5=>%10.5s\n", "Hello!!");
	printf("printf str -10.5=>%-10.5s\n", "Hello!!");
	ft_printf("printf str -10.5=>%-10.5s\n", "Hello!!");
	printf("printf str -10.*=>%-10.*s\n", num, "Hello!!");
	ft_printf("printf str -10.*=>%-10.*s\n", num, "Hello!!");
	// Integer Print
	printf("\nInit Print Int\n");
	printf("printf +int =>%i\n", num);
	ft_printf("fprint +int =>%i\n", num);
	printf("printf -int =>%i\n", INT32_MIN);
	ft_printf("fprint -int =>%i\n", INT32_MIN);
	printf("printf +int 12=>%12i\n", num);
	ft_printf("fprint +int 12=>%12i\n", num);
	printf("printf +int *=>%*i\n", num2, num);
	ft_printf("fprint +int *=>%*i\n", num2, num);
	printf("printf -int 12=>%12i\n", INT32_MIN);
	ft_printf("fprint -int 12=>%12i\n", INT32_MIN);
	printf("printf -int *=>%*i\n", num2, INT32_MIN);
	ft_printf("fprint -int *=>%*i\n", num2, INT32_MIN);
	printf("printf +int -12=>%-12i\n", num);
	ft_printf("fprint +int -12=>%-12i\n", num);
	printf("printf +int -*=>%-*i\n", num2, num);
	ft_printf("fprint +int -*=>%-*i\n", num2, num);
	printf("printf -int -12=>%-12i\n", INT32_MIN);
	ft_printf("fprint -int -12=>%-12i\n", INT32_MIN);
	printf("printf -int -*=>%-*i\n", num2, INT32_MIN);
	ft_printf("fprint -int -*=>%-*i\n", num2, INT32_MIN);
	printf("printf +int 012=>%012i\n", num);
	ft_printf("fprint +int 012=>%012i\n", num);
	printf("printf +int 0*=>%0*i\n", num2, num);
	ft_printf("fprint +int 0*=>%0*i\n", num2, num);
	printf("printf -int 012=>%012i\n", INT32_MIN);
	ft_printf("fprint -int 012=>%012i\n", INT32_MIN);
	printf("printf -int 0*=>%0*i\n", num2, INT32_MIN);
	ft_printf("fprint -int 0*=>%0*i\n", num2, INT32_MIN);
	printf("printf +int +=>%+i\n", num);
	ft_printf("fprint +int +=>%+i\n", num);
	printf("printf -int +=>%+i\n", INT32_MIN);
	ft_printf("fprint -int +=>%+i\n", INT32_MIN);
	printf("printf +int spc=>% i\n", num);
	ft_printf("fprint +int spc=>% i\n", num);
	printf("printf -int spc=>% i\n", INT32_MIN);
	ft_printf("fprint -int spc=>% i\n", INT32_MIN);
	printf("printf +int .12=>%.12i\n", num);
	ft_printf("fprint +int .12=>%.12i\n", num);
	printf("printf +int .*=>%.*i\n", num2, num);
	ft_printf("fprint +int .*=>%.*i\n", num2, num);
	printf("printf -int .12=>%.12i\n", INT32_MIN);
	ft_printf("fprint -int .12=>%.12i\n", INT32_MIN);
	printf("printf -int .*=>%.*i\n", num2, INT32_MIN);
	ft_printf("fprint -int .*=>%.*i\n", num2, INT32_MIN);
	return (count);
}
