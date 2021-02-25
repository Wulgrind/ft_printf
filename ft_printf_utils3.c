#include "ft_printf.h"

int	ft_dot(char *str, va_list ap, static int *i)
{
	int	j;

	j = 0;
	(*i)++;
	if (!ft_isdigit(str[*i]))
	{
		j = ft_width(str, i);
	}
	if (str[*i], 
	return (j);
}

