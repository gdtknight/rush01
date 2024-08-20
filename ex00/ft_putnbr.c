/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:14:08 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 23:21:19 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr.h"

void	ft_putnbr(int nb)
{
	char			buf[12];
	unsigned int	offset;

	offset = __convert_nb_to_str__(buf, nb);
	__putnbr__(buf, offset);
}

unsigned int	__convert_nb_to_str__(char *buf, int nb)
{
	unsigned int	offset;
	int				flag;

	flag = 0;
	offset = 0;
	if (nb == 0)
	{
		buf[offset++] = '0';
		return (offset);
	}
	if (nb < 0)
	{
		flag = 1;
		nb += 1;
		nb *= (-1);
	}
	while (nb > 0)
	{
		buf[offset++] = '0' + (nb % 10);
		nb /= 10;
	}
	if (flag)
		offset = __carry__(buf, offset);
	return (offset);
}

unsigned int	__carry__(char *buf, unsigned int offset)
{
	unsigned int	cur;
	int				num;

	cur = 0;
	num = buf[cur] - '0';
	while (num + 1 == 10)
	{
		buf[cur++] = '0';
		num = (buf[cur] - '0');
	}
	if (cur == offset)
		buf[offset++] = '1';
	else
		buf[cur] = '0' + (num + 1);
	buf[offset++] = '-';
	return (offset);
}

void	__putnbr__(char *nbr, unsigned int offset)
{
	while (offset--)
		write(1, &nbr[offset], 1);
}
