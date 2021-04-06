/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_rules.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/10 13:05:17 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 14:58:07 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static int	ft_printf_is_flags(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '+'
			|| c == '#' || c == ' ')
		return (1);
	else
		return (0);
}

static int	ft_printf_is_conv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'n' || c == 'l' || c == 'h')
		return (1);
	else
		return (0);
}

t_params	ft_printf_rules(char *format, t_params par)
{
	if (format[par.pos] == '%')
		par.pos++;
	while (format[par.pos])
	{
		if (ft_printf_is_flags(format[par.pos]) == 1)
			par = ft_printf_flags(format, par);
		else if (format[par.pos] >= '1' && format[par.pos] <= '9')
			par = ft_printf_field(format, par);
		else if (ft_printf_is_conv(format[par.pos]) == 1)
		{
			par = ft_printf_conv(format, par);
			break ;
		}
		else if (format[par.pos] == '%')
		{
			par.str[0] = '%';
			par.pos++;
			break ;
		}
		else if (format[par.pos] == '*')
			par = ft_printf_star(par, format);
		else
			break ;
	}
	return (par);
}
