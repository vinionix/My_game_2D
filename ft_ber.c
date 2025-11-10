/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:23:33 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/27 20:28:32 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber(char *str)
{
	int		i;
	int		j;
	char	ber[5];

	ber[0] = '.';
	ber[1] = 'b';
	ber[2] = 'e';
	ber[3] = 'r';
	ber[4] = '\0';
	i = (int)ft_strlen(str);
	j = 0;
	while (str[i] != '.')
	{
		if (i < 0)
			ft_error();
		i--;
	}
	while (ber[j] == str[i] && ber[j] != '\0')
	{
		j++;
		i++;
	}
	if (ber[j] != '\0' || str[i] != '\0')
		ft_error();
}
