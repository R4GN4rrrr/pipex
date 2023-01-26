/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:15:08 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/11/01 11:14:11 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (tmp[index] == (unsigned char ) c)
			return (&tmp[index]);
		index++;
	}
	return (NULL);
}
