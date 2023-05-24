/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:52 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/21 23:03:04 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_print
{
	int			spec;
	int			width;
	int			left;
	int			zero;
	int			prc;
	int			hash;
	int			spc;
	int			plus;
	int			star;
}				t_print;

int		ft_printf(const char *strf, ...);
int		parse_spec(char spec, va_list ap);
int		print_digit(long n, int base, char mode);
int		print_str(char *str);
int		print_char(int c);
int		print_ptr(unsigned long int ptr);
int		print_addr(unsigned long int addr);
t_print	initialize_tab(void);
int		parse_flags(const char *format, va_list ap, t_print *flags);

#endif
