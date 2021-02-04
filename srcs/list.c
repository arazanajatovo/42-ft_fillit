/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 19:10:38 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 12:20:22 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

t_coord	*ft_coord_init(void)
{
	t_coord	*coord;

	if (!(coord = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	coord->lmin = 5;
	coord->rmin = 5;
	coord->lmax = 0;
	coord->rmax = 0;
	return (coord);
}

t_coord	*ft_get_coord(char **mstr, t_tetri **list)
{
	t_coord *coord;
	int		i;
	int		j;

	i = -1;
	coord = ft_coord_init();
	while (mstr[++i])
	{
		j = -1;
		while (mstr[i][++j])
		{
			if (mstr[i][j] == '#')
			{
				coord->lmin = i < coord->lmin ? i : coord->lmin;
				coord->lmax = i > coord->lmax ? i : coord->lmax;
				coord->rmin = j < coord->rmin ? j : coord->rmin;
				coord->rmax = j > coord->rmax ? j : coord->rmax;
			}
		}
	}
	coord->l = coord->lmin;
	coord->r = coord->rmin;
	(*list)->width = coord->rmax - coord->rmin + 1;
	(*list)->hight = coord->lmax - coord->lmin + 1;
	return (coord);
}

t_tetri	*ft_cut_tetri(char **mstr, t_tetri *list, int i, int j)
{
	t_coord *coord;

	i = 0;
	coord = ft_get_coord(mstr, &list);
	if (!(list->content = (char**)malloc(sizeof(char*) * (list->hight + 1))))
		return (NULL);
	while (coord->l <= coord->lmax)
	{
		j = 0;
		coord->r = coord->rmin;
		if (!(list->content[i] = ft_strnew(list->width)))
			return (NULL);
		while (coord->r <= coord->rmax)
		{
			list->content[i][j] = mstr[coord->l][coord->r];
			coord->r++;
			j++;
		}
		coord->l++;
		i++;
	}
	free(coord);
	list->content[i] = NULL;
	return (list);
}

char	**ft_str_to_mstr(char *str)
{
	char	**mstr;
	int		nb_r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(mstr = (char**)malloc(sizeof(char*) * 5)))
		return (NULL);
	while (j < 4)
	{
		nb_r = 0;
		if (!(mstr[j] = ft_strnew(4)))
			return (NULL);
		while (nb_r < 4)
		{
			mstr[j][nb_r] = str[i];
			i++;
			nb_r++;
		}
		i++;
		j++;
	}
	mstr[j] = NULL;
	return (mstr);
}

t_tetri	*ft_create_list(char *str, char id)
{
	char	**mstr;
	char	*tmp;
	t_tetri	*list;

	mstr = NULL;
	list = NULL;
	if (init_elem(mstr, str, &list, id) == 0)
		return (NULL);
	if (str[20] == '\n')
	{
		tmp = str;
		if (!(str = ft_strsub(str, 21, ft_strlen(str) - 21)))
			return (NULL);
		free(tmp);
	}
	else
	{
		free(str);
		str = NULL;
	}
	if (str)
		list->next = ft_create_list(str, ++id);
	return (list);
}
