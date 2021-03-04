#include "ft_printf.h"

void	ft_printfS(va_list ap, int *ret, char *str, s_flag *a)
{
	va_list	ap2;
	char	*s;

	s = (char *) va_copy(ap2, ap);
	ft_putstr(char *s, int *ret, s_flag *a);
	va_end(ap2);
}
