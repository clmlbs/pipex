/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_%_alone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:38:55 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/17 14:14:22 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_well_used(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] != 'c' && str[i] != 's' && str[i] != 'p'
				&& str[i] != 'd' && str[i] != 'i' && str[i] != 'u'
				&& str[i] != 'x' && str[i] != 'X' && str[i] != '%')
				return (0);
		}
		i++;
	}
	return (1);
}
