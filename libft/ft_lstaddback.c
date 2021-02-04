/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lst_add_back.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 22:56:25 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:41:05 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*list;

	if (alst && new)
	{
		if (*alst == NULL)
		{
			*alst = ft_lstnew(new->content, new->content_size);
			return ;
		}
		list = *alst;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
		new->next = NULL;
	}
}
