/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:12:17 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:55:02 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destend;
	size_t	len;
	size_t	srclen;

	destend = 0;
	srclen = 0;
	len = 0;
	while (dest[destend])
		destend++;
	len += size < destend ? size : destend;
	while (src[srclen] != '\0' && srclen < size - len)
	{
		dest[destend++] = src[srclen++];
	}
	while (src[srclen])
		srclen++;
	destend -= size <= destend ? 1 : 0;
	destend += len >= size ? 1 : 0;
	dest[destend] = '\0';
	return (len + srclen);
}
