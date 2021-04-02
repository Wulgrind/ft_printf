#include "ft_printf.h"

int	ft_checktype(char i)
{
	if (i == 'c' || i == 's' || i == 'p'
		|| i == 'd' || i == 'i'
		|| i == 'u' || i == 'x'
		|| i == 'X' || i == '%')
		return (0);
	else
		return (1);
}
