/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_reverse_char.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 15:45:26 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 20:20:47 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_char(char *str, size_t len)
{
	char	tmp[len + 1];
	size_t	i;
	size_t	j;

	tmp[0] = str[len - 1];
	i = 1;
	j = 0;
	while (i < len)
	{
		tmp[i] = str[j];
		j++;
		i++;
	}
	tmp[len] = 0;
	i = 0;
	while (tmp[i])
	{
		str[i] = tmp[i];
		i++;
	}
}
