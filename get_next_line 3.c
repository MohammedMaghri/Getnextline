/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:39:25 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/22 15:12:02 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	linecount(char *string)
{
	int index;

	index = 0;
	if (!string)
		return (0);
	while (string[index])
	{
		if (string[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}
char	*stringcopy(int fd, char *string, char *tempvar)
{
	int readreturn;

	readreturn = 1;
	if (readreturn > 0 && linecount(string) == 0)
	{
		readreturn = read(fd, string, BUFFER_SIZE);
		if (readreturn <= 0)
		{
			free(string);
			free(tempvar);
			return (NULL);
		}
		string[BUFFER_SIZE] = '\0';
		tempvar = movethecontent(string, tempvar);
	}
	free(string);
	if (tempvar)
	{
		if (tempvar[0] == '\0')
			free(tempvar);
			return (NULL);
	}
	return (tempvar);
}
char *lineextra(char *string)
{
	int index;

	index = 0 ;
	if (!string)
		return (NULL);
	while (string[index] && string[index] != '\n')
		index++;
	if (string[index] == '\n')
		index++;
	return fromto(string, index);
}
char	*stopindex(char *string)
{
	int index;
	char *res;

	index = 0 ;
	if (!string)
		return NULL;
	while (string[index] && string[index] != '\n')
		index++;
	if (string[index] == '\n')
		index++;
	res = copyorigin(&string[index]);
	free(string);
	return (res);	
}
char	*get_next_line(int fd)
{
	static char	*tempvar;
	char		*string;
	char		*line;

	if (fd < 0 && fd > OPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	string = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!string)
		return NULL;
	tempvar = stringcopy(fd, string, tempvar);
	line = lineextra(tempvar);
	tempvar = stopindex(tempvar);
	return line;
}
