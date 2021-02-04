/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 18:23:15 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/27 22:45:06 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_sqrt(int nb)
{
	int		min;
	int		max;
	int		testsqr;

	min = 0;
	max = 46341;
	testsqr = (max - min) / 2;
	if (nb <= 0)
		return (0);
	while (testsqr * testsqr != nb)
	{
		if (testsqr * testsqr > nb)
			max = testsqr;
		if (testsqr * testsqr < nb)
			min = testsqr;
		if (max - min <= 1)
			return (0);
		testsqr = (max - min) / 2 + min;
	}
	return (testsqr);
}
