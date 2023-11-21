/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:43:47 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/21 20:25:54 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int countlen(char *string)
{
	int index;

	index = 0;
	while (string[index])
	{
		index++;
	}
	return index;
}
char *oneblock(char *string)
{
	char	*allocation;
	int		index;

	index = 0;
	allocation = malloc(sizeof(char) * countlen(string) + 1);
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
char	*tothefrom(char *string , int len)
{
	char *allocation;
	int index;

	index = 0 ;
	allocation = malloc(sizeof(char) + (len + 1));
	while (index < len)
	{
		allocation[index] = string[index];
		index++;
	}
	allocation[index] = '\0';
	return (allocation);
}
char *extractline(char *string, int len)
{
	int index;
	char *allocation ;

	if (len == -1)
		return (oneblock(string));
	index = 0 ;
	while (string[index] && string[index] != '\n')
		index++ ;
	if (string[index] == '\n')
		index++;
	allocation = tothefrom(string, len);
	return (allocation);
}
char	*thefincish(char *string)
{
	int index ;
	char *res;

	index = 0;
	while (string[index] && string[index] != '\n')
		index++;
	if (string[index] == '\n')
		index++;
	res = oneblock(&string[index]);
	free(string);
	return (res);
}
char	*copythestring(char *string, char *copy)
{
	int	index;
	int	increment;
	char *allocation;

	if (!string && !copy)
		return (NULL);
	if (!string)
		return (oneblock(copy));
	if (!copy)
		return (oneblock(string));
	allocation = malloc(sizeof(char) * (countlen(string) + countlen(copy))+ 1);
		if (!allocation)
			return (NULL);
	index = 0;
	increment = 0;
	while (string[index])
		allocation[increment++] = string[index++];
	index =  0;
	while (copy[index])
		allocation[increment++]  = copy[index++];
	allocation[increment] = '\0';
	return (allocation);
}
