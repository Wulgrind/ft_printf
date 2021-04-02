#include "ft_printf.h"

int	ft_printfP2(t_flag *a, long int filler, unsigned long long x, long int len);

static void	ft_hexadecimal(unsigned long long x, t_flag *a)
{
	unsigned long long	i;

	i = x;
	if (i >= 16)
	{
		ft_hexadecimal(i / 16, a);
		ft_hexadecimal(i % 16, a);
	}
	else
	{
		if (i < 10)
			ft_putchar(i + 48, a);
		if (i >= 10)
			ft_putchar(i + 87, a);
	}
}

static void	ft_fill(t_flag *a, long int filler)
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

int	ft_lenP(unsigned long long x)
{
	int	i;

	i = 0;
	if (x == 0)
		i = 1;
	while (x > 0)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

int	ft_printfP(va_list ap, t_flag *a)
{
	unsigned long long	x;
	long int			len;
	long int			filler;

	filler = 0;
	x = (unsigned long long) va_arg(ap, unsigned long long);
	if (a->dot > 0)
		a->zero = 0;
	len = ft_lenP(x) + 2;
	if (a->width > a->dot && len <= a->dot)
		filler = a->width - a->dot;
	if (a->width > len && a->dot < len)
		filler = a->width - len;
	ft_printfP2(a, filler, x, len);
	return (1);
}

int	ft_printfP2(t_flag *a, long int filler, unsigned long long x, long int len)
{
	if (a->minus == 0)
		ft_fill(a, filler);
	while (len < a->dot)
	{
		ft_putchar('0', a);
		len++;
	}
	if (!(x == 0 && a->dot >= 0))
	{
		ft_putchar('0', a);
		ft_putchar('x', a);
		ft_hexadecimal(x, a);
	}
	if (a->minus > 0)
		ft_fill (a, filler);
	return (1);
}
