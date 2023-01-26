/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:06:24 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/10/31 00:46:19 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*tmp;
	char		*tmp1;

	tmp = (const char *)src;
	tmp1 = (char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst == src)
		return (dst);
	while (i < n)
	{
		tmp1[i] = tmp[i];
		i++;
	}
	return (dst);
}
