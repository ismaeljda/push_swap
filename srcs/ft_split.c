/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isall <isall@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:00:42 by isall             #+#    #+#             */
/*   Updated: 2024/10/28 10:00:42 by isall            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static  int ft_len(char const *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
            count++;
        while (s[i] && s[i] != c)
            i++;
    }
    return (count);
}

static char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int  len_word(char const *s, char c)
{
    int i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i);
}
static char    *ft_word(char const *s, char c)
{
    char    *str;
    int     len;
    int     i;

    len = len_word(s, c);
    str = (char *)malloc((len + 1) * sizeof(char));
    i = 0;
    if (!str)
        return (NULL);
    while (i < len)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
char    **ft_split_2(char const *s, char c)
{
    char    **tab;
    int     i;
    int     j;

    tab = (char **)malloc((ft_len(s,c) + 1) * sizeof (char*));
    i = 0;
    j = 0;
    if (!tab)
        return (NULL);
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (s[i])
        {
            tab[j] = ft_word(&s[i], c);
            if (!tab[j])
                return (free_array(tab, j)); 
            j++;
        }
        while (s[i] && s[i] != c)
            i++;
    }
    tab[j] = NULL;
    return (tab);
}
