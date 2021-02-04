/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfold.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 17:57:51 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:41:29 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_lstfold(int (*f)(int, int), t_list **list)
{
	t_list	*tmp;
	int		res;

	if (!list)
		return (0);
	res = 0;
	tmp = *list;
	res = (int)(ft_atoi((char*)tmp->content));
	while (tmp->next)
	{
		tmp = tmp->next;
		res = f(res, (int)(ft_atoi((char*)tmp->content)));
	}
	return (res);
}
