#include "ft_printf.h"

int		ft_l(unsigned long int x)
{
		int				i;
		unsigned int	j;

		i = 0;
		j = x;
		while (j > 16)
		{
			j /= 16;
			i++;
		}
		return (i);
}

void	ft_hexadecimal(char **s, unsigned long int x, s_flag *a, int hole, int len)
{
	int	temp;

	if (a->zero > 0 || a->minus > 0)
	{
		while (len-- > 0)
		{
			temp = x % 16;
			if (temp < 10)
				*s[hole + len + 2] = temp + 48;
			if (temp >= 10)
				*s[hole + len + 2] = temp + 55;
			x /= 16;
		}
	}
	if (a->zero == 0 || a->minus == 0)
	{
		while (len-- > 0)
		{
			temp = x % 16;
			if (temp < 10)
				*s[len + 2] = temp + 48;
			if (temp >= 10)
				*s[len + 2] = temp + 55;
			x /= 16;
		}
	}
}

char	*ft_createstr(unsigned long int x, s_flag *a, char *s, int hole, int len)
{
	int	i;

	i = 0;
	if (a->zero > 0 || a->minus > 0)
	{
		if (a->minus > 0)
			while (i < hole)
				s[i++] = ' ';
		else
			while (i < hole)
				s[i++] = '0';
		s[i++] = '0';
		s[i++] = 'X';
		ft_hexadecimal(&s, x, a, hole, len);
	}
	if (a->zero == 0 && a->minus == 0)
	{
		while (hole-- > 0)
			s[len + hole] = ' ';
		s[i++] = '0';
		s[i++] = 'X';
		ft_hexadecimal(&s, x, a, hole, len);
	}
	return (s);
}

int	ft_printfP(va_list ap, int *ret, s_flag *a)
{
	unsigned long int	*p;
	char				*s;
	unsigned long int	i;
	int					len;
	int 				hole;
	int					j;

	p = (unsigned long int *) va_arg(ap, void *);
	i = *p;
	j = 0;
	len = ft_l(i);
	if (a->dot > len)
		hole = a->dot - len;
	if (a->width > 0)
	{
		while (a->width < hole + len)
		a->width++;
		while ((hole + len) < a->width)
			hole++;
	}
	if (!(s = malloc(sizeof(hole + len + 3))))
		return (0);
	s[hole + len + 3] = '\0';
	s = ft_createstr(i, a, s, hole, len);
	while (s[j++] != '\0')
		ft_putchar(s[i], ret);
	return (1);
}
