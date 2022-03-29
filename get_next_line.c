/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:00:22 by aivanyan          #+#    #+#             */
/*   Updated: 2022/03/29 04:52:47 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
	   
char	*get_next_line(int fd)
{
	static char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
}
