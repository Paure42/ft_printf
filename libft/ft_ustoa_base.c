/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/16 19:14:27 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 19:28:55 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnumbers(unsigned short int n, int base_max)
{
	int i;

	if (n == 0)
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

char		*ft_ustoa_base(unsigned short int n, char *base)
{
	char	*str;
	int		k;
	int		negatif;
	int		base_max;

	base_max = ft_strlen(base);
	k = ft_countnumbers(n, base_max) + 1;
	if (!(str = ft_calloc(k, sizeof(char))))
		return (str = ft_calloc(1, sizeof(char)));
	if (n == 0 && (str[0] = '0') == '0')
		return (str);
	negatif = -1;
	k--;
	while (--k > negatif && (str[k] = base[n % base_max]) != '\0')
		n /= base_max;
	return (str);
}
