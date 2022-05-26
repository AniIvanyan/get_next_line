/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 03:00:22 by aivanyan          #+#    #+#             */
/*   Updated: 2022/04/08 19:27:25 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
	   
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*stash;

	read(fd, buffer, BUFFER_SIZE);
	
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s",get_next_line(fd));
}
