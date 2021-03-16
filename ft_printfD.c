#include "ft_printf.h"

int		ft_len(int d);
int		ft_writedbl(int d, int *ret, int i);
void	ft_putdbl(int d, int *ret, s_flag *a);

void	ft_printfD(va_list ap,  int *ret, s_flag *a)
{
	int	d;

	d = (int) va_arg(ap, int);
	ft_putdbl(d, ret, a);
}

void	ft_putdbl(int d, int *ret, s_flag *a)
{
	int					i;
	int					hole;

	hole = 0;
	i = ft_len(d);
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
		ft_writedbl(d, ret, i);
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
		ft_writedbl(d, ret, i);
	}
}

int		ft_len(int d)
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

int	ft_writedbl(int d, int *ret, int i)
{
	char	*str;
	int		j;

	j = 0;
	if (!(str = malloc(sizeof(i + 1))))
		return (0);
	str[i + 1] = '\0';
	if (d < 0)
	{
		str[0] = '-';
		d = d * -1;
	}
	while (d > 0)
	{
		str[i] = d % 10;
		d = d / 10;
		i--;
	}
	while (str[j++])
		ft_putchar(str[j], ret);
	return (1);
}
