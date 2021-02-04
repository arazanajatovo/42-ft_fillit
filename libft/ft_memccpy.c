/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:16:24 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:42:28 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	while (len != 0)
	{
		if (*src2 == (unsigned char)c)
		{
			*dest2 = (unsigned char)*src2;
			dest2++;
			return ((unsigned char*)dest2);
		}
		else
		{
			*(dest2++) = (unsigned char)*(src2++);
			len--;
		}
	}
	return (NULL);
}
