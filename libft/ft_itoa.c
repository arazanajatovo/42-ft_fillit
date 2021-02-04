/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/13 03:31:26 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/25 18:36:33 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_fillstring(int n, int neg, int len)
{
	char	*new;
	long	nb;

	nb = n;
	if (!(new = ft_strnew(len)))
		return (NULL);
	if (neg == 1)
		new[0] = '-';
	nb = n < 0 ? nb * -1 : nb;
	new[len--] = '\0';
	while (len >= neg)
	{
		new[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (new);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;
	int		neg;

	len = 0;
	neg = 0;
	nb = n;
	if (n <= 0)
		len++;
	if (n < 0)
		neg = 1;
	nb = n < 0 ? nb * -1 : nb;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	if (!(str = ft_fillstring(n, neg, len)))
		return (NULL);
	return (str);
}
