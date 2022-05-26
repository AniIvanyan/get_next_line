/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:00:22 by aivanyan          #+#    #+#             */
/*   Updated: 2022/05/26 20:05:46 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer; //on stack if needed
	char		*char_return;
	static char	*stash;
	ssize_t		read_return;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read_return = 1;
	while (read_return > 0)
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		buffer[read_return] = '\0';
		char_return = ft_strjoin(stash, buffer);
		free(stash);
		stash = char_return;
		if (ft_strchr(stash, '\n'))
			{
				// till new line put in char_return and return
				// delete till new line everything in stash
			}
	}
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s",get_next_line(fd));
}
