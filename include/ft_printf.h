/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:52 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/24 11:57:44 by johnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

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

int			ft_printf(const char *strf, ...);
int			parse_spec(char spec, va_list ap);
int			print_digit(long n, int base, char mode);
int			print_str(char *str);
int			print_char(int c);
int			print_ptr(unsigned long int ptr);
int			print_addr(unsigned long int addr);
t_print		initialize_tab(void);
const char	*parse_flags(const char *format, va_list ap, t_print *flags);
int			ft_isspec(int c);
int			ft_istype(int c);
int			ft_isflag(int c);
t_print		ft_flag_left(t_print flags);
const char	*ft_flag_prc(const char *format, va_list ap, t_print *flags);

#endif
