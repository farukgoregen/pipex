/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:58:00 by omgorege          #+#    #+#             */
/*   Updated: 2024/10/13 12:45:13 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			size;
	unsigned char	*str;

	size = ft_strlen(s1);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, size);
	str[size] = '\0';
	return ((char *)str);
}
