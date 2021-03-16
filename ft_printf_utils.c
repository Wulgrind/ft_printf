#include "ft_printf.h"

char	*ft_stdrup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
	   return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

int		ft_flags(va_list ap, int *ret, char *str, s_flag *a, int *i)
{
	while (str[i])
	{
		if (str[*i] == 'm')
			continue;
		else if (str[*i] == '0')
			a->zero = 1;
		else if (str[*i] == '-')
			a->minus = 1;
		else if (!ft_isdigit(str[*i]) && a->width == 0)
			a->width = ft_width(str, i);
		else if (str[*i] == '*')
			a->width = ft_star(str, ap, i);
		else if (str[*i] == '.')
			a->dot = ft_dot(str, i);
		else if (a->minus == 1)
			a->zero = 0;
		else if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd'
				|| str[*i] == 'i' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X'
				|| str[*i] == '%')
		{
			ft_type(ap, ret, str, a, i);
			return (1);
		}
		else
			return (1);
		(*i)++;
	}
	return (1);
}

void	ft_putchar(char c, int *ret)
{
	write (1, &c, 1);
	(*ret)++;
}

void	ft_putnbr(int d, int *ret)
{
	long int	c;

	c = d;
	if (c < 0)
	{
		ft_putchar('-', ret);
		c = -c;
	}
	if (c > 9)
	{
		ft_putnbr(c / 10, ret);
		ft_putnbr(c % 10, ret);
	}
	else
	{
		ft_putchar(c + '0', ret);
	}
}

void	ft_putstr(char *s, int *ret, s_flag *a)
{
	int	width;
	int	dot;
	int	len;
	
	width = 0;
	dot = 0;
	len = ft_strlen(s);
	if (a->dot > 0)
	{
		dot = a->dot;
	}
	if (a->width > 0)
	{
		width = a->width;
		while (len > width)
			width++;
	}
	ft_writestr(s, ret, a, width, dot, len);
}
