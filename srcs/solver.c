/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 07:37:30 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 10:34:27 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

void	ft_free_mstr(char **mstr)
{
	int		i;

	i = 0;
	while (mstr[i])
		free(mstr[i++]);
	free(mstr);
}

t_map	*ft_remove_tetri(t_map *map, t_tetri *tetri, int i, int j)
{
	int		k;
	int		l;

	k = 0;
	while (tetri->content[k])
	{
		l = 0;
		while (tetri->content[k][l])
		{
			if (map->content[i + k][j + l] == tetri->id)
				map->content[i + k][j + l] = '.';
			l++;
		}
		k++;
	}
	return (map);
}

t_map	*ft_add_tetri(t_map *map, t_tetri *tetri, int i, int j)
{
	int		k;
	int		l;

	k = 0;
	while (tetri->content[k])
	{
		l = 0;
		while (tetri->content[k][l])
		{
			if (tetri->content[k][l] == '#')
			{
				if (map->content[i + k][j + l] == '.')
					map->content[i + k][j + l] = tetri->id;
				else
					return (NULL);
			}
			l++;
		}
		k++;
	}
	return (map);
}

t_map	*ft_fill_map(t_map *map, t_tetri *tetri, int i, int j)
{
	t_map	*filledmap;
	int		taille;

	taille = map->taille;
	filledmap = NULL;
	if (i + tetri->hight <= taille)
	{
		if ((filledmap = ft_add_tetri(map, tetri, i, j)))
			if (tetri->next)
				filledmap = ft_fill_map(filledmap, tetri->next, 0, 0);
		if (!filledmap)
		{
			map = ft_remove_tetri(map, tetri, i, j);
			if (j + tetri->width > taille)
				filledmap = ft_fill_map(map, tetri, i + 1, 0);
			else
				filledmap = ft_fill_map(map, tetri, i, j + 1);
		}
	}
	else
		return (NULL);
	return (filledmap);
}

t_map	*ft_fillit(t_tetri *list)
{
	int		taille;
	int		i;
	t_map	*map;
	t_map	*tmp;

	i = 0;
	map = NULL;
	taille = taille_min_map(list);
	while (!map)
	{
		if ((map = ft_create_map(taille, i++)) == NULL)
			return (NULL);
		tmp = map;
		map = ft_fill_map(map, list, 0, 0);
		if (!map)
		{
			ft_free_mstr(tmp->content);
			free(tmp);
		}
	}
	return (map);
}
