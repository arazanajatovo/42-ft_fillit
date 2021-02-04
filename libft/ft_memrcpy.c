/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 18:00:55 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:43:38 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst1;
	unsigned char		*src1;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = n;
	while (i > 0)
	{
		i--;
		dst1[i] = src1[i];
	}
	return (dst1);
}
