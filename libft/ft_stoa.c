/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 17:38:08 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 17:43:59 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumbers(short n)
{
	int i;

	if (n < 0)
		i = 1;
	else if (n == 0)
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

char		*ft_stoa(short n)
{
	char	*str;
	int		k;
	int		negatif;

	if (n == -32768)
		return (ft_strdup("-32768"));
	k = ft_countnumbers(n) + 1;
	if (!(str = ft_calloc(k, sizeof(*str))))
		return (str = ft_calloc(1, sizeof(*str)));
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		negatif = 0;
	}
	else
		negatif = -1;
	k--;
	while (--k > negatif)
	{
		str[k] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
