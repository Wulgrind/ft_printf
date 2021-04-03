#include "ft_printf.h"

int	ft_lenU(unsigned int u, t_flag *a)
{
	int	len;

	len = 0;
	if (u == 0 && a->dot != 0)
		len++;
	while (u > 0)
	{
		u = u / 10;
		len++;
	}
	return (len);
}
