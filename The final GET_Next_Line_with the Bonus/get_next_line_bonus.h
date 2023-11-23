/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:30 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/23 11:17:53 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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