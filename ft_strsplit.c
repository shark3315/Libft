/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:24:07 by lapain            #+#    #+#             */
/*   Updated: 2017/12/04 14:35:25 by lapain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words(const char *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		ft_len_words(const char *s, char c)
{
	int len;
	int index;

	len = 0;
	index = 0;
	while (s[index] != c && s[index] != '\0')
	{
		len++;
		index++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		nb_words;
	char	**strsplit;

	if (s == NULL)
		return (NULL);
	nb_words = ft_nb_words(s, c);
	strsplit = (char **)malloc(sizeof(*strsplit) * (nb_words + 1));
	if (strsplit == NULL)
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		while (*s == c)
			s++;
		strsplit[i] = ft_strsub(s, 0, ft_len_words(s, c));
		s = s + ft_len_words(s, c);
		i++;
	}
	strsplit[i] = NULL;
	return (strsplit);
	free(strsplit);
}
