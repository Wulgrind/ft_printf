#include "ft_printf.h"
#include <stdio.h>

void	ft_printfC(va_list ap, int *ret, s_flag *a)
{
	int	c;
	int	len;

	len = 1;
	c = (char) va_arg(ap, int);
	if (a->dot > 0)
		while (len + a->width > a->dot)
			(a->width)--;
	if (a->zero == 0 && a->minus == 0)
	{
		while (len < a->width && a->width != 1)
		{
			ft_putchar(' ', ret);
			len++;
		}
	}
	ft_putchar(c, ret);
	if (a->zero > 0 || a->minus > 0)
	{
		while (len < a->width)
		{
			if (a->minus > 0)
				ft_putchar(' ', ret);
			if (a->zero > 0 && a->minus == 0)
				ft_putchar('0', ret);
			len++;
		}
	}
}
