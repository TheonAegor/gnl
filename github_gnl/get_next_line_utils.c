/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <taegor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 01:37:52 by taegor            #+#    #+#             */
/*   Updated: 2021/01/10 13:01:03 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen(char *s)
{
	int			len;

	len = 0;
	if (s != 0)
		while (s[len])
			len++;
	return (len);
}

void			*ft_calloc(size_t nmemb, size_t size)
{
	char		*p;
	size_t		len;
	int			i;

	len = nmemb;
	if (!(p = malloc(nmemb * size)))
		return (NULL);
	i = 0;
	while (len)
	{
		p[i] = '\0';
		len--;
		i++;
	}
	return (p);
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

int     ft_strjoin(char **s1, char *s2)
{                
    char    *str; 
    int     i; 
    int     j; 
          
    i = 0;                                                             j = 0;                                                             str = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));                                        
    if (str == 0)   
        return (-1);    
    if (*s1 != 0)       
        while (s1[0][i])      
        {                     
            str[i] = s1[0][i]; 
            i++;                  
        }                         
    while (s2[j] && s2[j] != '\n') 
        str[i++] = s2[j++]; 
    str[i] = '\0'; 
    if (*s1 != 0) 
        free(*s1); 
    *s1 = str; 
    return (1);
}

int				find_n(char *buf)
{
	int			i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
