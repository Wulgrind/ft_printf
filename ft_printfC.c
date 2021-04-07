/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai </var/mail/qbrillai>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:18:55 by qbrillai          #+#    #+#             */
/*   Updated: 2021/04/07 17:18:58 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_filler(t_flag *a, int len);

void	ft_printfC(va_list ap, t_flag *a)
{
	int	c;
	int	len;

	len = 1;
	c = (char) va_arg(ap, int);
	if (a->dot > 0)
		while (len + a->width > a->dot)
			(a->width)--;
	if (a->zero == 0 && a->minus == 0)
	{
		while (len < a->width && a->width != 1)
		{
			ft_putchar(' ', a);
			len++;
		}
	}
	ft_putchar(c, a);
	if (a->zero > 0 || a->minus > 0)
		ft_filler(a, len);
}

static void	ft_filler(t_flag *a, int len)
{
	while (len < a->width)
	{
		if (a->minus > 0)
			ft_putchar(' ', a);
		if (a->zero > 0 && a->minus == 0)
			ft_putchar('0', a);
		len++;
	}
}
