/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nextline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:02:12 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/18 22:20:56 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXTLINE_H
# define NEXTLINE_H


# include "nextline.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*extract(int fd);
char	*copypaste(char *string);
int		lencount(char *string);
char	*linecheck(char *string);
char	*merge(int fd);

#endif
