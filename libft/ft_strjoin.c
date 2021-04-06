/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 10:54:53 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 13:59:15 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(int n, char *s1, char *s2)
{
	if (n == 1)
		free(s1);
	else if (n == 2)
		free(s2);
	else if (n == 3)
	{
		free(s1);
		free(s2);
	}
}

char			*ft_strjoin(char const *s1, char const *s2, int f)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = -1;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	i += ft_strlen(s2);
	if (i <= 0 || !(str = malloc((i + 1) * sizeof(*str))))
		return (str = ft_calloc(1, sizeof(*str)));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++n])
	{
		str[i] = s2[n];
		i++;
	}
	str[i] = 0;
	if (f)
		ft_free(f, (char*)s1, (char*)s2);
	return (str);
}
