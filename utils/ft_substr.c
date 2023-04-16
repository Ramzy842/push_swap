/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:35:18 by rchahban          #+#    #+#             */
/*   Updated: 2023/04/07 07:17:05 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*substr;

	x = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while ((size_t)start < ft_strlen(s) && x < len)
	{
		*(substr + x) = (char)s[start + x];
		x++;
	}
	*(substr + x) = '\0';
	return (substr);
}
