#include "ft_printf.h"

void	ft_printfC(va_list ap, int *ret, char *str, s_flag *a)
{
	int	c;
	va_list ap2;

	c = (char) va_copy(ap2, ap);
	ft_putchar(c, ret);
	va_end(ap2);
}
