/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymenyoub <ymenyoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:23:18 by ymenyoub          #+#    #+#             */
/*   Updated: 2022/12/18 23:20:43 by ymenyoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/libft.h"

void	child_process(char **av, char **env, int *fd)
{
	int	fd_input;

	if (access(av[1], F_OK) == -1)
	{
		write(2, "pipex: no such file or directory: ", 34);
		write(2, av[1], ft_strlen(av[1]));
		exit(1);
	}
	fd_input = open(av[1], O_RDONLY);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_input, 0);
	close(fd[0]);
	ft_lunch(av[2], env);
}

void	parent_process(char **av, char **env, int *fd)
{
	int	fd_out;

	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		write(2, "file dosen't open\n", 18);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, 1);
	close(fd[1]);
	ft_lunch(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
		{
			write(2, "child doesn't create\n", 21);
			return (1);
		}
		if (pid == 0)
			child_process(av, env, fd);
		waitpid(pid, NULL, 0);
		parent_process(av, env, fd);
	}
	else
	{
		write(2, "pipex : invalid number of args\n", 31);
		return (1);
	}
}
