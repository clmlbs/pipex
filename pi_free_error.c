/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_free_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <cleblais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:24:31 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/23 15:05:09 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pi_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	free(strs);
}

void	pi_free_everything(t_var *v)
{
	if (v->path)
		pi_free_strs(v->path);
	if (v->cmd)
		pi_free_strs(v->cmd);
}

void	pi_error_dup(int *end, int i)
{
	close(end[i]);
	perror("Dup");
	if (i == 1)
		exit(1);
	else
		return ;
}
