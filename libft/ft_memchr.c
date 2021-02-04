/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:23:36 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:42:35 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*src2;

	src2 = (unsigned char*)src;
	while (len != 0)
	{
		if (*src2 == (unsigned char)c)
			return ((unsigned char*)src2);
		else
		{
			src2++;
			len--;
		}
	}
	return (NULL);
}
