#include "ft_printf.h"

typedef struct	s_flag
{
	int		zero;
	int		dot;
	int		minus;
	char	type;
	int		star;
	int		width;
}				s_flag;
