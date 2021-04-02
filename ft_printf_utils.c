#include "ft_printf.h"

char	*ft_stdrup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_flags(va_list ap, char *str, t_flag *a, int *i)
{
	while (str[(*i)++])
	{
		if (str[*i] == '0')
			a->zero = 1;
		else if (str[*i] == '-')
			a->minus = 1;
		else if (!ft_isdigit(str[*i]) && a->width == 0)
			a->width = ft_width(str, i);
		else if (str[*i] == '*')
		{
			a->width = ft_nextarg(ap, a);
			a->star = 1;
		}
		else if (str[*i] == '.')
			a->dot = ft_dot(str, i, ap);
		
		else if (!(ft_checktype(str[*i])))
		{
			ft_type(ap, str, a, i);
			return (1);
		}
		else
			return (1);
	}
	return (1);
}

void	ft_putchar(char c, t_flag *a)
{
	write (1, &c, 1);
	(a->ret)++;
}

void	ft_putnbr(int d, t_flag *a)
{
	long int	c;

	c = d;
	if (c < 0)
	{
		ft_putchar('-', a);
		c = -c;
	}
	if (c > 9)
	{
		ft_putnbr(c / 10, a);
		ft_putnbr(c % 10, a);
	}
	else 
	{
		ft_putchar(c + '0', a);
	}
}

void	ft_putstr(char *str, t_flag *a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], a);
		i++;
	}
}
