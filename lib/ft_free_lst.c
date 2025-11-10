/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 06:39:17 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 08:30:58 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_lst(t_map *a)
{
	t_map	*temp;

	temp = NULL;
	while (a)
	{
		temp = a->next;
		if (a->str)
		{	
			free(a->str);
		}
		free(a);
		a = temp;
	}
}
