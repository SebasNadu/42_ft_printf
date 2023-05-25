/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:52 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/25 09:23:08 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# if defined (__linux__)
#  define NNULL "(nil)"
# elif defined (__APPLE__)
#  define NNULL "0x0"
# endif

typedef struct s_print
{
	int			spec;
	int			width;
	int			left;
	int			zero;
	int			precision;
	int			hash;
	int			space;
	int			plus;
	int			star;
}				t_print;

int			ft_printf(const char *strf, ...);
int			ft_print_spec(char spec, va_list ap, t_print flags);
int			ft_print_digit(long n, int base, char mode);
int			ft_print_char(int c, t_print flags);
int			ft_print_str(char *str, t_print flags);
int			ft_print_ptr(unsigned long int ptr, t_print flags);
const char	*ft_flag_precision(const char *format, va_list ap, t_print *flags);
int			ft_print_s(const char *str);
int			ft_print_s_wprecision(const char *str, int precision);
int			ft_print_addr(unsigned long int addr);
t_print		ft_initialize_tab(void);
const char	*ft_parse_flags(const char *format, va_list ap, t_print *flags);
int			ft_isspec(int c);
int			ft_istype(int c);
int			ft_isflag(int c);
t_print		ft_flag_left(t_print flags);
const char	*ft_flag_prc(const char *format, va_list ap, t_print *flags);
t_print		ft_flag_star(va_list ap, t_print flags);
t_print		ft_flag_digit(char c, t_print flags);

#endif
