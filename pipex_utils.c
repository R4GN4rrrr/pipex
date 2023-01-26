/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:22:29 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/12/18 05:23:50 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void	ft_free(char **av)
{
	int	i;

	i = 0;
	while (av[i++])
		free(av[i]);
	free(av);
}

char	*ft_get_path(char *cmd, char **env)
{
	char	**path;
	char	*new_p;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	path = ft_split(env[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		new_p = ft_strjoin(temp, cmd);
		free(temp);
		if (access(new_p, X_OK) == 0)
			return (new_p);
		free(new_p);
		i++;
	}
	ft_free(path);
	return (0);
}

void	ft_lunch(char *av, char **env)
{
	char	*p_name;
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(av, ' ');
	execve(cmd[0], cmd, env);
	p_name = ft_get_path(cmd[0], env);
	if (execve(p_name, cmd, env) < 0)
	{
		write(2, "pipex : command not found : ", 28);
		write(2, av, ft_strlen(av));
		write(2, "\n", 1);
		ft_free(cmd);
		exit(127);
	}
}
