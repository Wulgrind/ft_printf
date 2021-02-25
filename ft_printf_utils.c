#include "ft_printf.h"

char	*stdrup(char	*src)
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

int		ft_flags(va_list ap, int *ret, char *str, s_flag *a)
{
	int	i;

	i = 0;
	while (str[i] != '%' && str[i])
	{
		i++;
	}
	while (str[i++])
	{
		if (str[i] == '0')
			a->zero = 1;
		if (str[i] == '-')
			a->minus = 1;
		if (!ft_isdigit(str[i]) && str[i -1] != 'm')
			a->width = ft_width(str);
		if (str[i] == '*')
			a->width = ft_star(str, ap);

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

void	ft_putstr(char *s, int *ret)
{
	int	i;
	
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], ret);
		i++;
	}
}
