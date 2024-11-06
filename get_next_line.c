/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:14:21 by rheringe          #+#    #+#             */
/*   Updated: 2024/11/05 23:06:38 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(char *buffer, char *read_line);
int		ft_strlen(const char *c);
static char *ft_extract_line(char *read_line);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

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
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) //bytes_read = 1 
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(read_line, buffer);
		free(read_line);
		read_line = temp;
		if (ft_strchr(read_line, '\n'))
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || (bytes_read == 0 && (!read_line || read_line[0] == '\0')))
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

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		len;
	int		i;

	len = 0;
	while (s[len] != '\0')
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_s;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join_s = (char *)malloc(((len_s1 + len_s2 + 1) * sizeof(char)));
	if (!join_s)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		join_s[i] = s1[i];
	j = 0;
	while ((j) < len_s2)
	{
		join_s[i] = s2[j];
		i++;
		j++;
	}
	join_s[i] = '\0';
	return (join_s);
}


// #include <fcntl.h> // para open
// #include <stdio.h> // para printf e perror
// #include <stdlib.h> // para exit
// #include "get_next_line.h"

// int main(void)
// {
//     int fd = open("file.txt", O_RDONLY); // abre o arquivo em modo leitura
//     char *line;

//     if (fd == -1) // verifica se o arquivo foi aberto corretamente
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     // Lê e imprime cada linha até o fim do arquivo
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line); // imprime a linha lida
//         free(line); // libera a memória alocada para a linha
//     }
// 	printf("%s", line);
//     close(fd); // fecha o arquivo
//     return (0);
// }
