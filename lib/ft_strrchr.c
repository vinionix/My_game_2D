/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@42.rio>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:49:57 by vfidelis          #+#    #+#             */
/*   Updated: 2024/09/23 21:40:52 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return (0);
	}
	if (str[i] == (char)c)
		return (0);
	return (1);
}

/*int main()
{
	const char *str = "Hello, world!";
	char c = 'a';

	char *result = ft_strchr(str, c);
	if (result)
		printf("Caractere '%c' encontrado na posição: %ld\n", c, result - str);
	else
		printf("Caractere '%c' não encontrado.\n", c);

	return (0);
}*/