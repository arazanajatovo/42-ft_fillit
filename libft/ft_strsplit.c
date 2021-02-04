/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/25 12:16:29 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:56:34 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

static size_t	ft_countchars(char const *s, size_t init_i, char c)
{
	size_t	len;

	len = 0;
	while (s[init_i] != (char const)c && s[init_i])
	{
		init_i++;
		len++;
	}
	return (len);
}

static char		**ft_countwords(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == (char const)c)
			i++;
		if (s[i] && s[i] != (char const)c)
			len++;
		while (s[i] != (const char)c && s[i])
			i++;
	}
	if (!(split = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	init_i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s || !(split = ft_countwords(s, c)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == (char const)c)
			i++;
		init_i = i;
		len = ft_countchars(s, init_i, c);
		i = i + len;
		if (!(split[j] = ft_strsub(s, init_i, len)))
			return (NULL);
		if (s[i] || (!s[i] && s[i - 1] != (char const)c))
			j++;
	}
	split[j] = NULL;
	return (split);
}
