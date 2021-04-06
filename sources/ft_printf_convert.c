/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_convert.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 19:10:45 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 17:40:23 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_params	ft_printf_c(t_params par)
{
	int				i;

	i = ft_strlen(par.str);
	par.str[i] = (unsigned char)va_arg(par.list_arg, int);
	if (par.str[i] == '\0')
		par.is_char = 1;
	return (par);
}

t_params	ft_printf_s(t_params par)
{
	size_t	i;
	char	*tmp;

	if (par.prec == -1 && va_arg(par.list_arg, char*))
		return (par);
	par.is_str = 1;
	if (!(tmp = va_arg(par.list_arg, char*)))
	{
		ft_strncat(par.str, "(null)", 6);
		return (par);
	}
	i = ft_strlen(tmp);
	if (i >= par.alloc + 1)
		if (!(par.str = ft_realloc(par.str, par.alloc + 1, par.alloc + i + 1)))
		{
			par.error = 1;
			ft_free(tmp);
			return (par);
		}
	par.str = ft_strncat(par.str, tmp, i);
	return (par);
}

t_params	ft_printf_di(t_params par)
{
	char	*tmp;
	size_t	i;

	tmp = ft_itoa(va_arg(par.list_arg, int));
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

t_params	ft_printf_u(t_params par)
{
	char	*tmp;
	size_t	i;

	tmp = ft_utoa(va_arg(par.list_arg, unsigned int));
	i = ft_strlen(tmp);
	if (i >= par.alloc + 1)
		if (!(par.str = ft_realloc(par.str, par.alloc + 1, par.alloc + i + 1)))
		{
			par.error = 1;
			ft_free(tmp);
			return (par);
		}
	par.str = ft_strncat(par.str, tmp, i);
	par.is_int = 1;
	ft_free(tmp);
	return (par);
}

t_params	ft_printf_x(t_params par, char *format)
{
	char	*tmp;
	size_t	i;

	i = va_arg(par.list_arg, unsigned int);
	if (format[par.pos] == 'x')
		tmp = ft_lltoa_base(i, "0123456789abcdef");
	else if (format[par.pos] == 'X')
		tmp = ft_lltoa_base(i, "0123456789ABCDEF");
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
		par = ft_printf_hash(par, format[par.pos]);
	else
		par.hash = 0;
	if (par.str[0] == '0' && par.prec <= 0 && par.point == 1)
		par.str[0] = '\0';
	par.is_int = 1;
	return (par);
}
