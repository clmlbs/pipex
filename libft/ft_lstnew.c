/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:14:49 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/15 14:21:07 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*new_link;

	new_link = (t_list *)malloc(sizeof(t_list));
	if (!new_link)
		return (NULL);
	new_link->content = content;
	new_link->next = NULL;
	return (new_link);
}
