#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *fmt, ...);
void	ft_putchar(char c, int *ret);
void	ft_putnbr(int d, int *ret);
void	ft_putstr(char *s, int *ret);

#endif
