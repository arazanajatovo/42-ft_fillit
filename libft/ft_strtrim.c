/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 17:14:34 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:56:56 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned char	*trim;
	size_t			i;
	size_t			j;
	size_t			k;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen((char*)s);
	k = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] != '\0')
	{
		j--;
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
			j--;
	}
	if (!(trim = (unsigned char*)ft_strnew(j - i + 1)))
		return (NULL);
	while (i <= j)
		trim[k++] = (unsigned char)s[i++];
	trim[k] = '\0';
	return ((char*)trim);
}
