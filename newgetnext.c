/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newgetnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:42:47 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/18 23:37:07 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nextline.h"
#include <stdio.h>
#define MAXBUFFER 10000

char	*theres(char *string)
{
	int		index;
	char	*allocation;

	allocation = malloc(sizeof(char) * sizeof(string) + 1);
		if (!allocation)
			return (NULL);
	index = 0;
	while (index <= lencount(string))
	{
		allocation[index] = string[index];
		index++;
	}
	allocation[index] = '\0';
	return allocation;
}

char	*extract(int file)
{
	char	*alloction;
	char	Buffer[MAXBUFFER];
	int rrres = read(file , Buffer ,MAXBUFFER);
	alloction = theres(Buffer);
	return (alloction);
}

char	*theeese(char *string)
{
	static int	index;
	char		*allo; 

	allo = malloc(sizeof(char) * sizeof(string) + 1);
	if (!allo)
		return (NULL);
		printf("%d" , lencount(string));
		while (allo[index] != '\n')
		{
			allo[index] = string[index];
			index++;
		}
			printf("(%d)\n" , index);
		allo[index] = '\0';
	return (allo);
}
int main()
{
	int fd = 0;
	fd = open("test.txt" , O_RDONLY);
	char *string = extract(fd);
	printf("%s\n" , string);
	printf("\n **** (%s)\n" , theeese(string)); 
}