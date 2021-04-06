/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_convert_bonus.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 12:03:58 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 13:26:46 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_params	ft_printf_n(t_params par)
{
	int	*i;

	i = va_arg(par.list_arg, int*);
	*i = par.ret;
	return (par);
}

t_params	ft_printf_ldi(t_params par)
{
	char	*tmp;
	size_t	i;

	tmp = ft_lltoa(va_arg(par.list_arg, long));
	i = ft_strlen(tmp);
	if (par.sp == 1 && tmp[0] != '-' && par.plus == 0 && ((size_t)par.field <= i
				|| par.zero == 1 || par.negative == 1 || par.prec > (long)i))
		write(1, " ", 1);
	else
		par.sp = 0;
	if (i >= par.alloc + 1)
		if (!(par.str = ft_realloc(par.str, par.alloc + 1, par.alloc + i + 1)))
		{
			par.error = 1;
			ft_free(tmp);
			return (par);
		}
	if (par.plus == 1 && tmp[0] != '-')
		par.str[0] = '+';
	par.str = ft_strncat(par.str, tmp, i);
	par.is_int = 1;
	ft_free(tmp);
	return (par);
}

t_params	ft_printf_hdi(t_params par)
{
	char	*tmp;
	size_t	i;

	tmp = ft_stoa((short)va_arg(par.list_arg, int));
	i = ft_strlen(tmp);
	if (par.sp == 1 && tmp[0] != '-' && par.plus == 0 && ((size_t)par.field <= i
				|| par.zero == 1 || par.negative == 1 || par.prec > (long)i))
		write(1, " ", 1);
	else
		par.sp = 0;
	if (i >= par.alloc + 1)
		if (!(par.str = ft_realloc(par.str, par.alloc + 1, par.alloc + i + 1)))
		{
			par.error = 1;
			ft_free(tmp);
			return (par);
		}
	if (par.plus == 1 && tmp[0] != '-')
		par.str[0] = '+';
	par.str = ft_strncat(par.str, tmp, i);
	par.is_int = 1;
	ft_free(tmp);
	return (par);
}

t_params	ft_printf_lx(t_params par, char *format)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	if (format[par.pos + 1] == 'x')
		tmp = ft_lltoa_base(va_arg(par.list_arg, long), "0123456789abcdef");
	else if (format[par.pos + 1] == 'X')
		tmp = ft_lltoa_base(va_arg(par.list_arg, long), "0123456789ABCDEF");
	if ((i = ft_strlen(tmp)) >= par.alloc + 1)
		if (!(par.str = ft_realloc(par.str, par.alloc + 1, par.alloc + i + 1)))
		{
			par.error = 1;
			ft_free(tmp);
			return (par);
		}
	ft_strncat(par.str, tmp, i);
	ft_free(tmp);
	if (par.hash == 1 && par.str[0] && par.str[0] != '0')
		par = ft_printf_hash(par, format[par.pos + 1]);
	else
		par.hash = 0;
	if (par.str[0] == '0' && par.prec <= 0 && par.point == 1)
		par.str[0] = '\0';
	par.is_int = 1;
	return (par);
}

t_params	ft_printf_hx(t_params par, char *format)
{
	char	*tmp;
	size_t	i;

	tmp = NULL;
	if (format[par.pos + 1] == 'x')
		tmp = ft_ustoa_base((unsigned short)va_arg(par.list_arg, int),
				"0123456789abcdef");
	else if (format[par.pos + 1] == 'X')
		tmp = ft_ustoa_base((unsigned short)va_arg(par.list_arg, int),
				"0123456789ABCDEF");
	if ((i = ft_strlen(tmp)) >= par.alloc + 1)
		if (!(par.str = ft_realloc(par.str, par.alloc + 1, par.alloc + i + 1))
				&& (par.error = 1) == 1 && ft_free(tmp))
			return (par);
	ft_strncat(par.str, tmp, i);
	ft_free(tmp);
	if (par.hash == 1 && par.str[0] && par.str[0] != '0')
		par = ft_printf_hash(par, format[par.pos + 1]);
	else
		par.hash = 0;
	if (par.str[0] == '0' && par.prec <= 0 && par.point == 1)
		par.str[0] = '\0';
	par.is_int = 1;
	return (par);
}
