/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fillit.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 01:29:38 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 11:52:55 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# define BUFF_SIZE 42

# include "../libft/includes/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct		s_map
{
	char			**content;
	int				taille;
}					t_map;

typedef struct		s_tetri
{
	struct s_tetri	*next;
	char			**content;
	int				width;
	int				hight;
	char			id;
}					t_tetri;

typedef struct		s_coord
{
	int				l;
	int				r;
	int				lmin;
	int				lmax;
	int				rmin;
	int				rmax;
}					t_coord;

typedef struct		s_check
{
	int				i;
	int				init_i;
	int				contacte;
	int				valide;
	int				nb_row;
	int				nb_line;
	int				nb_plein;
	int				nb_tetra;
}					t_check;

t_tetri				*ft_cut_tetri(char **mstr, t_tetri *list, int i, int j);
t_tetri				*ft_create_list(char *str, char id);
t_map				*ft_create_map(int taille_min, int add_taille);
t_map				*ft_fillit(t_tetri *list);
char				**ft_str_to_mstr(char *str);
int					ft_check_final(t_tetri *list, t_map *map, char *str);
int					taille_min_map(t_tetri *list);
int					ft_check_read(char *str);
int					init_elem(char **mstr, char *str, t_tetri **list, int id);
void				ft_free_mstr(char **mstr);
void				ft_clean_fillit(t_map *map, t_tetri *list);
void				ft_del_list(t_tetri *list);
#endif
