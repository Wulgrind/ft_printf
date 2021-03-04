#include "ft_printf.h"

int		ft_dot(char *str, va_list ap, static int *i)
{
	int	j;

	j = 0;
	(*i)++;
	if (!ft_isdigit(str[*i]))
		j = ft_width(str, i);
	if (str[*i] == '.')
	j = 0;   
	return (j);
}

void	ft_type(va_list ap, int *ret, char *str, s_flag *a, static int *i)
{
	if (str[*i] == 'c')
		ft_printfC(va_list ap, int *ret, char *str, s_flag *a);
	if (str[*i] == 's')
		ft_printfS(va_list ap, int *ret, char *str, s_flag *a);
	
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_writestr(char *s, int *ret, s_flag *a, int width, int dot, int j)
{
	int	i;

	i = 0;
	if (a->minus > 0)
		while (s[i] != '\0' && 
}
