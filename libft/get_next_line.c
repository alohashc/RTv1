/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alohashc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:29:17 by alohashc          #+#    #+#             */
/*   Updated: 2017/02/03 17:18:50 by alohashc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_str(char **str, char **tmp, char **line)
{
	int		count;

	*str = ft_strdup(*tmp);
	ft_strdel(tmp);
	count = ft_check(*str);
	if (count != -1)
	{
		*line = ft_strsub(*str, 0, count);
		*tmp = ft_strsub(*str, count + 1, ft_strlen(*str) - count + 1);
		free(*str);
		return (1);
	}
	return (0);
}

int		create_str(char **str, char *buf, char **tmp)
{
	int		count;
	char	*temp;
	char	*temp1;

	count = ft_check(buf);
	if (count != -1)
	{
		temp = ft_strdup(*str);
		free(*str);
		temp1 = ft_strsub(buf, 0, count);
		*str = ft_strjoin(temp, temp1);
		free(temp);
		free(temp1);
		*tmp = ft_strsub(buf, count + 1, BUFF_SIZE - (count + 1));
		return (1);
	}
	temp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(temp, buf);
	free(temp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*tmp[4096];
	char		buf[BUFF_SIZE + 1];
	char		*str;

	str = ft_strnew(0);
	if (fd < 0 || !line || fd > 4096)
		return (-1);
	if (tmp[fd])
		if (ft_check_str(&str, &tmp[fd], line) == 1)
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		if (create_str(&str, buf, &tmp[fd]) == 1)
			break ;
	}
	*line = ft_strdup(str);
	free(str);
	if (*line[0] == '\0' && ret == 0)
		return (0);
	return (1);
}
