/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:03 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/05 15:29:31 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	if (!path)
	{
		return (NULL);
	}
	return (path);
}

char	*pathc(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*arg;
	char	*str;

	path = ft_split(ft_path(envp), ':');
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		arg = ft_strjoin(path[i], "/");
		str = ft_strjoin(arg, cmd);
		free(arg);
		if (access(str, F_OK) == 0)
			return (str);
		i++;
	}
	i = 0;
	free(str);
	return (NULL);
}

void	error(void)
{
	perror("ERROR");
	exit(1);
}

void	exec(char **envp, char *av)
{
	char	**cmd;
	char	*path;
	int		i;

	i = -1;
	cmd = ft_split(av, ' ');
	path = pathc(cmd[0], envp);
	if (!path)
	{
		while (cmd[i++])
			free(cmd);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
	free(path);
}
