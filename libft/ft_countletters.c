/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countletters.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 11:04:28 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 19:05:17 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countletters(char const *s, char c, int start)
{
	int	nbchar;

	if (!(s))
		return (0);
	nbchar = 0;
	while (s[start] != c && s[start])
	{
		start++;
		nbchar++;
	}
	return (nbchar);
}
