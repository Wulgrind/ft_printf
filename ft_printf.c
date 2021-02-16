#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		d;
	char	c,	*s;
	va_start(ap, fmt);
	while (*fmt)
		switch (*fmt++)
		{
			case s :	/* chaine */
				s = va_arg (ap, char *);
				ft_putstr(char *s);
				break;
			case d :	/* int */
				d = va_arg (ap, int);
				ft_putnbr(int d);
				break;
			case c :	/* character */
				c = va_arg (ap, char);
				ft_putchar(char c);
				break;
		}
	va_end(ap);
}
