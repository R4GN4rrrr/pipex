/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 03:24:38 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/11/18 01:58:12 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*p;

	l = ft_strlen(s1)+ 1;
	p = malloc(ft_strlen((char *)s1) + 1);
	if (!p)
		return (0);
	ft_memcpy(p, s1, l);
	return (p);
}
