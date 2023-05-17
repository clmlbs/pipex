/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:30:04 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/18 17:29:31 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	if (!str || !ft_check_well_used(str))
		return (-1);
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_put_format(str[i], &count, args);
			i++;
		}
		else
		{
			ft_putchar_c(str[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}
