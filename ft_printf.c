#include "ft_printf.h"

void	ft_printf2(va_list ap, int *i, char *str, t_flag *a);

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	int			i;
	char		*str;
	t_flag		a;

	ret = 0;
	i = 0;
	va_start(ap, format);
	str = ft_stdrup(format);
	if (!(ft_check (str)))
	{
		free(str);
		return (0);
	}
	a.ret = 0;
	ft_printf2(ap, &i, str, &a);
	va_end(ap);
	free(str);
	ret = a.ret;
	return (ret);
}

void	ft_printf2(va_list ap, int *i, char *str, t_flag *a)
{
	while (str[*i])
	{
		if (str[*i] == '%')
		{
			ft_initflags(a);
			ft_flags(ap, str, a, i);
		}
		else
			ft_putchar(str[*i], a);
		(*i)++;
	}
}

#include <stdio.h>
/*
int	main()
{
	int i = 0;
	int j = 0;
	i = ft_printf("%-.2x", 0);
	printf("\n");
	j = printf("%-.2x", 0);
	printf("\n%i\n%i", i, j);
}*/
