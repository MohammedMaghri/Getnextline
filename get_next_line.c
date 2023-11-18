/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:11:06 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/18 22:43:02 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nextline.h"

#define MAXBUFFER 100000

void	freemory(char *string)
{
	int	index ;

	index = 0 ;
	while (string[index])
	{
		string[index] = 0;
		index++ ;
	}
}

char	*extract(int fd)
{
	char		ffer[MAXBUFFER];
	static int	start;
	int			res;
	char		*allocation;

	res = 0 ;
	start = 0 ;
	res = read(fd, ffer, MAXBUFFER);
	allocation = copypaste(ffer);
	return (allocation);
}

char	*linecheck(char *string)
{
	int			index;
	static char	*allocation;
	int			increment;

	increment = 0;
	index = 0;
	allocation = malloc(sizeof(char) * (lencount(string) + 1));
	if (!allocation)
		return (NULL);
	while (string[index] && string[index] != '\n')
		index++;
	index++ ;
	while (increment < index)
	{
		allocation[increment] = string[increment];
		increment++;
	}
	allocation[increment] = '\0';
	return (allocation);
}

char	*moveto(char *string)
{
	int		index;
	char	*allocation ;

	index = 0;
	allocation = malloc(sizeof(char) * sizeof(string) + 1);
	if (!allocation)
		return (NULL);
	while (string[index])
	{
		allocation[index] = string[index];
		index++;
	}
	allocation[index] = '\0';
	return (allocation); 
}

char	*merge(int fd)
{
	char		*string;
	char		*thestring;
	static char	*res; 
	string = extract(fd);
	thestring = linecheck(string);
	res = moveto(thestring);
	return (resw);
}
