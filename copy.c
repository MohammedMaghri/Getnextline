/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:01:28 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/18 16:21:20 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nextline.h"
#include <stdlib.h>
#include <stdio.h>

char	*copypaste(char *string)
{
	int		index;
	int		increment;
	char	*allocation;

	index = 0;
	increment = 0;
	allocation = malloc(sizeof(char) * lencount(string) + 1);
	while (string[increment])
	{
		allocation[index] = string[increment];
		index++ ;
		increment++;
	}
	allocation[index] = '\0';
	return (allocation); 
}
