#include "ft_printf.h"

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
