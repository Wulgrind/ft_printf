#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		d;
	char	c,	*s;
	int		ret;

	ret = 0;
	va_start(ap, format);
	if (*format)
		switch (*format)
		{
			case 's' :	/* chaine */
				s = va_arg (ap, char *);
				ft_putstr(s, &ret);
				break;
			case 'd' :	/* int */
				d = va_arg (ap, int);
				ft_putnbr(d, &ret);
				break;
			case 'c' :	/* character */
				c = (char) va_arg (ap, int);
				ft_putchar(c, &ret);
				break;
		}
	va_end(ap);
	return (ret);
}

int	main()
{
	
}
