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
}				s_flag;

char			*ft_stdrup(const char *src);
int				ft_printf(const char *fmt, ...);
void			ft_putchar(char c, int *ret);
void			ft_putnbr(int d, int *ret);
void			ft_putstr(char *s, int *ret, s_flag *a);
int				ft_flags(va_list ap, int *ret, char *str, s_flag *a, int *i);
int				ft_isdigit(char c);
int				ft_width(char *str, int *i);
int				ft_star(char *str, va_list ap, int *i);
int				ft_nextarg(va_list ap);
int				ft_dot(char *str, int *i);
void			ft_type(va_list ap, int *ret, char *str, s_flag *a, int *i);
void			ft_printfC(va_list ap, int *ret);
void			ft_printfS(va_list ap, int *ret, s_flag *a);
void			ft_writestr(char *s, int *ret, s_flag *a, int width, int dot, int len);
int				ft_printfP(va_list ap, int *ret, s_flag *a);
void			ft_printfD(va_list ap, int *ret, s_flag *a);
void			ft_initflags(s_flag *a);
void			ft_printfU(va_list ap, int *ret, s_flag *a);
int				ft_printfX(va_list ap, int *ret, s_flag *a, int c);
int				ft_check(char *str);
int				ft_strlen(char *s);

#endif
