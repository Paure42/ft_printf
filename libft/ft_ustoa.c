/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ustoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 19:36:21 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 19:38:02 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumbers(unsigned short int n)
{
	int	i;

	if (n == 0)
		i = 1;
	else
		i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_ustoa(unsigned short int n)
{
	char	*str;
	int		k;

	k = ft_countnumbers(n) + 1;
	if (!(str = ft_calloc(k, sizeof(*str))))
		return (str = ft_calloc(1, sizeof(*str)));
	k--;
	while (--k > -1)
	{
		str[k] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
