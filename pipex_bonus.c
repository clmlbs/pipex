/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:30:01 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/23 15:06:58 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pi_execute(t_var *v, char **envp)
{
	int		i;
	char	*path_cmd;

	i = -1;
	while (v->path[++i])
	{
		path_cmd = ft_strjoin(v->path[i], v->cmd[0]);
		if (!path_cmd)
		{
			perror("ft_strjoin");
			return ;
		}
		if (execve(path_cmd, v->cmd, envp) == -1)
			free(path_cmd);
	}
}

void	pi_child(t_var *v, int *end, char **envp)
{
	if (v->count == 2)
	{
		if (dup2(v->fd1, STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
			pi_error_dup(end, 1);
		else
			pi_execute(v, envp);
	}
	else if (v->count == v->argc - 2)
	{
		if (dup2(v->fd2, STDOUT_FILENO) < 0)
			pi_error_dup(end, 1);
		else
			pi_execute(v, envp);
	}
	else
	{
		if (dup2(end[1], STDOUT_FILENO) < 0)
			pi_error_dup(end, 1);
		else
			pi_execute(v, envp);
	}
}

void	pi_pipe_fork(t_var *v, int *end, char **envp)
{
	pid_t	pid;

	if (pipe(end) < 0)
		perror("Pipe");
	pid = fork();
	if (pid < 0)
		perror("Fork");
	else if (pid == 0)
	{
		close(end[0]);
		if (pi_create_cmds(v))
			pi_child(v, end, envp);
	}
	else
	{
		close(end[1]);
		if (dup2(end[0], STDIN_FILENO) < 0)
			pi_error_dup(end, 0);
		wait(0);
	}
}

void	pi_pipex(int argc, char **argv, char **envp)
{
	t_var	v;
	int		end[2];

	v.path = NULL;
	v.cmd = NULL;
	v.argv = argv;
	v.argc = argc;
	v.count = 2;
	if (!pi_all_checks(argc, envp, &v))
	{
		pi_free_everything(&v);
		return ;
	}
	v.count = 2;
	while (v.count < v.argc - 1)
	{
		pi_pipe_fork(&v, end, envp);
		v.count++;
	}
	pi_free_everything(&v);
}

int	main(int argc, char **argv, char **envp)
{
	pi_pipex(argc, argv, envp);
	return (0);
}
