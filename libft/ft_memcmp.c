/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:12:13 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/10/28 06:19:08 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp1;
	int				d;

	i = 0;
	d = 0;
	tmp = (unsigned char *)s1;
	tmp1 = (unsigned char *)s2;
	while (i < n)
	{
		d = (tmp[i] - tmp1[i]);
		if (tmp[i] != tmp1[i])
			return (d);
		i++;
	}
	return (0);
}
