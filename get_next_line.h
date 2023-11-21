/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:10:58 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/21 20:28:49 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXT_H
# define GETNEXT_H

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

#define MAXSIZE 1000

int		countlen(char *string);
char	*copythestring(char *string, char *copy);
char	*oneblock(char *string);
char	*tothefrom(char *string , int  len);
char	*extractline(char *string, int len);
char	*thefincish(char *string);
char	*get_next_line(int fd);

#endif
