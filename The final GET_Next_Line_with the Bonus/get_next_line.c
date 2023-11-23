/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:32:43 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/23 11:14:15 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*buffercopy(int fd, char *string, char *copystring)
{
	int	reared;

	reared = 1;
	while (reared > 0 && linere(string) == 0)
	{
		reared = read(fd, string, BUFFER_SIZE);
		if (reared < 0)
		{
			free(string);
			free(copystring);
			return (NULL);
		}
		string[reared] = '\0';
		copystring = copythcopy(string, copystring);
	}
	free(string);
	if (copystring)
	{
		if (copystring[0] == '\0')
			return (free(copystring), NULL);
	}
	return (copystring);
}

char	*extraxt(char *string, int start, int len)
{
	char	*allocation;

	allocation = malloc(sizeof(char) * lencount(string) + 1);
	if (!allocation)
		return (NULL);
	while (string[start] && start < len)
	{
		allocation[start] = string[start];
		start++;
	}
	allocation[start] = '\0';
	return (allocation);
}

char	*newlinefinder(char *string)
{
	int	index;

	index = 0;
	if (!string)
		return (NULL);
	while (string[index] && string[index] != '\n')
		index++;
	if (string[index] == '\n')
		index++;
	return (extraxt(string, 0, index));
}

char	*freethfinal(char *string)
{
	int		index;
	char	*res;

	index = 0;
	while (string[index] && string[index] != '\n')
		index++;
	if (string[index] == '\n')
		index++;
	res = onestringcopied(&string[index]);
	free(string);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*copystring;
	char		*line;
	char		*string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	string = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!string)
		return (NULL);
	string[0] = '\0';
	copystring = buffercopy(fd, string, copystring);
	line = newlinefinder(copystring);
	if (!copystring)
		return (NULL);
	copystring = freethfinal(copystring);
	return (line);
}
