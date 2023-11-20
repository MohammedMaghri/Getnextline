/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:55:45 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/20 15:35:13 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include <string.h>
char	*substring(char *string , int end)
{
	int		index;
	char	*allocation;
	int increment;

	increment = 0;
	allocation = malloc(end + 1);
		if (!allocation)
			return (NULL);
	index = 0;
	printf("%d\n" , end);
	printf("000000000000%s\n" , string);
	while (index < end && string[index] != '\0') {
    allocation[increment] = string[index];
    index++;
    increment++;
	}
	printf("%d and %lu\n" , end , strlen(string));
	printf("%d \n" , index);
	allocation[index] = '\0';
	return (allocation);
}
int	newlineindex(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		if (string[index] == '\n')	
			return (index);
		index++;
	}
	return (-1);
}
