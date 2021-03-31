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

void	ft_printfS(va_list ap, int *ret, s_flag *a)
{
	char	*str;
	int		len;

	len = 0;
	str = (char *) va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_len(str);
	if (a->dot < -1)
		a->dot = -1;
	if (a->dot >= 0)
		while (len > a->dot)
			len--;
	if (a->minus == 0 && a->zero == 0)
			while (len < a->width)
			{
				ft_putchar(' ', ret);
				len++;
			}
	if (a->dot >= 0)
		while(len > a->dot)
			len--;
	if (a->dot <= -1)
		ft_putstr(str, ret);
	if (a->dot >= 0)
		ft_putstrlen(str, ret, len);
	ft_treatminus(ret, a, len);
}
