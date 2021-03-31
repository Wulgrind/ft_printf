#include "ft_printf.h"

int		ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_dot(char *str, int *i, va_list ap)
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

void	ft_type(va_list ap, int *ret, char *str, s_flag *a, int *i)
{
	int	x;

	if (str[*i] == 'c')
		ft_printfC(ap, ret, a);
	if (str[*i] == 's')
		ft_printfS(ap, ret, a);
	if (str[*i] == 'p')
		ft_printfP(ap, ret, a);
	if (str[*i] == 'd' || str[*i] == 'i')
		ft_printfD(ap, ret, a);
	if (str[*i] == 'u')
		ft_printfU(ap, ret, a);
	if (str[*i] == 'x' || str[*i] == 'X')
	{
		if (str[*i] == 'x')
			x = 1;
		if (str[*i] == 'X')
			x = 2;
		ft_printfX(ap, ret, a, x);
	}
	if (str[*i] == '%')
		ft_putchar('%', ret);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstrlen(char *str, int *ret, int len)
{
	int	i;

	i = 0;
	while(str[i] && i < len)
	{
		ft_putchar(str[i], ret);
		i++;
	}
}
