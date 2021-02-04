/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 22:48:25 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:46:17 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!(new_str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
