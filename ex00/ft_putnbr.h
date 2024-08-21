/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:14:07 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:50:51 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTNBR_H
# define FT_PUTNBR_H
# include "utils.h"

void			ft_putnbr(int nb);
unsigned int	convert_nb_to_str(char *buf, int nb);
unsigned int	carry(char *buf, unsigned int offset);
void			putnbr(char *nbr, unsigned int offset);
#endif
