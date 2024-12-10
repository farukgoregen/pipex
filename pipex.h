/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:53:53 by omgorege          #+#    #+#             */
/*   Updated: 2024/12/09 11:07:07 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_INFILE "Dosya hatasi"
# define ERR_OUTFILE "Outfile hatasi"
# define ERR_INPUT "Hatali Arguman"
# define ERR_PIPE "Pipe Hatasi"
# define ERR_PATH "Path bulunamadi"
# define ERR_CMD "Komut Bulunamadi"
# define ERR_PRC "process hatasi"
# define ERR_ENV "env hatasi"

void	exec(char **envp, char *av);
char	*pathc(char *cmd, char **envp);
void	mother(char **av, char **envp, int *fd);
void	child(char **av, char **envp, int *fd);
void	error(char *hat);
char	*ft_path(char **envp);
void	ft_free(char **str);
#endif