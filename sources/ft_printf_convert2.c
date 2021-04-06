/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_convert2.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 15:37:31 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 12:10:54 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_params	ft_printf_p(t_params par)
{
	char	*tmp;
	char	*tmp2;
	size_t	i;

	tmp2 = ft_lltoa_base((long long)va_arg(par.list_arg, void*),
			"0123456789abcdef");
	tmp = ft_strjoin("0x", tmp2, 0);
	if (!tmp || (i = ft_strlen(tmp)) >= par.alloc + 1)
		if (!tmp ||
			!(par.str = ft_realloc(par.str, par.alloc + 1, par.alloc + i + 1)))
		{
			par.error = 1;
			ft_free(tmp);
			ft_free(tmp2);
			return (par);
		}
	ft_strncat(par.str, tmp, i);
	ft_free(tmp);
	ft_free(tmp2);
	if (par.str[2] == '0' && par.point == 1)
		par.str[2] = '\0';
	par.is_int = 1;
	par.point = 0;
	return (par);
}
