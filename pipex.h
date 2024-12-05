/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:53:53 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/05 15:43:56 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	exec(char **envp, char *av);
char	*pathc(char *cmd, char **envp);
void	mother(char **av, char **envp, int *fd);
void	child(char **av, char **envp, int *fd);
void	error(void);
char	*ft_path(char **envp);
#endif