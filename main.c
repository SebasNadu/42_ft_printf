/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 00:41:33 by johnavar          #+#    #+#             */
/*   Updated: 2023/06/02 23:21:51 by sebasnadu        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdint.h>
#include <limits.h>

int	main(void)
{
	int	count;
	int	num;
	int	num2;
	char	*null_str;

	count = -1;
	num = 5;
	num2 = 12;
	null_str = NULL;
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
	// Integer Hexadecimal
	printf("\nInit Print Hexadecimal\n");
	printf("printf hex x=>%x\n", INT32_MAX);
	ft_printf("fprint hex x=>%x\n", INT32_MAX);
	printf("printf -hex =>%x\n", INT32_MIN);
	ft_printf("fprint -hex =>%x\n", INT32_MIN);
	printf("printf hex X=>%X\n", INT32_MAX);
	ft_printf("fprint hex X=>%X\n", INT32_MAX);
	printf("printf hex #X=>%#X\n", INT32_MAX);
	ft_printf("fprint hex #X=>%#X\n", INT32_MAX);
	printf("printf hex 12=>%12x\n", -1);
	ft_printf("fprint hex 12=>%12x\n", -1);
	printf("printf hex *=>%*x\n", num2, -1);
	ft_printf("fprint hex *=>%*x\n", num2, -1);
	printf("printf hex -12=>%-12x\n", -1);
	ft_printf("fprint hex -12=>%-12x\n", -1);
	printf("printf hex -*=>%-*x\n", num2, -1);
	ft_printf("fprint hex -*=>%-*x\n", num2, -1);
	printf("printf hex 012=>%012x\n", -1);
	ft_printf("fprint hex 012=>%012x\n", -1);
	printf("printf hex 0*=>%0*x\n", num2, -1);
	ft_printf("fprint hex 0*=>%0*x\n", num2, -1);
	printf("printf hex +=>%+x\n", -1);
	ft_printf("fprint hex +=>%+x\n", -1);
	printf("printf hex spc=>% x\n", -1);
	ft_printf("fprint hex spc=>% x\n", -1);
	printf("printf hex .12=>%.12x\n", -1);
	ft_printf("fprint hex .12=>%.12x\n", -1);
	printf("printf hex .*=>%.*x\n", num2, -1);
	ft_printf("fprint hex .*=>%.*x\n", num2, -1);
	printf("printf hex #.*=>%#.*x\n", num2, -1);
	ft_printf("fprint hex #.*=>%#.*x\n", num2, -1);
	// Print Address
	printf("\nInit Print Pointer\n");
	printf("printf p =>%p\n", &num);
	ft_printf("fprint p =>%p\n", &num);
	printf("printf p =>%p\n", NULL);
	ft_printf("fprint p =>%p\n", NULL);
	printf("printf p 12=>%12p\n", &num);
	ft_printf("fprint p 12=>%12p\n", &num);
	printf("printf p 12=>%12p\n", NULL);
	ft_printf("fprint p 12=>%12p\n", NULL);
	printf("printf p -12=>%-12p\n", &num);
	ft_printf("fprint p -12=>%-12p\n", &num);
	printf("printf p -12=>%-12p\n", NULL);
	ft_printf("fprint p -12=>%-12p\n", NULL);
	printf("printf p 012=>%012p\n", &num);
	ft_printf("fprint p 012=>%012p\n", &num);
	printf("printf p 012=>%012p\n", NULL);
	ft_printf("fprint p 012=>%012p\n", NULL);
	// Print Unsigned
	printf("\nInit Print Unsigned\n");
	printf("printf u =>%u\n", num);
	ft_printf("fprint u =>%u\n", num);
	printf("printf u 12=>%12u\n", num);
	ft_printf("fprint u 12=>%12u\n", num);
	printf("printf u *=>%*u\n", num2, num);
	ft_printf("fprint u *=>%*u\n", num2, num);
	printf("printf u -12=>%-12u\n", num);
	ft_printf("fprint u -12=>%-12u\n", num);
	printf("printf u -*=>%-*u\n", num2, num);
	ft_printf("fprint u -*=>%-*u\n", num2, num);
	printf("printf u 012=>%012u\n", num);
	ft_printf("fprint u 012=>%012u\n", num);
	printf("printf u 0*=>%0*u\n", num2, num);
	ft_printf("fprint u 0*=>%0*u\n", num2, num);
	printf("printf u +=>%+u\n", num);
	ft_printf("fprint u +=>%+u\n", num);
	printf("printf u spc=>% u\n", num);
	ft_printf("fprint u spc=>% u\n", num);
	printf("printf u .12=>%.12u\n", num);
	ft_printf("fprint u .12=>%.12u\n", num);
	printf("printf u .*=>%.*u\n", num2, num);
	ft_printf("fprint u .*=>%.*u\n", num2, num);
	// Extra tests
	printf("\nInit Extra Tests\n");
	/* printf(" %-9p %-10p \n", LONG_MIN, LONG_MAX);
	ft_printf(" %-9p %-10p \n", LONG_MIN, LONG_MAX);
	printf(" %-13p %-14p \n", ULONG_MAX, -ULONG_MAX);
	ft_printf(" %-13p %-14p \n", ULONG_MAX, -ULONG_MAX); */
	printf("printf=>%.1s\n", null_str);
	ft_printf("fprint=>%.1s\n", null_str);
	printf("pf as soon as %-10possible\n", (void *) -1);
	ft_printf("fp as soon as %-10possible\n", (void *) -1);
	printf("printf =>%-11p %-12p \n", INT32_MIN, INT32_MAX);
	ft_printf("fprint =>%-12p %-12p \n", INT32_MIN, INT32_MAX);
	return (count);
}
