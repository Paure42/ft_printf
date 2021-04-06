/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_zero.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 16:13:27 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 13:13:03 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

static t_params		ft_printf_zero_numb(t_params par)
{
	int i;

	i = 0;
	while (par.str[i] && par.str[i] != '+' && par.str[i] != '-')
		i++;
	if (par.str[i] == '-')
	{
		par.str[i] = '0';
		par.str[0] = '-';
	}
	else if (par.str[i] == '+')
	{
		par.str[i] = '0';
		par.str[0] = '+';
	}
	return (par);
}

t_params			ft_printf_zero(t_params par, int i)
{
	char	*tmp;
	size_t	tmp_len;
	size_t	str_len;

	if (!(tmp = ft_calloc(i + 1, sizeof(char)))
			&& (par.error = 1) == 1)
		return (par);
	tmp = ft_memset(tmp, '0', i);
	str_len = ft_strlen(par.str);
	if ((tmp_len = ft_strlen(tmp)) >= (par.alloc - str_len))
		if (!(par.str = ft_realloc(par.str, str_len, str_len + tmp_len + 1)))
		{
			par.error = 1;
			return (par);
		}
	ft_strncat(par.str, tmp, tmp_len);
	while (par.hash == 0 && tmp_len && (int)tmp_len-- > -1)
		ft_reverse_char(par.str, ft_strlen(par.str));
	while (par.hash == 1 && tmp_len && (int)tmp_len-- > -1)
		ft_reverse_char(par.str + 2, ft_strlen(par.str + 2));
	if (par.is_int == 1)
		par = ft_printf_zero_numb(par);
	free(tmp);
	return (par);
}
