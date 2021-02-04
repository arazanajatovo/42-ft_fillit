/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 15:12:10 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:54:50 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned char	*join;
	size_t			i;
	size_t			j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(join = (unsigned char*)malloc(sizeof(*join) *
					(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1))))
		return (NULL);
	while (s1[j])
		join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i++] = '\0';
	return ((char*)join);
}
