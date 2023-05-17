/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:15:13 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/07 13:15:15 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc_c;
	unsigned char	*str;
	size_t			i;

	uc_c = c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc_c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
