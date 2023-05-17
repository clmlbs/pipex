/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:15:02 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/13 18:43:16 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	if (!lst)
		return (0);
	i = 1;
	ptr = lst;
	while (ptr->next != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
