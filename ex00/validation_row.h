/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_row.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:33 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:03:50 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_ROW_H
# define VALIDATION_ROW_H
# include "utils.h"
# include "ft_atoi.h"

int	is_valid_row(unsigned int **map, unsigned int size, unsigned int row);
int	is_unique_row(unsigned int **map, unsigned int size, unsigned int row);
int	is_valid_rowleft(unsigned int **map, unsigned int size, unsigned int row);
int	is_valid_rowright(unsigned int **map, unsigned int size, unsigned int row);
#endif
