#include "ft_printf.h"

static void	ft_hexadecimal(unsigned int x, s_flag *a, int c)
{
	unsigned long long i;

	i = x;
	if (i >= 16)
	{
		ft_hexadecimal(i / 16, a, c);
		ft_hexadecimal(i % 16, a, c);
	}
	else
	{
		if (i < 10)
			ft_putchar(i + 48, a);
		if (i >= 10 && c == 2)
			ft_putchar(i + 55, a);
		if (i >= 10 && c == 1)
			ft_putchar(i + 87, a);
	}
}

void	ft_fill(s_flag *a, long int filler)
{
	while (filler > 0)
	{
		if (a->zero > 0 && a->dot < 0 && a->minus == 0)
			ft_putchar('0', a);
		else
			ft_putchar(' ', a);
		filler--;
	}
}

int		ft_printfX(va_list ap, s_flag *a, int c)
{
	unsigned int		x;
	long int 			len;
	long int			filler;
	
	filler = 0;
	x = (unsigned int) va_arg(ap, unsigned int);
	x = (unsigned int)(4294967295 + 1 + x);
	if (a->dot > 0)
		a->zero = 0;
	len = ft_len(x);
	if (a->width > a->dot && len <= a->dot)
		filler = a->width - a->dot;
	if (a->width > len && a->dot < len)
		filler = a->width - len;
	if (a->minus == 0)
		ft_fill(a, filler);
	while (len < a->dot)
	{
		ft_putchar('0', a);
		len++;
	}
	if (!(x == 0 && a->dot >= 0))
		ft_hexadecimal(x, a, c);
	if (a->minus > 0)
		ft_fill(a, filler);
	return (1);
}
