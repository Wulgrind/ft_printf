#include "ft_printf.h"

int		ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] == '%')
			return (1);
	}
	return (0);
}

int		ft_dot(char *str, int *i)
{
	int	j;

	j = 0;
	(*i)++;
	if (!ft_isdigit(str[*i]))
		j = ft_width(str, i);
	if (str[*i] == '.')
	j = 0;   
	return (j);
}

void	ft_type(va_list ap, int *ret, char *str, s_flag *a, int *i)
{
	int	x;

	if (str[*i] == 'c')
		ft_printfC(ap, ret);
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

void	ft_writestr(char *s, int *ret, s_flag *a, int len)
{
	int	i;

	i = 0;
	if (a->dot > -1)
	{
		if (a->minus == 0)
		{
			while (i <= len && i <= a->width && i <= a->dot)
			{
				ft_putchar(s[i], ret);
				i++;
			}
			while (i <= a->width && i <= a->dot)
			{
				ft_putchar(' ', ret);
				i++;
			}
		}
		if (a->minus > 0)
		{
			while (a->width > len && a->dot > 0)
			{
				ft_putchar(' ', ret);
				a->width--;
				a->dot--;
			}
			while (i <= len && a->dot > 0)
			{
				ft_putchar(s[i], ret);
				i++;
				a->dot--;
			}
		}
	}
	if (a->dot == -1)
	{
		if (a->minus == 0)
		{
			while (i <= len && i <= a->width)
			{
				ft_putchar(s[i], ret);
				i++;
			}
			while (i <= a->width)
			{
			ft_putchar(' ', ret);
			}
		}
		if (a->minus > 0)
		{
			while (a->width > len)
			{
				ft_putchar(' ', ret);
				a->width--;
				a->dot--;
			}
			while (i <= len)
			{
				ft_putchar(s[i], ret);
				i++;
			}
		}
	}
}
