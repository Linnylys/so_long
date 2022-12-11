/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsipile <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:06:06 by lsipile           #+#    #+#             */
/*   Updated: 2022/02/13 19:59:45 by lsipile          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	nb_dec_cal(int n)
{
	int	nbr;
	int	nb_dec;

	nb_dec = 1;
	nbr = n;
	while ((nbr / 10) != 0)
	{
		nbr = nbr / 10;
		nb_dec ++;
	}
	if (n < 0)
		nb_dec ++;
	return (nb_dec);
}

char	*ft_itoa_limited(int n)
{
	int		nb_dec;
	int		nbr;
	int		i;
	char	*str;

	nbr = n;
	nb_dec = nb_dec_cal(n);
	str = malloc((nb_dec + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n >= 0)
		nbr = n;
	else
		nbr = -n;
	i = nb_dec - 1;
	str[nb_dec] = '\0';
	while (i >= 0 && (i != 0 || n >= 0))
	{
		str[i] = '0' + nbr % 10;
		nbr = nbr / 10;
		i --;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	else if (n == -2147483648)
	{
		str = ft_itoa_limited(-2147483647);
		str[10] = '8';
	}
	else
		str = ft_itoa_limited(n);
	return (str);
}
