/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:10:47 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/09 12:05:15 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **av, char **envp, int *fd)
{
	int	fd1;

	fd1 = open(av[1], O_RDONLY, 0777);
	if (fd1 == -1)
		error(ERR_INFILE);
	dup2(fd[1], 1);
	dup2(fd1, 0);
	close(fd[0]);
	exec(envp, av[2]);
}

void	mother(char **av, char **envp, int *fd)
{
	int	fd2;

	fd2 = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd2 == -1)
		error(ERR_OUTFILE);
	dup2(fd[0], 0);
	dup2(fd2, 1);
	close(fd[1]);
	exec(envp, av[3]);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (envp == NULL)
		error(ERR_ENV);
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error(ERR_PIPE);
		pid1 = fork();
		if (pid1 == -1)
			error(ERR_PRC);
		if (pid1 == 0)
			child(av, envp, fd);
		mother(av, envp, fd);
	}
	else
	{
		error(ERR_INPUT);
	}
	return (0);
}
