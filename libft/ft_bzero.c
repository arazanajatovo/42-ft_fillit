/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bzero.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:01:41 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:33:45 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned int	i;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char*)str;
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
}
