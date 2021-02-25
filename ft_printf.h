#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

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
void			ft_putstr(char *s, int *ret);
int				ft_flags(va_list ap, int *ret, char *str, s_flag *a);
int				ft_isdigit(char c);
int				ft_width(char *str);
int				ft_star(char *str, va_list ap);
int				ft_nextarg(char *str, va_list ap);
int				ft_narg(char *str, va_list ap);

#endif
