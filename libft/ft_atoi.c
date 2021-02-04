/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 19:24:03 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 19:10:00 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_atoi(const char *str)
{
	long	num;
	int		i;
	int		negt;

	i = 0;
	num = 0;
	negt = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		negt = -negt;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * negt);
}
