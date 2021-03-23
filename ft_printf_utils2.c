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

int	ft_star(char *str, va_list ap, int *i)
{
	int	j;

	j = 0;
	(*i)++;
	if (!ft_isdigit(str[*i]))
		j = ft_nextarg(ap);
	(*i)--;
	return (j);
}

int	ft_nextarg(va_list ap)
{
	int		i;
	va_list	ap2;

	i = 0;
	va_copy(ap2, ap);
	i = va_arg(ap2, int);
	va_end(ap2);
	return (i);
}
