/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 17:14:17 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:41:45 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	list = lst;
	if (lst && f)
	{
		if (!(list = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		list = f(lst);
		if (lst->next != NULL)
			list->next = ft_lstmap(lst->next, f);
		else
			list->next = NULL;
		return (list);
	}
	return (NULL);
}
