/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_padding.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 18:44:10 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 16:14:36 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_params	ft_printf_negative(t_params par, int i)
{
	char	*tmp;
	size_t	len;

	if (!(tmp = ft_calloc(i + 1, sizeof(char))))
	{
		par.error = 1;
		return (par);
	}
	tmp = ft_memset(tmp, ' ', i);
	len = ft_strlen(tmp);
	if (len >= (par.alloc - ft_strlen(par.str)))
		if (!(par.str = ft_realloc(par.str, ft_strlen(par.str),
			ft_strlen(par.str) + len + 1)) && (par.error = 1) == 1)
			return (par);
	if (par.negative == 1)
		ft_strncat(par.str, tmp, len);
	else
		par.str = ft_strjoin(tmp, par.str, 2);
	free(tmp);
	return (par);
}

t_params	ft_printf_prec(char *format, t_params par)
{
	if (format[par.pos + 1] == '*' && par.pos++)
		return (par = ft_printf_star(par, format));
	if (format[par.pos + 1] >= '0' && format[par.pos + 1] <= '9')
	{
		par.pos++;
		while (format[par.pos] &&
			(format[par.pos] >= '0' && format[par.pos] <= '9'))
		{
			par.prec = par.prec * 10 + (format[par.pos] - '0');
			par.pos++;
		}
		par.pos--;
		return (par);
	}
	else if (par.is_str == 1)
		par.prec = -2;
	else
		par.prec = -1;
	return (par);
}

t_params	ft_printf_star(t_params par, char *format)
{
	if (format[par.pos - 1] == '.')
	{
		par.prec = va_arg(par.list_arg, int);
		if (par.prec < 0)
		{
			par.point = 0;
			par.prec = 0;
		}
		return (par);
	}
	else
		par.field = va_arg(par.list_arg, int);
	if (par.field < 0)
	{
		par.field *= -1;
		par.negative = 1;
	}
	par.pos++;
	return (par);
}
