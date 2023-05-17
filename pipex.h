/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:08:13 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/23 15:06:37 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_var
{
	int		fd1;
	int		fd2;
	int		argc;
	char	**argv;
	char	**path;
	char	**cmd;
	int		count;
}	t_var;

int		pi_all_checks(int argc, char **envp, t_var *v);
int		pi_check_argc_open(int argc, t_var *v);
void	pi_child(t_var *v, int *end, char **envp);
int		pi_cmds_exist(char **path, char **cmd);
int		pi_create_cmds(t_var *v);
int		pi_create_path(char **envp, t_var *v);
void	pi_error_dup(int *end, int i);
void	pi_execute(t_var *v, char **envp);
void	pi_free_everything(t_var *v);
void	pi_free_strs(char **strs);
void	pi_pipex(int argc, char **argv, char **envp);
void	pi_pipe_fork(t_var *v, int *end, char **envp);
void	pi_child(t_var *v, int *end, char **envp);
char	**pi_split(char *s, char c);
char	*pi_substr(char *s, unsigned int start, size_t len);
int		main(int argc, char **argv, char **envp);

#endif
