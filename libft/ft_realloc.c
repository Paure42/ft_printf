/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: paure <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/26 16:45:31 by paure        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 19:10:33 by paure       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t size)
{
	char	*str;

	if (old_size > size)
		old_size = size;
	if (!ptr || !(str = ft_calloc(size, sizeof(char))))
		return (NULL);
	ft_memcpy(str, ptr, old_size);
	free(ptr);
	return (str);
}
