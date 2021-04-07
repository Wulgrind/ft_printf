/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai </var/mail/qbrillai>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:18:35 by qbrillai          #+#    #+#             */
/*   Updated: 2021/04/07 17:18:37 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flag
{
	int		zero;
	int		dot;
	int		minus;
	int		star;
	int		width;
	int		ret;
}				t_flag;

int				ft_checktype(char i);
int				ft_len(unsigned int u, t_flag *a);
char			*ft_stdrup(const char *src);
int				ft_printf(const char *fmt, ...);
void			ft_putchar(char c, t_flag *a);
void			ft_putnbr(long int d, t_flag *a);
void			ft_putstr(char *str, t_flag *a);
int				ft_flags(va_list ap, char *str, t_flag *a, int *i);
int				ft_isdigit(char c);
int				ft_width(char *str, int *i);
int				ft_nextarg(va_list ap, t_flag *a);
int				ft_dot(char *str, int *i, va_list ap);
void			ft_type(va_list ap, char *str, t_flag *a, int *i);
void			ft_printfC(va_list ap, t_flag *a);
void			ft_printfS(va_list ap, t_flag *a);
int				ft_printfP(va_list ap, t_flag *a);
void			ft_printfD(va_list ap, t_flag *a);
void			ft_initflags(t_flag *a);
void			ft_printfU(va_list ap, t_flag *a);
int				ft_printfX(va_list ap, t_flag *a, int c);
int				ft_check(char *str);
int				ft_strlen(char *s);
void			ft_putstrlen(char *str, t_flag *a, int len);
void			ft_putnbru(unsigned int u, t_flag *a);
int				ft_nextdot(va_list ap);
int				ft_lenP(unsigned long long x);
int				ft_lenU(unsigned int u, t_flag *a);

#endif
