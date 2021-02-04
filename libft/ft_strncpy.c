/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:33:40 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:55:44 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	while (i < len && src[i])
	{
		dest2[i] = (unsigned char)src2[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return ((char*)dest2);
}
