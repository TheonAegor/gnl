#include "get_next_line.h"

int				ft_strlen(char *s)
{
	int			len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

void			*ft_calloc(size_t nmemb, size_t size)
{
	char		*p;
	size_t		len;

	len = nmemb;
	if (!(p = malloc(nmemb * size)))
		return (NULL);
	while (nmemb)
	{
		*p = '\0';
		nmemb--;
		p++;
	}
	return (p - len);
}

char			*ft_strdup(const char *s)
{
	char		*p;
	int			len;
	int			i;

	len = ft_strlen((char *)s);
	if (!s)
		return (NULL);
	if (*s == '\0')
		len = 1;
	if (!(p = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*p;
	int			len_s1;
	int			len_s2;
	int			i;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(p = ft_calloc((len_s1 + len_s2 + 1), sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len_s1)
		p[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		p[i + len_s1] = s2[i];
	p[len_s1 + len_s2] = '\0';
	return (p);
}

char			*ft_strchr(char *s, int c)
{
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	if (ft_strlen(s) == 0)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}
