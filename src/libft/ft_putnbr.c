/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urassh <urassh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:30:52 by urassh            #+#    #+#             */
/*   Updated: 2025/09/27 18:41:22 by urassh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	ft_putchar(char c);

void	ft_putnbr(int n)
{
	int	sign;

	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		ft_putstr("-");
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}
