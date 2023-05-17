/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:32:39 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/23 15:05:52 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pi_cmds_exist(char **path, char **cmd)
{
	int		i;
	char	*path_cmd;

	i = -1;
	while (path[++i])
	{
		path_cmd = ft_strjoin(path[i], cmd[0]);
		if (!path_cmd)
		{
			perror("ft_strjoin");
			return (0);
		}
		if (access(path_cmd, X_OK) == 0)
		{	
			free(path_cmd);
			return (1);
		}
		free(path_cmd);
	}
	ft_printf("command not found: %s\n", cmd[0]);
	return (0);
}

int	pi_create_cmds(t_var *v)
{
	int		i;

	i = -1;
	if (v->cmd)
		pi_free_strs(v->cmd);
	v->cmd = ft_split(v->argv[v->count], ' ');
	if (!v->cmd)
		return (0);
	return (1);
}

int	pi_create_path(char **envp, t_var *v)
{
	int	i;
	int	line;

	i = -1;
	while (envp[++i])
	{
		if (!strncmp(envp[i], "PATH=", 5))
		{
			line = i;
			break ;
		}
	}
	v->path = pi_split(envp[i] + 5, ':');
	if (!v->path)
		return (0);
	return (1);
}

int	pi_check_argc_open(int argc, t_var *v)
{
	if (argc < 5)
	{
		ft_printf("Error: bad number of arguments\n");
		return (0);
	}
	v->fd1 = open(v->argv[1], O_RDONLY);
	if (v->fd1 == -1)
	{
		perror("Error");
		return (0);
	}
	v->fd2 = open(v->argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (v->fd2 == -1)
	{
		close(v->fd1);
		perror("Error");
		return (0);
	}
	return (1);
}

int	pi_all_checks(int argc, char **envp, t_var *v)
{
	if (!pi_check_argc_open(argc, v))
		return (0);
	if (!pi_create_path(envp, v))
	{
		close(v->fd1);
		close(v->fd2);
		return (0);
	}
	while (v->count < argc - 1)
	{
		if (!pi_create_cmds(v) || !pi_cmds_exist(v->path, v->cmd))
		{
			close(v->fd1);
			close(v->fd2);
			return (0);
		}
		v->count++;
	}
	return (1);
}
