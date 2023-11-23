/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:16:18 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/23 11:16:32 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	lencount(char *string)
{
	int	index;

	index = 0;
	if (!string)
	{
		return (0);
	}
	while (string[index])
	{
		index++;
	}
	return (index);
}

char	*onestringcopied(char *string)
{
	int		index;
	char	*allocation;

	if (!string)
		return (NULL);
	allocation = malloc(sizeof(char) * lencount(string) + 1);
	if (!allocation)
		return (NULL);
	index = 0;
	while (string[index])
	{
		allocation[index] = string[index];
		index++;
	}
	allocation[index] = '\0';
	return (allocation);
}

int	linere(char *string)
{
	int	index;

	index = 0;
	if (string[0] == '\0')
	{
		return (0);
	}
	while (string[index])
	{
		if (string[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*copythcopy(char *string, char *copystring)
{
	int		index;
	int		increment;
	char	*allocation;

	increment = 0;
	index = 0;
	if (!copystring && !string)
		return (NULL);
	else if (!copystring)
		return (onestringcopied(string));
	else if (!string)
		return (onestringcopied(copystring));
	allocation = malloc(sizeof(char)
			* (lencount(string) + lencount(copystring)) + 1);
	while (copystring[index])
		allocation[increment++] = copystring[index++];
	index = 0;
	while (string[index])
		allocation[increment++] = string[index++];
	allocation[increment] = '\0';
	return (free(copystring), allocation);
}
