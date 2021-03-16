#include "ft_printf.h"

static void	ft_putdbl(unsigned int u, int *ret, s_flag *a);
static int	ft_len(unsigned int u);
static void	ft_writedbl(unsigned int u, int *ret);

void	ft_printfU(va_list ap, int *ret, s_flag *a)
{
	unsigned int	u;
	
	u = (unsigned int) va_arg(ap, unsigned int);
	ft_putdbl(u, ret, a);
}

static void	ft_putdbl(unsigned int u, int *ret, s_flag *a)
{
	int	i;
	int	hole;

	hole = 0;
	i = ft_len(u);
	if (a->dot < 0)
		a->dot = 1;
	while (i < a->dot)
		hole++;
	while (i + hole > a->width)
		a->width++;
	while (i + hole < a->width)
		hole++;
	if (a->minus == 0 && a->zero == 0)
	{
		ft_writedbl(u, ret);
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
		ft_writedbl(u, ret);
	}
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

static void	ft_writedbl(unsigned int u, int *ret)
{
	long unsigned int nb;

	nb = u;
	while (nb > 9)
	{
		ft_writedbl(u / 10, ret);
		ft_writedbl(u % 10, ret);
	}
	if (nb < 9)
		ft_putchar(u + '0', ret);
}
