#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flag
{
	int		zero;
	int		dot;
	int		minus;
	int		star;
	int		width;
	int		ret;
}				s_flag;

int				ft_len(unsigned int u);
char			*ft_stdrup(const char *src);
int				ft_printf(const char *fmt, ...);
void			ft_putchar(char c, s_flag *a);
void			ft_putnbr(int d, s_flag *a);
void			ft_putstr(char *str, s_flag *a);
int				ft_flags(va_list ap, char *str, s_flag *a, int *i);
int				ft_isdigit(char c);
int				ft_width(char *str, int *i);
int				ft_nextarg(va_list ap, s_flag *a);
int				ft_dot(char *str, int *i, va_list ap);
void			ft_type(va_list ap, char *str, s_flag *a, int *i);
void			ft_printfC(va_list ap, s_flag *a);
void			ft_printfS(va_list ap, s_flag *a);
int				ft_printfP(va_list ap, s_flag *a);
void			ft_printfD(va_list ap, s_flag *a);
void			ft_initflags(s_flag *a);
void			ft_printfU(va_list ap, s_flag *a);
int				ft_printfX(va_list ap, s_flag *a, int c);
int				ft_check(char *str);
int				ft_strlen(char *s);
void			ft_putstrlen(char *str, s_flag *a, int len);
void			ft_putnbru(unsigned int u, s_flag *a);
int				ft_nextdot(va_list ap);
int				ft_lenP(unsigned long long x);
int				ft_lenU(unsigned int u);

#endif
