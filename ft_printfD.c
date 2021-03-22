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

int	ft_putdbl(int d, int *ret, s_flag *a)
{
	int		i;
	int		j;
	char	*str;

	i = ft_len(d);
	j = i;
	while (j < a->dot)
		j++;
	while (j < a->width)
		j++;
	if (!(str = malloc(sizeof(j + 1))))
		return (0);
	str[j + 1] = '\0';
	ft_writedbl(d, ret, i , j, str, a);
	return (1);
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

int	ft_writedbl(int d, int *ret, int i, int j, char *str, s_flag *a)
{
	int	s;

	s = 0;
	if (a->zero == 0 && a->minus == 0)
	{
		while (j > i)
		{
			ft_putchar('0', ret);
			j--;
		}
		if (d < 0)
		{
			ft_putchar('-', ret);
			d = d * -1;
		}
		while (d > 0)
		{
			str[s] = 48 + (d % 10);
			d = d / 10;
			s++;
		}
		while (s >= 0)
		{
			ft_putchar(str[s], ret);
			s--;
		}
	}
	else if (a->zero > 0 || a->minus > 0)
	{
		if (d < 0)
		{
			ft_putchar ('-', ret);
			d = d * -1;
		}
		while (d > 0)
		{
			str[s] = 48 + (d % 10);
			d = d / 10;
			s++;
		}
		while (s < 0)
		{
			ft_putchar (str[s], ret);
			s--;
		}
		while (j > i)
		{
			ft_putchar('0', ret);
			j--;
		}
	}
	return (1);
}
