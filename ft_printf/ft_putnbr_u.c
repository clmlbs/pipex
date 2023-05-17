/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:09:12 by cleblais          #+#    #+#             */
/*   Updated: 2022/11/17 18:26:52 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nb, int *count)
{
	char	chiffre;

	if (nb >= 10)
	{
		ft_putnbr_u(nb / 10, count);
		ft_putnbr_u(nb % 10, count);
	}
	else
	{
		chiffre = nb + '0';
		write(1, &chiffre, 1);
		*count += 1;
	}
}
