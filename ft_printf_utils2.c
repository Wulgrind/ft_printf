#include "ft_printf.h"

int	ft_isdigit(char c)
{
	if (c >= 1 && c <= 9)
		return (0);
	return (1);
}

int ft_width(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '%' && str[i])
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (!ft_isdigit(str[i++]))
	{
		j = j * 10;
		j += str[i] - '0';
	}
	return (j);
}

int	ft_star(char *str, va_list ap)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '%' && str[i])
		i++;
	while (str[i] != '*' && str[i])
		i++;
	i++;
	if (str[i] == 'm')
		i++;
	if (ft_isdigit(str[i]))
		j = ft_nextarg(str, ap);
	if (!ft_isdigit(str[i]))
		j = ft_narg(str, ap);
}

int	ft_nextarg(char *str, va_list ap)
{
	int		i;
	va_list	ap2;

	i = 0;
	va_copy(ap2, ap);
	i = va_arg(ap2, int);
	va_end(ap2);
	return (i);
}

int	ft_narg(char *str, va_list ap)
{
	va_list	ap2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_copy(ap2, ap);

}
