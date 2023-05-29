/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnavar <johnavar@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:04:52 by johnavar          #+#    #+#             */
/*   Updated: 2023/05/29 22:01:11 by sebasnadu        ###   ########.fr       */
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

int		ft_printf(const char *strf, ...);
int		ft_parse_format(const char *format, va_list *ap);
int		ft_print_spec(char spec, va_list *ap, t_print *flags);
t_print	ft_initialize_tab(void);
int		ft_parse_flags(const char *format, int i, va_list *ap, t_print *flags);
int		ft_isflag(int c);
int		ft_istype(int c);
int		ft_isspec(int c);
void	ft_flag_left(t_print *flags);
void	ft_flag_star(va_list *ap, t_print *flags);
int		ft_flag_prec(const char *format, int i, va_list *ap, t_print *flags);
void	ft_flag_digit(char c, t_print *flags);
int		ft_print_c(char c);
int		ft_print_char(char c, t_print *flags);
int		ft_print_pad(int width, int size, int zero);

#endif
