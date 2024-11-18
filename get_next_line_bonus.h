/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:18:48 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/16 23:06:47 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /*_BUFFER_SIZE_*/

# include <unistd.h>
# include <stdlib.h>

char	*ft_read_file(char *buffer, char *read_line);
char	*get_next_line(int fd);
char	*ft_read_file(char *buffer, char *read_line);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_check_buffer(int fd, char **rl);
char	*ft_get_temp(int bytes_read, char *buffer, char *rl);
int		ft_strlen(const char *c);
char	*ft_extract_line(char *rl);

#endif