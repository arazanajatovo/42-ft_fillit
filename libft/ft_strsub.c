/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 12:33:55 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:56:48 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned char	*sub;
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	if (!(sub = (unsigned char*)malloc(sizeof(*sub) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		sub[i] = (unsigned char)s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return ((char*)sub);
}
