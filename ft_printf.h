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
	char	type;
	int		star;
	int		width;
}				s_flag;

int				ft_printf(const char *fmt, ...);
void			ft_putchar(char c, int *ret);
void			ft_putnbr(int d, int *ret);
void			ft_putstr(char *s, int *ret, s_flag *a);
int				ft_flags(va_list ap, int *ret, char *str, s_flag *a, static int *i);
int				ft_isdigit(char c);
int				ft_width(char *str, static int *i);
int				ft_star(char *str, va_list ap);
int				ft_nextarg(char *str, va_list ap);
int				ft_dot(char *str, va_list ap, static int i);
void			ft_type(va_list ap, int *ret, char *str, s_flag *a, static int *i);
void			ft_printfC(va_list ap, int *ret, char *str, s_flag *a);
void			ft_printfS(va_list ap, int *ret, char *str, s_flag *a);
void			ft_writestr(char *s, int *ret, s_flag *a, int width, int dot, int len);
void			ft_printfP(va_list ap, int *ret, char *str, s_flag *a);


#endif
