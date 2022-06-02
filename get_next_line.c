/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:00:22 by aivanyan          #+#    #+#             */
/*   Updated: 2022/06/02 14:36:28 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_return_line(char *stash)
{
	char	*new_line;

	if (!stash)
		return (NULL);
	new_line = ft_strchr(stash, '\n');
	if (new_line)
		return (ft_substr(stash, 0, new_line - stash + 1));
	return (ft_substr(stash, 0, ft_strlen(stash)));
}

char	*ft_update_stash(char **stash)
{
	char	*new_line;
	char	*temp;
	char	*return_line;

	// if(!(*stash) || !(**stash))
	// {
	// 	free(*stash);
	// 	return (NULL);
	// }
	if (!(*stash))
		return (NULL);
	if (!(**stash))
	{
		temp = *stash;
		*stash = NULL;
		free(temp);
		return (NULL);
	}
	return_line = ft_get_return_line(*stash);
	new_line = ft_strchr(*stash, '\n');
	if (new_line)
	{
		temp = ft_substr(new_line + 1, 0, ft_strlen(new_line + 1));
		free(*stash);
		*stash = temp;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
	return (return_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	static char	*stash;
	ssize_t		read_return;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	//read_return = read(fd, buffer, BUFFER_SIZE);
	read_return = 1;
	while (read_return > 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		if (read_return < 0)
			free(buffer);
		if (read_return < 0)
			return (NULL);
		buffer[read_return] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(buffer);
	return (ft_update_stash(&stash));
}
