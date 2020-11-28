#include "get_next_line.h"

int			ft_strlen(char *s)
{
	int		len;

	len = 0;
	while(*s)
	{
		len++;
		s++;
	}
	return (len);
}

size_t		ft_strlcpy(char *dst, const char *src,
		size_t size)
{
	int			result_len;
	size_t		i;

	if (!dst || !src)
		return (0);
	i = 0;
	while(src[i])
		i++;
	result_len = i;
	if (size == 0)
		return (result_len);
	i = 0;
	while (size - 1 > i && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (result_len);
}
static char	*ft_copy(char *dst, const char *src)
{
	int		i;

	if (src[0] == '\0')
	{
		dst[0] = '\0';
		return (dst);
	}
	i = -1;
	while (src[++i] != '\0')
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strdup(const char *s)
{
	char	*p;
	int		len;

	len = 0;
	while(s[len])
		len++;
	if (!s)
		return (NULL);
	if (*s == '\0')
		len = 1;
	if (!(p = malloc(sizeof(char) * len + 1)))
		return (NULL);
	return (ft_copy(p, s));
}

char			*ft_strjoin(char  *s1, char  *s2)
{
	char		*p;
	int			len_s1;
	int			len_s2;
	int			i;

//	printf("Start of strjoin\n");
	i = 0;
	if (!s1)
	{
		return (s2);
	}
	if (!s2)
		return ((char *)s1);
	len_s1 = ft_strlen(s1);
	//printf("len of line = %d\n", len_s1);
	len_s2 = ft_strlen(s2);
	//printf("len of buf = %d\n", len_s2);
	if (!(p = malloc((len_s1 + len_s2 + 1) * sizeof(char))))
		return (NULL);
//	printf("After malloc\n");
	i = 0;
	while (i < len_s1)
	{
//		printf("s1[%d] = %c | ", i,s1[i]);
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
//		printf("s2[%d] = %c \n ", i,s2[i]);
		p[i + len_s1] = s2[i];
		i++;
	}
	p[len_s1 + len_s2] = '\0';
//	printf("End of strjoin");
//	printf("p = %s| buf = %s \n", p, s2);
	return (p);
}
