#include "ft_printf.h"

void	ft_printfS(va_list ap, int *ret, s_flag *a)
{
	char	*s;

	s = (char *) va_arg(ap, char *);
	ft_putstr(s, ret, a);
}
