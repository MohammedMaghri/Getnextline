/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:35:28 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/22 13:14:56 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

char	*fromto(char *string, int line);
char	*get_next_line(int fd);
char	*stringcopy(int fd, char *string, char *tempvar);
int		lencount(char *string);
char	*copyorigin(char *string);
char	*movethecontent(char *string, char *tempvar);

#endif

