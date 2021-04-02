#include "ft_printf.h"

int	ft_lenU(unsigned int u)
{
	int	len;

	len = 0;
	while (u > 0)
	{
		u = u / 10;
		len++;
	}
	return (len);
}
