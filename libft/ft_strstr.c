/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 19:35:55 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:56:41 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *src, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (!needle[i])
		return ((char*)src);
	while (src[i])
	{
		j = 0;
		while (src[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)&src[i]);
		}
		i++;
	}
	return (0);
}
