/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 06:01:58 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 12:17:00 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumbers(int n, int base_max)
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
		n /= base_max;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int n, char *base)
{
	char	*str;
	int		k;
	int		negatif;
	int		base_max;

	base_max = ft_strlen(base);
	k = ft_countnumbers(n, base_max) + 1;
	if (!(str = ft_calloc(k, sizeof(char))))
		return (str = ft_calloc(1, sizeof(char)));
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
		str[k] = base[n % base_max];
		n /= base_max;
	}
	return (str);
}
