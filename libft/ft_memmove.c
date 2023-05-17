/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:15:49 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/13 12:08:27 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (ptr_dst > ptr_src)
	{
		while (len > 0)
		{
			ptr_dst[len - 1] = ptr_src[len - 1];
			len--;
		}
		return (dst);
	}
	while (i < len)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
