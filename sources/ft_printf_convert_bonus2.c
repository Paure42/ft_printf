/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_convert_bonus2.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 19:53:09 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 20:05:26 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "printf.h"

t_params	ft_printf_lu(t_params par)
{
	char	*tmp;
	size_t	i;

	tmp = ft_ulltoa(va_arg(par.list_arg, unsigned long long int));
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

t_params	ft_printf_hu(t_params par)
{
	char	*tmp;
	size_t	i;

	tmp = ft_ustoa((unsigned short)va_arg(par.list_arg, unsigned int));
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
