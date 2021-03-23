#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}

int ft_width(char *str, int *i)
{
	int	j;

	j = 0;
	while (!ft_isdigit(str[*i]))
	{
		j = j * 10;
		j = j + (str[*i] - '0');
		(*i)++;
	}
	(*i)--;
	return (j);
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
