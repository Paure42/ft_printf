/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmpchar.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 11:41:09 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/05 13:55:33 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmpchar(char const *s1, char const *set, int start, int pos)
{
	int i;

	i = -1;
	if (!(s1) || !(set))
		return (0);
	while (set[++i] && start != -1 && s1[start])
	{
		if (set[i] == s1[start])
		{
			start += pos;
			i = -1;
		}
	}
	return (start);
}
