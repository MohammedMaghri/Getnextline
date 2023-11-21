/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:10:53 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/21 20:28:34 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int findnewline(char *string)
{
	int index;

	index = 0;
	while (string[index])
	{
		if (string[index] == '\n')
			return (index + 1);
		index++ ;
	}
	return (-1);
}

char *allocatetillline(int fd, char *string, char *thecopy)
{
	int	byteread;	
	int	index;

	index = 0;
	byteread = 1;
	while (byteread > 0)
	{
		byteread = read(fd, string, MAXSIZE);
		if (byteread < 0)
		{
			free(string);
			free(thecopy);
			return (NULL);
		}
	}
	thecopy = copythestring(string,thecopy);
	free(string);
	if (thecopy[0] == '\0')
	{
		return(free(thecopy), NULL);
	}
	return (thecopy);
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;
	char		*line;
	int			newline;

	newline = 0;
	if ((fd < 0 && fd > OPEN_MAX) || MAXSIZE < 0)
		return (NULL);
	string = malloc(sizeof(char) * MAXSIZE + 1);		
		if (!string)
			return (NULL);
	buffer = allocatetillline(fd, string ,buffer);
	newline = findnewline(buffer);
	line = extractline(buffer, newline);
	buffer = thefincish(buffer);
	return (line);
}
