#include "ft_printf.h"

int	ft_dot(char *str, va_list ap, static int *i)
{
	int	j;

	j = 0;
	(*i)++;
	if (str[*i] == 'm')
		(*i)++;
	
}

