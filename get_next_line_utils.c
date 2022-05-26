/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:00:34 by aivanyan          #+#    #+#             */
/*   Updated: 2022/05/27 01:35:56 by aivanyan         ###   ########.fr       */
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*src_temp;
	char	*dest_temp;
	size_t	i;

	src_temp = (char *)src;
	dest_temp = (char *)dest;
	i = 0;
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		i++;
	}
	return (dest_temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	size = ft_strlen(s);
	if (size < len)
		len = size;
	if (start >= size)
		len = 0;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	substr[len] = '\0';
	return (ft_memcpy(substr, s + start, len));
}
