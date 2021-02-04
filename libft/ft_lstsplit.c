/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 17:25:23 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:42:10 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstsplit(char const *s, char c)
{
	t_list	*list;
	char	**split;
	size_t	i;

	i = 0;
	list = NULL;
	if (!s || !c)
		return (NULL);
	split = ft_strsplit(s, c);
	while (split[i])
	{
		ft_lstaddback(&list, ft_lstnew(split[i], ft_strlen(split[i])));
		i++;
	}
	return (list);
}
