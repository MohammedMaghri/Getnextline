/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lencount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaghri <mmaghri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:10:24 by mmaghri           #+#    #+#             */
/*   Updated: 2023/11/18 14:24:25 by mmaghri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nextline.h"

int	lencount(char *string)
{
	int	index;

	index = 0;
	while (string[index])
	{
		index++;
	}
	return (index);
}
