/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:07:13 by davi              #+#    #+#             */
/*   Updated: 2024/06/05 12:07:14 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return(0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int		i;
	char	caracter;

	i = 0;
	if (!str)
		return (NULL);
	caracter = (char) c;
	while (str[i])
	{
		if (str[i] == caracter)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == caracter)
		return ((char *) &str[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*resultado;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	resultado = (char *)malloc(
			(ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!resultado)
		return (NULL);
	while (s1[i])
		resultado[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		resultado[j++] = s2[i++];
	}
	resultado[j] = '\0';
	free(s1);
	return (resultado);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*resultado;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	resultado = (char*)malloc((len + 1) * sizeof(char));
	if (resultado == NULL)
		return (NULL);
	while (i < len)
	{
		resultado[i] = s[start + i];
		i++;
	}
	resultado[i] = '\0';
	return (resultado);
}