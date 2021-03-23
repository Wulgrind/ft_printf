#include "ft_printf.h"

void	ft_initflags(s_flag *a, va_list ap)
{
	a->zero = 0;
	a->minus = 0;
	a->dot = -1;
	a->star = 0;
	a->width = 0;
}
