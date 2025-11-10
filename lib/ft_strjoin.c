/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:09:39 by vfidelis          #+#    #+#             */
/*   Updated: 2025/02/13 05:34:53 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*receptor;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	receptor = (char *)malloc(sizeof(char) * (len + 1));
	if (receptor == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		receptor[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		receptor[i++] = s2[j++];
	}
	receptor[i] = '\0';
	return (receptor);
}

/*int main()
{
	char    arr1[] = "Hello!";
	char    arr2[] = "World";
	char    *arr_receptor;

	arr_receptor = ft_strjoin(arr1, arr2);
	printf("Resultado da concatenação: %s", arr_receptor);
	free(arr_receptor);
}*/
