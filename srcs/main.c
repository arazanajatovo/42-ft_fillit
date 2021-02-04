/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 23:35:24 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 12:47:30 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

void	ft_del_list(t_tetri *list)
{
	if (list->next)
		ft_del_list(list->next);
	ft_free_mstr(list->content);
	free(list);
}

void	ft_display_map(t_map *map)
{
	int		i;

	i = 0;
	while (map->content[i])
		ft_putendl(map->content[i++]);
}

void	ft_clean_fillit(t_map *map, t_tetri *list)
{
	ft_del_list(list);
	ft_display_map(map);
	ft_free_mstr(map->content);
	free(map);
}

int		ft_read_tetri(int fd, char **str)
{
	char	*buf;
	char	*tmp;
	int		bfs;

	bfs = BUFF_SIZE;
	if (!(*str))
		if (!(*str = ft_strnew(0)))
			return (0);
	if (!(buf = ft_strnew(bfs)))
	{
		free(*str);
		return (0);
	}
	if ((bfs = read(fd, buf, BUFF_SIZE) > 0))
	{
		tmp = *str;
		if ((*str = ft_strjoin(tmp, buf)) == NULL)
			return (0);
		free(tmp);
		free(buf);
		return (ft_read_tetri(fd, str));
	}
	free(buf);
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	char	*str;
	t_tetri	*list;

	str = NULL;
	list = NULL;
	map = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDWR);
		if (!(ft_read_tetri(fd, &str)))
			return (-1);
		if (ft_check_read(str) == -1)
		{
			free(str);
			ft_putendl("error");
			return (-1);
		}
		if (ft_check_final(list, map, str) == -1)
			return (-1);
	}
	else
		ft_putendl("usage : ./fillit target_file");
	return (0);
}
