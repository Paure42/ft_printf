/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 05:12:24 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 05:34:36 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumbers(unsigned int n)
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

char		*ft_utoa(unsigned int n)
{
	char	*str;
	int		k;

	if ((int)n < 0)
		n = 4294967295 + n + 1;
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
