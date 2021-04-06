/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countwords.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 10:58:36 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 19:05:58 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int i;
	int nbwords;

	if (!(s))
		return (0);
	i = 0;
	nbwords = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i + 1] == c)
				i++;
			if (s[i + 1])
				nbwords++;
		}
		i++;
	}
	if (nbwords == 1 && s[0] == c)
		return (0);
	return (nbwords);
}
