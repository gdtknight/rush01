/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:38:30 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/20 22:50:42 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_atoi(char *str)
{
	int	flag;
	int	result;

	result = 0;
	flag = 0;
	while (__is_space__(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = !flag;
		str++;
	}
	while (__is_numeric__(*str))
	{
		result *= 10;
		result += (*str++ - '0');
	}
	if (flag)
		result *= (-1);
	return (result);
}
