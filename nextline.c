/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:37:01 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/20 15:37:51 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "file.h"

#define MAXBUFFER 50

char	*copycontent(char *string)
{
	int	index;
	int increment;
	char *allocation;

	printf("paste = (%s) ", string);
	index =  0 ;
	allocation = malloc(sizeof(char) * sizeof(string) + 1);
		if (!allocation)
			return (NULL);
	while (string[index])
	{
		allocation[index] =  string[index];
		index++;
	}
	allocation[index] = '\0';
	return (allocation);
}

char *ft_get_next_line(int fd)
{
	char	buffer[MAXBUFFER + 1];
	int		thenew;
	int		res;
	static char	*temp;

	res = read(fd, buffer, MAXBUFFER);
	if ( res >= 0)
	{
		buffer[res] = '\0';
		temp = copycontent(buffer);
		thenew = newlineindex(buffer);
		printf("%d\n", thenew);
			return substring(temp ,  thenew);
	}
	return NULL;
}

int main()
{
	int fd ;
	fd = open("text.txt" , O_RDONLY);
	char *result = ft_get_next_line(fd);
	printf("////%s/////" , result);
}

