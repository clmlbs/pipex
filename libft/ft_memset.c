/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:15:58 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/13 10:58:57 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*ptr;
	unsigned char	c_uc;

	i = 0;
	ptr = b;
	c_uc = c;
	while (i < len)
	{
		ptr[i] = c_uc;
		i++;
	}
	return (b);
}
