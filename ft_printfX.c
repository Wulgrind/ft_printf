#include "ft_printf.h"

static int		ft_len(unsigned int x)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = x;
	while (j >= 16)
	{
		j = (j / 16);
		i++;
	}
	return (i);
}

static int	ft_hexadecimal(unsigned int x,  int len, int c, int *ret)
{
	int		temp;
	char	*s;
	int		i;

	i = 0;
	if(!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len + 1] = '\0';
	while (len >= 0)
	{
		temp = x % 16;
		if (temp < 10)
			s[len] = temp + 48;
		if (temp >= 10 && c == 2)
			s[len] = temp + 55;
		if (temp >= 10 && c == 1)
			s[len] = temp + 87;
		x = (x / 16);
		len--;
	}
	while (s[i])
	{
		ft_putchar(s[i], ret);
		i++;
	}
	return (1);
}

int	ft_printfX(va_list ap, int *ret, s_flag *a, int c)
{
	unsigned int	x;
	int 			len;
	int				hole;
	
	hole = 0;
	x = (unsigned int) va_arg(ap, unsigned int);
	len = ft_len(x);
	while (a->width > (len + hole))
		hole++;
	while (a->dot > (len + hole))
		hole++;
	if (a->minus == 0 && a->zero == 0)
	{
		while (hole > 0)
		{
			ft_putchar(' ', ret);
		}
	}
	ft_hexadecimal(x,len, c, ret);
	if (a->minus > 0 || a->zero > 0)
	{
		while (hole > 0)
		{
			if (a->minus > 0)
				ft_putchar(' ', ret);
			if (a->minus == 0 && a->zero > 0)
				ft_putchar('0', ret);
			hole--;
		}
	}
	return (1);
}
