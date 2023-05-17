/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:17:09 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/13 11:18:31 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;

	new_str = malloc(sizeof(*new_str) * (ft_strlen(s1) + 1));
	if (! new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, ft_strlen(s1) + 1);
	return (new_str);
}
