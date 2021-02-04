/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 23:18:49 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:56:08 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char*)ft_memalloc(size + 1)))
		return (NULL);
	return (new);
}
