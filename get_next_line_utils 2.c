/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:52:43 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/22 14:10:45 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	lencount(char *string)
{
	int index;

	index = 0;
	while (string[index])
	{
		index++;
	}
	return (index);
}
char	*copyorigin(char *string)
{
	int		index;
	char	*allocation;

	index = 0;
	if (!string)
		return (NULL);
	allocation = malloc(sizeof(char) * lencount(string) + 1);
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
char	*fromto(char *string, int line)
{
	int		index;
	char	*allocation;
	index = 0;
	allocation = malloc(sizeof(char) * line + 1);
	if (!allocation)
	{
		free(string);
		return (NULL);
	}
	while (index < line)
	{
		allocation[index] = string[index];
		index++;
	}	
	allocation[index] = '\0';
	return (allocation);
}
char	*movethecontent(char *string, char *tempvar)
{
	int index;
	int increment;
	char *allocation;

	index = 0 ;
	increment = 0;
	if (!string && !tempvar)
		return NULL;
	else if (!string)
		return copyorigin(tempvar);
	else if (!tempvar)
		return copyorigin(string);
	allocation = malloc(sizeof(char) * lencount(string) + lencount(tempvar) + 1);
		if (!allocation)
			return NULL;
		while (tempvar[index])
			allocation[increment++] = tempvar[index++];
		index = 0;
		while (string[index])
			allocation[increment++] = string[index++];
		allocation[increment] = '\0';
		return (allocation);		
}
