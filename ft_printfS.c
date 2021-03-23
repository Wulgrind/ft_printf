#include "ft_printf.h"

static	int	ft_len(char	*str)
{
	int	i;
	
	i = 0;
	while(str[i])
		i++;
	return (i);
}

static void	ft_treatminus(int *ret, s_flag *a, int len)
{
	if (a->minus > 0 || a->zero > 0)
	{
		if (a->dot > 0)
		{
			while (len < a->width && len < a->dot)
			{
				if (a->minus > 0)
					ft_putchar(' ', ret);
				if (a->zero > 0 && a->minus == 0)
					ft_putchar('0', ret);
				len++;
			}
		}
		if (a->dot < 0)
		{
			while (len < a->width)
			{
				if (a->minus > 0)
					ft_putchar(' ', ret);
				if (a->zero > 0 && a->minus == 0)
					ft_putchar('0', ret);
				len++;
			}
		}
	}
}

void	ft_printfS(va_list ap, int *ret, s_flag *a)
{
	char	*str;
	int		len;

	len = 0;
	if (a->dot > 0)
		while (len > a->dot)
			len--;
	str = (char *) va_arg(ap, char *);
	len = ft_len(str);
	if (a->minus == 0 && a->zero == 0)
	{
		if (a->dot > 0)
			while (len < a->width && len < a->dot)
			{
				ft_putchar(' ', ret);
				len++;
			}
		if (a->dot < 0)
			while(len < a->width)
			{
				ft_putchar(' ',ret);
				len++;
			}
	}
	ft_putstr(str, ret);
	ft_treatminus(ret, a, len);
}
