/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:05:35 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/10/28 06:20:29 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ldest;
	unsigned int	lsrc;

	j = 0;
	lsrc = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (dstsize + lsrc);
	ldest = ft_strlen(dst);
	i = ldest;
	if (ldest < dstsize)
	{
		while (src[j] && j < dstsize - ldest - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (ldest + lsrc);
	}
	return (dstsize + lsrc);
}
