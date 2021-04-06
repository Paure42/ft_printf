/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:34:16 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 17:05:52 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char c)
{
	int		k;
	char	**tab;
	int		i;
	int		j;
	int		nbchar;

	i = 0;
	j = 0;
	nbchar = 0;
	if (!s || !s[0] || (!(k = ft_countwords(s, c)))
			|| !(tab = ft_calloc((k + 1), sizeof(char*))))
		return (tab = ft_calloc(1, sizeof(char*)));
	while (--k > -1)
	{
		if (s[i] != c)
		{
			i += nbchar = ft_countletters(s, c, i);
			tab[j] = ft_substr(s, i - nbchar, nbchar);
			j++;
			nbchar = 0;
		}
		while (s[i] == c)
			i++;
	}
	return (tab);
}
