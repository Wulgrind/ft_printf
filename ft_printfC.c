#include "ft_printf.h"

void	ft_printfC(va_list ap, int *ret)
{
	int	c;

	c = (char) va_arg(ap, int);
	ft_putchar(c, ret);
}
