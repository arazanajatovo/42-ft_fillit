/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 07:16:18 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 12:14:47 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

int		init_elem(char **mstr, char *str, t_tetri **list, int id)
{
	if (!(*list = (t_tetri*)malloc(sizeof(t_tetri))))
		return (0);
	if (!(mstr = ft_str_to_mstr(str)))
		return (0);
	if (!(*list = ft_cut_tetri(mstr, *list, 0, 0)))
		return (0);
	ft_free_mstr(mstr);
	(*list)->id = id;
	(*list)->next = NULL;
	return (1);
}

int		ft_sqrtup(int count)
{
	int		i;

	i = 10;
	while (i > 0)
	{
		if (i * i == count)
			return (i);
		else if (i * i < count)
			return (i + 1);
		else
			i--;
	}
	return (count);
}

int		taille_min_map(t_tetri *list)
{
	int		count;

	count = 0;
	while (list)
	{
		list = list->next;
		count += 4;
	}
	return (ft_sqrtup(count));
}

t_map	*ft_create_map(int taille_min, int add_taille)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->taille = taille_min + add_taille;
	if (!(map->content = (char**)malloc(sizeof(char*) * (map->taille + 1))))
		return (NULL);
	while (i < map->taille)
	{
		j = 0;
		if (!((map->content)[i] = ft_strnew(map->taille)))
			return (NULL);
		while (j < map->taille)
		{
			(map->content)[i][j] = '.';
			j++;
		}
		i++;
	}
	(map->content)[i] = NULL;
	return (map);
}
