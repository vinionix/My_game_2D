/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:05:13 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/16 04:05:13 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_last_lst(t_matrix *ft_matrix)
{
	size_t	i;
	t_map	*receiver;

	i = 0;
	receiver = ft_matrix->ft_map;
	while (receiver->next->next != NULL)
		receiver = receiver->next;
	while (receiver->str[i] != '\0')
		i++;
	if (receiver->str[i - 1] == '\n')
	{
		ft_free_lst(ft_matrix->ft_map);
		ft_error();
	}
	return (i);
}
