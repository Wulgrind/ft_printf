#include "ft_printf.h"

static int		ft_len(unsigned int x)
{
	int				i;

	i = 0;
	while (x > 0)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

static void	ft_hexadecimal(unsigned int x, int *ret, s_flag *a, int c)
{
	unsigned long long i;

	i = x;
	if (i > 16)
	{
		ft_hexadecimal(i / 16, ret, a, c);
		ft_hexadecimal(i % 16, ret, a, c);
	}
	else
	{
		if (i < 10)
			ft_putchar(i + 48, ret);
		if (i >= 10 && c == 2)
			ft_putchar(i + 55, ret);
		if (i >= 10 && c == 1)
			ft_putchar(i + 87, ret);
	}
}

void	ft_fill(s_flag *a, long int filler, int *ret)
{
	while (filler > 0)
	{
		if (a->zero > 0 && a->dot < 0 && a->minus == 0)
			ft_putchar('0', ret);
		else
			ft_putchar(' ', ret);
		filler--;
	}
}

int		ft_printfX(va_list ap, int *ret, s_flag *a, int c)
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
		ft_fill(a, filler, ret);
	while (len < a->dot)
	{
		ft_putchar('0', ret);
		len++;
	}
	if (!(x == 0 && a->dot >= 0))
		ft_hexadecimal(x, ret, a, c);
	if (a->minus > 0)
		ft_fill(a, filler, ret);
	return (1);
}
