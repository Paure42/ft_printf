/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_read_bonus.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 17:05:18 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 13:26:06 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static	t_params	ft_printf_ll_hh(char *format, t_params par)
{
	char c;

	c = format[par.pos + 2];
	if (format[par.pos + 1] == 'l')
	{
		if ((c == 'd' || c == 'i') && par.pos++)
			par = ft_printf_ldi(par);
		else if ((c == 'x' || c == 'X') && par.pos++)
			par = ft_printf_lx(par, format);
		else if (c == 'u' && par.pos++)
			par = ft_printf_lu(par);
	}
	else if (format[par.pos + 1] == 'h')
	{
		if ((c == 'd' || c == 'i') && par.pos++)
			par = ft_printf_hdi(par);
		else if ((c == 'x' || c == 'X') && par.pos++)
			par = ft_printf_hx(par, format);
		else if (c == 'u' && par.pos++)
			par = ft_printf_hu(par);
	}
	return (par);
}

t_params			ft_printf_conv_bonus(char *format, t_params par)
{
	if (format[par.pos] == 'l')
	{
		if (format[par.pos + 1] == 'd' || format[par.pos + 1] == 'i')
			par = ft_printf_ldi(par);
		else if (format[par.pos + 1] == 'x' || format[par.pos + 1] == 'X')
			par = ft_printf_lx(par, format);
		else if (format[par.pos + 1] == 'u')
			par = ft_printf_lu(par);
		else if (format[par.pos + 1] == 'l')
			par = ft_printf_ll_hh(format, par);
	}
	else if (format[par.pos] == 'h')
	{
		if (format[par.pos + 1] == 'd' || format[par.pos + 1] == 'i')
			par = ft_printf_hdi(par);
		else if (format[par.pos + 1] == 'x' || format[par.pos + 1] == 'X')
			par = ft_printf_hx(par, format);
		else if (format[par.pos + 1] == 'u')
			par = ft_printf_hu(par);
		else if (format[par.pos + 1] == 'h')
			par = ft_printf_ll_hh(format, par);
	}
	par.pos++;
	return (par);
}
