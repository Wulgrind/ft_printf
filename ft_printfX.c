#include "ft_printf.h"

static int		ft_len(unsigned int x)
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

static void	ft_hexadecimal(char **s, unsigned int x, s_flag *a, int hole, int len, int c)
{
	int	temp;

	if (a->zero > 0 || a->minus > 0)
	{
		while (len-- > 0)
		{
			temp = x % 16;
			if (temp < 10)
				*s[hole + len] = temp + 48;
			if (temp >= 10 && c == 2)
				*s[hole + len] = temp + 55;
			if (temp >= 10 && c == 1)
				*s[hole + len] = temp + 87;
			x /= 16;
		}
	}
	if (a->zero == 0 || a->minus == 0)
	{
		while (len-- > 0)
		{
			temp = x % 16;
			if (temp < 10)
				*s[len] = temp + 48;
			if (temp >= 10 && c == 2)
				*s[len] = temp + 55;
			if (temp >= 10 && c == 1)
				*s[len] = temp + 87;
			x /= 16;
		}
	}
}

char	*ft_makestr(unsigned int x, s_flag *a, int c, char *s, int hole, int len)
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
		ft_hexadecimal(&s, x, a, hole, len, c);
	}
	if (a->zero == 0 && a->minus == 0)
	{
		while (hole-- > 0)
			s[len + hole] = ' ';
		ft_hexadecimal(&s, x, a, hole, len, c);
	}
	return (s);
}

int	ft_printfX(va_list ap, int *ret, s_flag *a, int c)
{
	unsigned int	x;
	char			*s;
	int 			len;
	int				hole;
	int				i;
	
	hole = 0;
	i = 0;
	x = (unsigned int) va_arg(ap, unsigned int);
	len = ft_len(x);
	if (a->dot > len)
	{
		hole = a->dot - len;
	}
	if (a->width > 0)
	{
		while (a->width < hole + len)
			a->width++;
		while ((hole + len) < a->width)
			hole++;
	}
	if (!(s = malloc(sizeof(hole + len + 1))))
		return (0);
	s[hole + len + 1] = '\0';
	s = ft_makestr(x, a, c, s, hole, len);
	while (s[i++] != '\0')
		ft_putchar(s[i], ret);
	return (1);
}
