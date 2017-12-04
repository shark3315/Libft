/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:41:38 by lapain            #+#    #+#             */
/*   Updated: 2017/12/04 22:15:17 by lapain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *search, size_t n)
{
	size_t	len;
	int		i;
	int		len_search;

	len = 0;
	i = 0;
	len_search = ft_strlen(search);
	if (search[i] == '\0')
		return ((char *)src);
	if (src[len] != '\0')
	{
		while (len < n && src[len])
		{
			while (search[i] == src[len])
			{
				if (i == len_search - 1)
					return ((char *)src + len);
				i++;
			}
			i = 0;
			len++;
		}
	}
	return (NULL);
}
