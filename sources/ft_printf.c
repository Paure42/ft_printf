/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 16:36:22 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 12:59:20 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

int				ft_free(char *str)
{
	free(str);
	str = NULL;
	return (1);
}

static t_params	init(int n)
{
	t_params par;

	par.negative = 0;
	par.zero = 0;
	par.point = 0;
	par.plus = 0;
	par.hash = 0;
	par.alloc = 32;
	if (n == 0)
		par.pos = 0;
	else
		par.pos = n;
	par.error = 0;
	par.field = 0;
	par.prec = 0;
	par.is_int = 0;
	par.is_str = 0;
	par.is_char = 0;
	par.str = NULL;
	par.ret = 0;
	par.sp = 0;
	return (par);
}

static t_params	init2(t_params par, int n, int ret)
{
	par.negative = 0;
	par.zero = 0;
	par.point = 0;
	par.plus = 0;
	par.hash = 0;
	par.alloc = 32;
	if (n == 0)
		par.pos = 0;
	else
		par.pos = n;
	par.error = 0;
	par.field = 0;
	par.prec = 0;
	par.is_int = 0;
	par.is_str = 0;
	par.is_char = 0;
	par.str = NULL;
	par.ret = ret;
	par.sp = 0;
	return (par);
}

t_params		ft_asprintf(char *format, t_params par)
{
	while (format[par.pos])
	{
		if (!par.str)
			if (!(par.str = ft_calloc(par.alloc + 1, sizeof(char))))
			{
				par.error = 1;
				return (par);
			}
		if (par.error == 0)
		{
			par = ft_printf_write(format, par);
			par = ft_printf_rules(format, par);
			par = ft_printf_padding(par);
			if (par.str && par.error == 0)
			{
				write(1, (unsigned char *)par.str,
						ft_strlen(par.str) + par.is_char);
				par.ret += ft_strlen(par.str) + par.sp + par.is_char;
				free(par.str);
			}
			par = init2(par, par.pos, par.ret);
		}
	}
	return (par);
}

int				ft_printf(const char *format, ...)
{
	t_params	par;

	if (!format)
		return (-1);
	par = init(0);
	va_start(par.list_arg, format);
	par = ft_asprintf((char*)format, par);
	va_end(par.list_arg);
	if (par.error == 1)
	{
		if (par.str != NULL)
			free(par.str);
		return (-1);
	}
	else
		return (par.ret);
}
