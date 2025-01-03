/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:47:03 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/09 12:27:13 by omgorege         ###   ########.fr       */
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
	return (path);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*pathc(char *cmd, char **envp)
{
	int		i;
	char	**path;
	char	*arg;
	char	*str;
	char	*tmp;

	tmp = ft_path(envp);
	path = ft_split(tmp, ':');
	free(tmp);
	i = -1;
	while (path[++i])
	{
		arg = ft_strjoin(path[i], "/");
		str = ft_strjoin(arg, cmd);
		free(arg);
		if (access(str, F_OK) == 0)
		{
			ft_free(path);
			return (str);
		}
		free(str);
	}
	ft_free(path);
	return (NULL);
}

void	error(char *hat)
{
	perror(hat);
	exit(1);
}

void	exec(char **envp, char *av)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = pathc(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		error(ERR_CMD);
	}
	if (execve(path, cmd, envp) == -1)
	{
		error(ERR_PRC);
	}
	free(path);
}
