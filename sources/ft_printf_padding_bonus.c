/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_padding_bonus.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 15:32:57 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 13:27:52 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_params	ft_printf_hash(t_params par, char c)
{
	int	len;

	len = ft_strlen(par.str);
	if (c == 'x' || c == 'X')
	{
		if (!(par.str = ft_realloc(par.str, len, len + 2 + 1)))
		{
			par.error = 1;
			return (par);
		}
		par.str[len] = '0';
		if (c == 'x')
			par.str[len + 1] = 'x';
		else
			par.str[len + 1] = 'X';
		ft_reverse_char(par.str, len + 2);
		ft_reverse_char(par.str, len + 2);
	}
	return (par);
}

t_params	ft_printf_space(t_params par, int i)
{
	int	n;

	if (par.str[0] == '-' || par.str[0] == '+')
		n = 1;
	else
		n = 0;
	par.str[i] = par.str[n];
	par.str[n] = ' ';
	return (par);
}
