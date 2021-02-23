#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		i;
	char	*str;
	s_flag	a;

	ret = 0;
	i = 0;
	va_start(ap, format);
	str = ft_stdrup(format);
	while (str[i++])
	{
			if (str[i] == '%')
			{
				va_arg(ap, type);

				ft_flags(ap, &ret, str, &a);
			}
			else
				ft_putstr(str[i], &ret);
	}
	va_end(ap);
	return (ret);
}

int	main()
{
	
}
