/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 10:12:52 by ppaquet           #+#    #+#             */
/*   Updated: 2023/06/15 11:32:55 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Takes a double pointer to string as parameter, free the memory block, 
modify it's value to NULL, and finally return NULL. */
char	*freestr(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

/* Takes the static stash (sta) character string, reads the file descriptor
(fd) in section(s) defined by BUFFER_SIZE. The function joins the temporary
buffer(s) (buf) string to end of 'sta', then verify if '\n' is in the new stash.
If so, the function returns the new stash including the "next line". */
char	*fill_stash(int fd, char *sta)
{
	ssize_t		byte_read;
	char		*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(*buf));
	if (!buf)
		return (freestr(&sta));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
			break ;
		buf[byte_read] = '\0';
		sta = ft_gnl_strjoin(sta, buf);
		if (ft_gnl_strchr(sta, 10))
			break ;
	}
	buf = freestr(&buf);
	if (!sta || byte_read < 0 || (*sta == '\0' && byte_read <= 0))
		return (freestr(&sta));
	return (sta);
}

/* Updates a static char string (stash), so it can return the next_line.
When this function is recalled, it continues to update 'stash' so the following
next_line can be returned, retaining where it stopped reading the file
descriptor (fd), also the previously read characters stored in 'stash'.*/
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*give_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	give_line = NULL;
	give_line = content(stash);
	if (!give_line)
		return (freestr(&stash));
	stash = clean_stash(stash);
	return (give_line);
}
