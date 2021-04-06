/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 12:54:10 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 20:13:31 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		begin;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	begin = ft_cmpchar(s1, set, 0, 1);
	end = ft_cmpchar(s1, set, len - 1, -1);
	if (begin == len || !(str = ft_substr(s1, begin, end + 1 - begin)))
		return (str = ft_calloc(1, sizeof(*str)));
	return (str);
}
