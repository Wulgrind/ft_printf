#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	int			i;
	char		*str;
	s_flag		a;

	ret = 0;
	i = 0;
	va_start(ap, format);
	str = ft_stdrup(format);
	if(!(ft_check(str)))
	{
		write(1, "Wrong format", 12);
		return (0);
	}
	while (str[i])
	{
			if (str[i] == '%')
			{
				ft_initflags(&a, ap);
				ft_flags(ap, &ret, str, &a, &i);
			}
			else
				ft_putchar(str[i], &ret);
			i++;
	}
	va_end(ap);
	return (ret);
}

#include <stdio.h>

int	main()
{
	int	i = 16;
	ft_printf("%x", i);
	write(1, "\n", i);
	printf("%x", i);
}
