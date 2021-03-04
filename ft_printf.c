#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	static int	i;
	char		*str;
	s_flag		a;

	ret = 0;
	i = 0;
	va_start(ap, format);
	str = ft_stdrup(format);
	while (str[i++])
	{
			if (str[i] == '%')
			{
				va_arg(ap, type);
				ft_flags(ap, &ret, str, &a, &i);
			}
			else
				ft_putchar(str[i], &ret);
	}
	va_end(ap);
	i = 0;
	return (ret);
}

int	main()
{
	
}
