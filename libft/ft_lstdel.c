/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 22:44:40 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:41:12 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmp;

	lst = *alst;
	if (alst && del)
	{
		while (lst)
		{
			tmp = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = tmp;
		}
		*alst = NULL;
	}
}
