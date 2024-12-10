/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:58:43 by omgorege          #+#    #+#             */
/*   Updated: 2024/10/19 09:33:43 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = ft_strlen(str);
	while (str[i])
	{
		a--;
		if (str[a] == (char)c)
		{
			return ((char *)&str[a]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}
