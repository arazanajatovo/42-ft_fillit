/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:15:52 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:56:26 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	*tmp;
	int		len;

	tmp = (char*)src;
	len = 0;
	while (*tmp)
	{
		tmp++;
		len++;
	}
	while (len >= 0)
	{
		if (*tmp == c)
			return (tmp);
		tmp--;
		len--;
	}
	if (*tmp == c)
		return (tmp);
	return (NULL);
}
