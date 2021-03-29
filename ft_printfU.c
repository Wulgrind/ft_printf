#include "ft_printf.h"

static int	ft_putdbl(unsigned int u, int *ret, s_flag *a);
static int	ft_len(unsigned int u);

void	ft_printfU(va_list ap, int *ret, s_flag *a)
{
	unsigned int	u;
	
	u = va_arg(ap, unsigned int);
	ft_putdbl(u, ret, a);
}

static void	ft_fill(s_flag *a, long int filler, int *ret)
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

static int	ft_putdbl(unsigned int u, int *ret, s_flag *a)
{
	long int	len;
	long int	filler;

	filler = 0;
	if (a->dot > 0)
		a-> zero = 0;
	len = ft_len(u);
	if (a->width > a->dot && len <= a->dot)
		filler = a->width - a->dot;
	if (a->width > len && a->dot < len)
		filler = a->width - len;
	if (u < 0)
		filler--;
	if (a->minus == 0)
		ft_fill(a, filler, ret);
	while (len < a->dot)
	{
		ft_putchar('0', ret);
		len++;
	}
	if (!(u == 0 && a->dot >= 0))
		ft_putnbr(u, ret, a);
	if (a->minus > 0)
		ft_fill(a, filler, ret);
	return (1);
}


static int		ft_len(unsigned int u)
{
	int	len;
	
	len = 0;
	while (u > 0)
	{
		u = u / 10;
		len++;
	}
	return (len);
}
