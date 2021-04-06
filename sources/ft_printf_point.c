/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_point.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 11:56:21 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 16:23:04 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static t_params		ft_point_s(t_params par, int i)
{
	if (par.prec == -2)
	{
		par.str[i] = '.';
		return (par);
	}
	if (!(par.str = ft_realloc(par.str, i, par.prec + 1)))
		par.error = 1;
	par.str[par.prec] = 0;
	return (par);
}

static t_params		ft_point_di(t_params par, int i)
{
	int	n;

	if (par.str[0] == '+' || par.str[0] == '-')
		n = 1;
	else if (par.hash == 1)
		n = 2;
	else
		n = 0;
	if (!(par.str = ft_realloc(par.str, i, par.prec + 1 + n))
				&& (par.error = 1) == 1)
		return (par);
	while (i > (-1 + n))
	{
		if (par.str[i] != '\0')
			par.str[par.prec + n] = par.str[i];
		i--;
		par.prec--;
	}
	while (par.prec + n > (-1 + n))
	{
		par.str[par.prec + n] = '0';
		par.prec--;
	}
	return (par);
}

t_params			ft_printf_point(t_params par)
{
	int	i;

	if (par.hash == 1 && par.is_int == 1)
		i = 2;
	if (par.is_int == 1 && par.zero == 1 && par.field > 0)
		par.zero = 0;
	if (par.is_int == 1 && par.str[par.plus] == '0'
			&& (par.prec == 0 || par.prec == -1))
	{
		par.str[par.plus] = '\0';
		return (par);
	}
	i = ft_strlen(par.str);
	if (par.is_int == 1 && (par.str[0] == '+' || par.str[0] == '-'))
		i--;
	if (par.is_str == 1 && par.prec < i)
		par = ft_point_s(par, i);
	else if (par.is_int == 1 && par.prec > i)
		par = ft_point_di(par, ft_strlen(par.str));
	return (par);
}
