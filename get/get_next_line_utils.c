#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*resultado;

	len = 0;
	while (s[len])
		len++;
	resultado = (char *)malloc(len + 1);
	i = 0;
	if (!resultado)
	{
		return (NULL);
	}
	while (s[i])
	{
		resultado[i] = s[i];
		i++;
	}
	resultado[i] = '\0';
	return (resultado);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int		i;
	char	caracter;

	i = 0;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*resultado;

	i = 0;
	j = 0;
	resultado = (char *)malloc(
			(ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (resultado == NULL)
		return (NULL);
	while (s1[i])
		resultado[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		resultado[j++] = s2[i++];
	}
	resultado[j] = '\0';
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