#include "ft_printf.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (1);
		i++;
	}
	if (i > 0)
		return (1);
	return (0);
}

int	ft_dot(char *str, int *i, va_list ap)
{
	int	j;

	j = 0;
	(*i)++;
	if (!ft_isdigit(str[*i]) || str[*i] == '-')
		j = ft_width(str, i);
	else if (str[*i] == '*')
		j = ft_nextdot(ap);
	else
		(*i)--;
	if (j < 0)
		j = -1;
	return (j);
}

void	ft_type(va_list ap, char *str, s_flag *a, int *i)
{
	int	x;

	if (str[*i] == 'c')
		ft_printfC(ap, a);
	if (str[*i] == 's')
		ft_printfS(ap, a);
	if (str[*i] == 'p')
		ft_printfP(ap, a);
	if (str[*i] == 'd' || str[*i] == 'i')
		ft_printfD(ap, a);
	if (str[*i] == 'u')
		ft_printfU(ap, a);
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		if (str[*i] == 'x')
			x = 1;
		if (str[*i] == 'X')
			x = 2;
		ft_printfX(ap, a, x);
	}
	if (str[*i] == '%')
		ft_putchar('%', a);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstrlen(char *str, s_flag *a, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar(str[i], a);
		i++;
	}
}
