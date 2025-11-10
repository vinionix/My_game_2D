/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfidelis <vfidelis@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:34:44 by vfidelis          #+#    #+#             */
/*   Updated: 2024/11/05 16:43:38 by vfidelis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	reading(int fd, char **buffer, int *receiver);
char	*line_break(char **buffer);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
void	ft_realloc(char **str1, char *str2);
void	new_pos(char **buffer, char *pos);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
