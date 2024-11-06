/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:18:48 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/05 22:07:34 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif /*_BUFFER_SIZE_*/
 
# include <stdlib.h>
# include <unistd.h>

char	*ft_read_file(char *buffer, char *read_line);
char	*get_next_line(int fd);

#endif