/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:14:07 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 19:59:45 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTNBR_H
# define FT_PUTNBR_H
# include "utils.h"

void			ft_putnbr(int nb);
unsigned int	__convert_nb_to_str__(char *buf, int nb);
unsigned int	__carry__(char *buf, unsigned int offset);
void			__putnbr__(char *nbr, unsigned int offset);
#endif
