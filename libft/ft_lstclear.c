/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:13:49 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/14 11:31:32 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (lst && del)
	{
		while (*lst)
		{
			buf = (*lst)->next;
			ft_lstdelone((*lst), del);
			*lst = buf;
		}
	}
}
