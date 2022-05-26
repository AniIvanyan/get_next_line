/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:00:34 by aivanyan          #+#    #+#             */
/*   Updated: 2022/04/08 19:30:13 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*locate;
	int		i;

	i = 1;
	locate = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			locate = (char *)s;
			i = 0;
			break ;
		}
		s++;
	}
	if (i)
		if ((char)c == '\0')
			locate = (char *)s;
	return (locate);
}