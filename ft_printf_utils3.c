#include "ft_printf.h"

int		ft_dot(char *str, va_list ap, static int *i)
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

void	ft_type(va_list ap, int *ret, char *str, s_flag *a, static int *i)
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
		ft_printfX(ap, ret, a, &x);
	}
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_writestr(char *s, int *ret, s_flag *a, int width, int dot, int len)
{
	int	i;

	i = 0;
	if (dot > -1)
	{
		if (a->minus > 0)
		{
			while (i++ <= len && i <= width && i <= dot)
				ft_putchar(s[i], ret);
			while (i++ <= width && i <= dot)
				ft_putchar(' ', ret);
		}
		else
		{
			while (width-- > len && width > dot)
				ft_putchar(' ', ret);
			while (i++ < len && i < width && i < dot)
				ft_putchar(s[i], ret);
		}
	}
	if (dot = -1)
		if (a->minus > 0)
		{
			while (i++ <= len && i <= width)
				ft_putchar(s[i], ret);
			while (i++ < len && i < width)
				ft_putchar(s[i], ret);
		}
}
