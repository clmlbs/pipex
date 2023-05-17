/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:18:36 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/13 13:29:46 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (!needle[j])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] && haystack[i + j] == needle[j]
			&& i + j < len && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
		j = 0;
	}
	return (NULL);
}
