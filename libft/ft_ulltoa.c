/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ultoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 19:35:17 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 20:02:02 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumbers(unsigned long long int n)
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

char		*ft_ulltoa(unsigned long long int n)
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
