/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 16:29:57 by nkolle            #+#    #+#             */
/*   Updated: 2022/02/28 17:24:41 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	check_quotes(char *news)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	while (news[i])
	{
		if (news[i] == '"')
			counter++;
		i++;
	}
	if (counter % 2 == 0)
		return (1);
	return (0);
}

static char	*ft_check_c(const char *str, char *news, char cee)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && check_quotes(news) == 1)
			{
				while(str[++i] != '"')
					news[i] = str[i];
				if (str[i] == '"')
					news[i] = '\0';
			}
		if (str[i] != cee)
			news[i] = str[i];
		else if (str[i] == cee)
			news[i] = '\0';
		i++;
	}
	news[i] = '\0';
	return (news);
}

static size_t	ft_wordcount(char *newstr, size_t len)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < len)
	{
		if (newstr[i] == '\0' && newstr[i + 1] != newstr[i])
			ret++;
		i++;
	}
	i = 0;
	while (newstr[i] != '\0')
	{
		if (newstr[len] == '\0')
			return (ret + 1);
		i++;
	}
	return (ret);
}

static char	**ft_strsav(char **ptr, char *newstr, size_t count, size_t len_s)
{
	size_t	nsi;
	size_t	i;

	i = 0;
	nsi = 0;
	newstr[len_s] = '\0';
	while (newstr[nsi] == '\0' && i < count)
		nsi++;
	while (i < count)
	{
		ptr[i] = ft_strdup(&newstr[nsi]);
		if (ptr[i] == NULL)
		{
			free(ptr);
			free(newstr);
			return (NULL);
		}
		nsi += ft_strlen(&newstr[nsi]);
		i++;
		while (newstr[nsi] == '\0' && i < count)
			nsi++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	*newstr;
	char	**ptr;
	size_t	counter;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	newstr = (char *) malloc(sizeof(char) * (len_s + 1));
	if (newstr == NULL)
		return (NULL);
	ft_check_c(s, newstr, c);
	counter = ft_wordcount(newstr, len_s);
	ptr = malloc(sizeof(char *) * (counter + 1));
	if (ptr == NULL)
	{
		free(newstr);
		return (NULL);
	}
	ft_strsav(ptr, newstr, counter, len_s);
	ptr[counter] = NULL;
	free(newstr);
	return (ptr);
}