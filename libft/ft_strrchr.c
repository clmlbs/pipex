/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:18:45 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/13 13:08:02 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc_c;
	unsigned char	*str;
	int				i;

	uc_c = (unsigned char)c;
	str = (unsigned char *)s;
	i = ft_strlen((char *)str);
	while (i > 0)
	{
		if (str[i] == uc_c)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == uc_c)
		return ((char *)&str[i]);
	return (NULL);
}
