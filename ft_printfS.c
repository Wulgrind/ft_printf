#include "ft_printf.h"

static	int	ft_lens(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_treatminus(s_flag *a, int len)
{
	if (a->minus > 0 || a->zero > 0)
	{
		while (len < a->width)
		{
			if (a->minus > 0)
				ft_putchar(' ', a);
			if (a->zero > 0 && a->minus == 0)
				ft_putchar('0', a);
			len++;
		}
	}
}

void	ft_printfS2(s_flag *a, int len, char *str)
{
	if (a->dot >= 0)
		while (len > a->dot)
			len--;
	if (a->dot <= -1)
		ft_putstr(str, a);
	if (a->dot >= 0)
		ft_putstrlen(str, a, len);
	ft_treatminus(a, len);
}

void	ft_printfS(va_list ap, s_flag *a)
{
	char	*str;
	int		len;

	len = 0;
	str = (char *) va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_lens(str);
	if (a->dot < -1)
		a->dot = -1;
	if (a->dot >= 0)
		while (len > a->dot)
			len--;
	if (a->minus == 0 && a->zero == 0)
	{
		while (len < a->width)
		{
			ft_putchar(' ', a);
			len++;
		}
	}
	ft_printfS2(a, len, str);
}
