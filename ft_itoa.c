/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lapain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:51:15 by lapain            #+#    #+#             */
/*   Updated: 2017/12/04 19:07:34 by lapain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len_nb(int n)
{
	int len;

	len = 0;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char	*stri;
	int		len;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	len = ft_len_nb(n) + 1;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	len += negative;
	if ((stri = (char *)malloc(sizeof(*stri) * (len + 1))) == NULL)
		return (NULL);
	stri[len] = '\0';
	while (len--)
	{
		stri[len] = n % 10 + 48;
		n /= 10;
	}
	if (negative == 1)
		stri[0] = '-';
	return (stri);
}
