/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:33:27 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/22 22:58:02 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "get_next_line.h"
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1

# endif

int		linere(char *string);
int		lencount(char *string);
char	*onestringcopied(char *string);
char	*copythcopy(char *string, char *copystring);
char	*get_next_line(int fd);
char	*buffercopy(int fd, char *string, char *copystring);
#endif