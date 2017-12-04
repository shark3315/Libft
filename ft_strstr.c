/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:51:26 by lapain            #+#    #+#             */
/*   Updated: 2017/12/04 14:23:44 by lapain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *search)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(search);
	if (search[i] == '\0')
		return ((char *)src);
	while (src[i] != '\0')
	{
		while (search[j] == src[i + j])
		{
			if (j == len - 1)
				return ((char *)src + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
