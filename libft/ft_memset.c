/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 19:18:46 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:43:46 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *str, int n, size_t len)
{
	unsigned int	i;
	unsigned char	*dest;

	dest = (unsigned char*)str;
	i = 0;
	while (i < len)
	{
		dest[i] = (unsigned char)n;
		i++;
	}
	return (dest);
}
