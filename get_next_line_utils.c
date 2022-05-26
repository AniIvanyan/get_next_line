/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:00:34 by aivanyan          #+#    #+#             */
/*   Updated: 2022/05/26 19:13:22 by aivanyan         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1 && *s1)
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (s2 && *s2)
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}
