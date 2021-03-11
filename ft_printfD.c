#include "ft_printf.h"

int		ft_len(signed double d);
void	ft_writedbl(signed double d, int *ret);

void	ft_printfD(va_list ap,  int *ret, s_flag *a)
{
	signed double	d;

	d = (signed double) va_arg(ap, int);
	ft_putdbl(d, ret, a);
}

void	ft_putdbl(signed double d, int *ret, s_flag *a)
{
	int					i;
	int					hole;

	hole = 0;
	i = ft_len(d);
	if (a->dot < 0)
		a->dot = 1;
	while (i < dot)
		hole++;
	while (i + hole > a->width)
		width++;
	while (i + hole < a->width)
		hole++;
	if (a->minus == 0 && a->zero == 0)
	{
		ft_writedbl(d, ret);
		while (hole-- > 0)
			ft_putchar(' ', ret);
	}
	if (a->minus > 0 || a->zero > 0)
	{
		while (hole-- > 0)
		{
			if (a->minus > 0)
				ft_putchar(' ', ret);
			if (a->zero > 0)
				ft_putchar('0', ret);
		}
		ft_writedbl(d, ret);
	}
}

int		ft_len(signed double d)
{
	int	len;

	len = 0;
	if (d < 0)
	{
		d = d * -1;
		len++;
	}
	while (d > 0)
	{
		d = d / 10;
		len ++;
	}
	return (len);
}

void	ft_writedbl(signed double d, int *ret)
{
	long signed double nb;

	nb = d;
	if (nb < 0)
	{
		ft_putchar('-', ret);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_writedbl(nb / 10, ret);
		ft_writedbl(nb % 10, ret);
	}
	else
	{
		ft_putchar(nb + '0', ret);
	}
}
