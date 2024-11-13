/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_linex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:14:21 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/11 12:15:47 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_line(char *read_line);

char	*get_next_line(int fd)
{
	static char		*read_line;
	char			*buffer;
	char			*line;
	char			*temp;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	if (read_line == NULL)
		read_line = ft_strdup("");
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(read_line, buffer);
		free(read_line);
		read_line = temp;
		if (ft_strchr(read_line, '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!read_line
				|| read_line[0] == '\0')))
		return (free(read_line), read_line = NULL);
	line = ft_extract_line(read_line);
	temp = ft_strdup(read_line + ft_strlen(line));
	free(read_line);
	read_line = temp;
	return (line);
}

static char	*ft_extract_line(char *read_line)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (read_line[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = read_line[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
