/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albben-a <albben-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:53:25 by albben-a          #+#    #+#             */
/*   Updated: 2026/03/09 20:30:30 by albben-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	*get_line(char **big)
{
	char	*line;
	char	*end;
	char	*tmp;

	end = ft_strchr(*big, '\n');
	if (end)
	{
		line = ft_substr(*big, 0, end - *big + 1);
		tmp = ft_strdup(end + 1);
		if (!tmp || !line)
		{
			free(line);
			free(tmp);
			return (free(*big), *big = NULL, NULL);
		}
		free(*big);
		*big = tmp;
	}
	else
	{
		line = ft_strdup(*big);
		free(*big);
		*big = NULL;
	}
	return (line);
}

static char	*ft_free(char **big, char *buffer)
{
	free(buffer);
	buffer = NULL;
	if (*big && **big != '\0')
		return (get_line(big));
	if (*big)
	{
		free(*big);
		*big = NULL;
	}
	return (NULL);
}

static char	*create_big(char **big, char *buffer)
{
	char	*tmp;

	tmp = *big;
	if (!*big)
		*big = ft_strdup(buffer);
	else
		*big = ft_strjoin(*big, buffer);
	if (!*big)
	{
		free(tmp);
		*big = NULL;
		return (NULL);
	}
	free(tmp);
	return (*big);
}

static char	*get_big(int fd, char **big, char *buffer)
{
	int		bytes;

	while (!*big || !ft_strchr(*big, '\n'))
	{
		bytes = read(fd, buffer, 4);
		if (bytes < 0)
		{
			free (buffer);
			if (*big)
			{
				free(*big);
				*big = NULL;
			}
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (bytes == 0)
			return (ft_free(big, buffer));
		if (!create_big(big, buffer))
			return (free(buffer), NULL);
	}
	free(buffer);
	return (*big);
}

char	*get_next_line(int fd)
{
	static char		*big = NULL;
	char			*buffer;
	char			*line;

	if (fd < 0)
		return (NULL);
	buffer = malloc(4 + 1);
	if (!buffer)
	{
		if (big)
		{
			free(big);
			big = NULL;
		}
		return (NULL);
	}
	big = get_big(fd, &big, buffer);
	if (!big || *big == '\0')
		return (NULL);
	line = get_line(&big);
	return (line);
}
