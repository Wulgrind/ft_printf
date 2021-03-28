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
				ft_initflags(&a);
				ft_flags(ap, &ret, str, &a, &i);
			}
			else
				ft_putchar(str[i], &ret);
			i++;
	}
	va_end(ap);
	free(str);
	return (ret);
}

 #include <stdio.h>

/*int	main()
{
	int i;
	int	j;

	i = ft_printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, 32767, 21, -32767);
	write(1, "\n", 1);
	j = printf(" --0*%0*.0i*0 0*%0*.10i*0-- ", -21, 32767, 21, -32767);
	write(1, "\n", 1);
	printf("%i", i);
	write(1, "\n", 1);
	printf("%i", j);
}*/

int	main()
{
	int i;
	int j;
	
	i = ft_printf(" %-3.2u %10.42u ", 1, -1);
	write(1, "\n", 1);
	j = printf(" %-3.2u %10.42u ", 1, -1);
	printf("\n%i\n%i", i , j);
}
