/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:23:08 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/12/17 01:59:27 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <time.h>
# include <sys/wait.h>
# include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	child_process(char **av, char **env, int *fd);
char	**ft_split(char const *s, char c);
char	*ft_get_path(char *cmd, char **env);
void	ft_lunch(char *av, char **env);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif