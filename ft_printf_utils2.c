#include "ft_printf.h"

int	ft_len(unsigned int u)
{
	int	len;

	len = 0;
	while (u > 0)
	{
		u = u / 16;
		len++;
	}
	return (len);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int	ft_width(char *str, int *i)
{
	int	j;
	int	minus;

	j = 0;
	minus = 0;
	if (str[*i] == '-')
	{
		minus = 1;
		i++;
	}
	while (!ft_isdigit(str[*i]))
	{
		j = j * 10;
		j = j + (str[*i] - '0');
		(*i)++;
	}
	if (minus == 1)
		j = j * -1;
	(*i)--;
	return (j);
}

int	ft_nextdot(va_list ap)
{
	int	i;

	i = va_arg(ap, int);
	return (i);
}

int	ft_nextarg(va_list ap, s_flag *a)
{
	int		i;

	i = va_arg(ap, int);
	if (i < 0)
	{
		i = i * -1;
		a->minus = 1;
	}
	return (i);
}
