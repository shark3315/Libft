/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:25:10 by lapain            #+#    #+#             */
/*   Updated: 2017/12/04 19:21:03 by lapain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*strtrim;
	int		len;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (ft_isblank(s[len - 1]) == 1 || s[len - 1] == '\n')
		len--;
	i = -1;
	while (ft_isblank(s[++i]) == 1 || s[i] == '\n')
		len--;
	if (len <= 0)
		len = 0;
	strtrim = (char *)malloc(sizeof(*strtrim) * (len + 1));
	if (strtrim == NULL)
		return (NULL);
	j = -1;
	while (++j < len)
		strtrim[j] = s[i++];
	strtrim[j] = '\0';
	return (strtrim);
}
