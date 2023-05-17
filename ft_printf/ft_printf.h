/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleblais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:22:57 by cleblais          #+#    #+#             */
/*   Updated: 2022/12/05 11:00:08 by cleblais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_check_well_used(const char *str);
void	ft_put_format(char c, int *count, va_list args);
void	ft_putchar_c(char c, int *count);
void	ft_putstr_s(char *s, int *count);
void	ft_putnbr_p(void *p, int *count);
void	ft_putnbr_i(int nb, int *count);
void	ft_putnbr_u(unsigned int nb, int *count);
void	ft_putnbr_x(unsigned int nb, char c, int *count);

#endif
