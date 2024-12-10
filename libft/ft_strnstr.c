/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:44:36 by omgorege          #+#    #+#             */
/*   Updated: 2024/10/16 16:12:02 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	size_t			a;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	i = 0;
	a = 0;
	if (ptr2[a] == '\0')
		return ((char *)&ptr1[i]);
	while (ptr1[i + a] && i < n)
	{
		while (ptr1[i + a] && (ptr1[i + a] == ptr2[a]) && (i + a < n))
		{
			a++;
			if (ptr2[a] == '\0')
				return ((char *)&ptr1[i]);
		}
		a = 0;
		i++;
	}
	return (0);
}
