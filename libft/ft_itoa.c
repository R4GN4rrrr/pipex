/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:20:10 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/10/28 06:18:57 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_nbr(int count)
{
	int	i;

	i = 0;
	if (count <= 0)
		i++;
	while (count)
	{
		count /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*str;

	i = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_nbr(n);
	str = malloc (sizeof (char) * size + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (n > 0)
	{
		str[size - i++] = ((n % 10 + '0'));
		n /= 10;
	}
	return (str);
}
