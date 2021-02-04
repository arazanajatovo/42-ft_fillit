/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/21 23:31:20 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 12:13:57 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_fillit.h"

int		ft_check_final(t_tetri *list, t_map *map, char *str)
{
	if ((list = ft_create_list(str, 'A')) == NULL)
	{
		free(str);
		return (-1);
	}
	if (!(map = ft_fillit(list)))
	{
		ft_del_list(list);
		return (-1);
	}
	ft_clean_fillit(map, list);
	return (1);
}

void	ft_check_contacte(char *str, t_check *check)
{
	if (check->i - 5 >= check->init_i && str[check->i - 5] == '#')
		check->contacte++;
	if (check->i - 1 >= check->init_i && str[check->i - 1] == '#')
		check->contacte++;
	if (check->i + 5 <= check->init_i + 19 && str[check->i + 5] == '#')
		check->contacte++;
	if (check->i + 1 <= check->init_i + 19 && str[check->i + 1] == '#')
		check->contacte++;
}

int		ft_check_tetra(char *str, t_check *check)
{
	check->init_i = check->i + 2;
	if (check->nb_plein != 4 || check->contacte < 6 ||
			check->nb_tetra > 26)
		return (-1);
	if (str[check->i + 1] == '\n')
	{
		check->nb_tetra++;
		check->i++;
		if (str[check->i + 1] == '\0')
			return (-1);
	}
	else if (str[check->i + 1] == '\0')
	{
		check->valide = 1;
		return (1);
	}
	else
		return (-1);
	check->contacte = 0;
	check->nb_row = 0;
	check->nb_line = 0;
	check->nb_plein = 0;
	return (1);
}

int		ft_check_all(char *str, t_check *check)
{
	while (str[++check->i])
	{
		check->valide = 0;
		if (str[check->i] == '.')
			check->nb_row++;
		else if (str[check->i] == '#')
		{
			ft_check_contacte(str, check);
			check->nb_row++;
			check->nb_plein++;
		}
		else if (str[check->i] == '\n' && check->nb_row == 4 &&
				++(check->nb_line) < 4)
			check->nb_row = 0;
		else if (check->nb_line == 4 && str[check->i] == '\n')
		{
			if (ft_check_tetra(str, check) == -1)
				return (-1);
		}
		else
			return (-1);
	}
	if (check->valide == 0)
		return (-1);
	return (1);
}

int		ft_check_read(char *str)
{
	t_check		check;
	int			res;

	check.i = -1;
	check.init_i = 0;
	check.valide = 0;
	check.contacte = 0;
	check.nb_row = 0;
	check.nb_line = 0;
	check.nb_plein = 0;
	check.nb_tetra = 1;
	if (str[0] == '\0')
		return (-1);
	if ((res = ft_check_all(str, &check)) == -1)
		return (-1);
	return (1);
}
