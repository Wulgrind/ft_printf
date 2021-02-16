#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int d)
{
	long int	c;

	c = d;
	if (c < 0)
	{
		ft_putchar('-');
		c = -c;
	}
	if (c > 9)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	else
		ft_putchar(c + '0');
}

void	ft_putstr(char *s)
{
	int	i;
	
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
