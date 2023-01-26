/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 02:48:33 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/10/30 04:18:49 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	l = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
		l = 0;
	else
		l = ft_strlen(s1) - 1;
	while (l && ft_strchr(set, s1[l]))
		l--;
	str = ft_substr(s1, i, l - i + 1);
	return (str);
}
