/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:14:08 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:51:15 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr.h"

void	ft_putnbr(int nb)
{
	char			buf[12];
	unsigned int	offset;

	offset = convert_nb_to_str(buf, nb);
	putnbr(buf, offset);
}

unsigned int	convert_nb_to_str(char *buf, int nb)
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
		offset = carry(buf, offset);
	return (offset);
}

unsigned int	carry(char *buf, unsigned int offset)
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

void	putnbr(char *nbr, unsigned int offset)
{
	while (offset--)
		write(1, &nbr[offset], 1);
}
