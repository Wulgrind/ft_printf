#include "libft.h"

void	ft_putdbl(unsigned double u, int *ret, s_flag *a);
void	ft_len(unsigned double u);
void	ft_writedbl(unsigned double u, int *ret);

void	ft_printfU(va_list ap, int *ret, s_flag *a)
{
	unsigned double	u;
	
	u = (unsigned double) va_arg(ap, unsigned int);
	ft_putdbl(u, ret, a)
}

void	ft_putdbl(unsigned double u, int *ret, s_flag *a)
{
	int	i;
	int	hole;

	hole = 0;
	i = ft_len(u);
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

int		ft_len(unsigned double u)
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

void	ft_writedbl(unsigned double u, int *ret)
{
	long unsigned double nb;

	nb = u;
	while (nb > 9)
	{
		ft_writedbl(u / 10, ret);
		ft_writedbl(u % 10, ret);
	}
	else
		ft_putchar(u + '0', ret);
}
