#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if (c >= 1 && c <= 9)
		return (0);
	return (1);
}
