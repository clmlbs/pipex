/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:50:17 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/14 07:47:03 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int		size;
	int		i;
	t_list	*new;
	t_list	*buf;

	if (!lst || !f || !del)
		return (NULL);
	size = ft_lstsize(lst);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		del((void *)lst->content);
		return (NULL);
	}
	buf = lst->next;
	i = 1;
	while (i < size)
	{
		ft_lstadd_back(&new, ft_lstnew(f(buf->content)));
		buf = buf->next;
		i++;
	}
	return (new);
}
