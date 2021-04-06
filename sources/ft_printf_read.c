/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_read.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/05 18:22:16 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 12:14:51 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_params	ft_printf_write(char *format, t_params par)
{
	int n;

	n = 0;
	while (format[par.pos] && format[par.pos] != '%')
	{
		n++;
		par.pos++;
	}
	if (n)
		write(1, format + (par.pos - n), n);
	par.ret += n;
	return (par);
}

t_params	ft_printf_field(char *format, t_params par)
{
	if (format[par.pos] >= '1' && format[par.pos] <= '9')
	{
		while (format[par.pos] &&
				(format[par.pos] >= '0' && format[par.pos] <= '9'))
		{
			par.field = par.field * 10 + (format[par.pos] - '0');
			par.pos++;
		}
	}
	return (par);
}

t_params	ft_printf_flags(char *format, t_params par)
{
	while (format[par.pos])
	{
		if (format[par.pos] == '-')
			par.negative = 1;
		else if (format[par.pos] == '0')
			par.zero = 1;
		else if (format[par.pos] == '.')
		{
			par.point = 1;
			par = ft_printf_prec(format, par);
		}
		else if (format[par.pos] == '+')
			par.plus = 1;
		else if (format[par.pos] == '#')
			par.hash = 1;
		else if (format[par.pos] == ' ')
			par.sp = 1;
		else
			break ;
		par.pos++;
	}
	return (par);
}

t_params	ft_printf_conv(char *format, t_params par)
{
	if (format[par.pos])
	{
		if (format[par.pos] == 'c')
			par = ft_printf_c(par);
		if (format[par.pos] == 's')
			par = ft_printf_s(par);
		if (format[par.pos] == 'p')
			par = ft_printf_p(par);
		if (format[par.pos] == 'd' || format[par.pos] == 'i')
			par = ft_printf_di(par);
		if (format[par.pos] == 'u')
			par = ft_printf_u(par);
		if (format[par.pos] == 'x' || format[par.pos] == 'X')
			par = ft_printf_x(par, format);
		if (format[par.pos] == 'n')
			par = ft_printf_n(par);
		if (format[par.pos] == 'l' || format[par.pos] == 'h')
			par = ft_printf_conv_bonus(format, par);
		par.pos++;
	}
	return (par);
}

t_params	ft_printf_padding(t_params par)
{
	int		i;

	if (par.point == 1)
		par = ft_printf_point(par);
	if (par.field > 0 && (i = par.field - ft_strlen(par.str) - par.is_char) > 0)
	{
		if (!(par.str = ft_realloc(par.str, ft_strlen(par.str),
						par.field + 1)) && (par.error = 1) == 1)
			return (par);
		if (par.zero == 1 && par.negative == 0 && par.field > 0 && i > 0)
			par = ft_printf_zero(par, i - par.sp);
		if ((par.negative == 1 || (par.field > 0 && par.zero == 0))
				&& par.field > 0 && i > 0)
			par = ft_printf_negative(par, i - par.sp);
		if (par.is_char == 1 && par.negative == 1)
		{
			par.is_char = ft_strlen(par.str);
			par.str[par.is_char] = ' ';
			par.str[0] = '\0';
			par.is_char++;
		}
	}
	return (par);
}
