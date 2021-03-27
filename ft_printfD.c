#include "ft_printf.h"

int		ft_len(int d);
int		ft_writedbl(int d, int *ret, int i, int j, char *str, s_flag *a);
int	ft_putdbl(int d, int *ret, s_flag *a);

void	ft_printfD(va_list ap,  int *ret, s_flag *a)
{
	int	d;

	d = (int) va_arg(ap, int);
	ft_putdbl(d, ret, a);
}

static void ft_fill(s_flag *a, int filler, int *ret)
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

int	ft_putdbl(int d, int *ret, s_flag *a)
{
	int		len;
	int		filler;

	filler = 0;
	if (a->dot >= 0)
		a->zero = 0;
	len = ft_len(d);
	if (a->width > a->dot && len <= a->dot)
		filler = a->width - a->dot;
	if (a->width > len && a->dot < len)
		filler = a->width - len;
	if (a->minus == 0 && a->zero == 0)
		ft_fill(a, filler, ret);
	if (d < 0)
	{
		ft_putchar('-', ret);
		d = -d;
	}
	while (len < a->dot)
	{
		ft_putchar('0', ret);
		len++;
	}
	if (!(d == 0 && a->dot >= 0))
		ft_putnbr(d, ret, a);
	if (a->minus > 0 || a->zero > 0)
		ft_fill(a, filler, ret);
	return (1);
}

int		ft_len(int d)
{
	int	len;

	len = 0;
	if (d < 0)
	{
		d = -d;
	}
	while (d > 0)
	{
		d = d / 10;
		len++;
	}
	return (len);
}
