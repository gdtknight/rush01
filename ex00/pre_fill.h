/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_fill.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:11:44 by yoshin            #+#    #+#             */
/*   Updated: 2024/08/21 21:24:16 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRE_FILL_H
# define PRE_FILL_H

void	fill_highest_row(unsigned int **map, unsigned int size);
void	fill_highest_col(unsigned int **map, unsigned int size);
void	fill_first_highest_box(unsigned int **map, unsigned int size);
void	fill_ordered_row(unsigned int **map, unsigned int size);
void	fill_ordered_col(unsigned int **map, unsigned int size);
#endif
