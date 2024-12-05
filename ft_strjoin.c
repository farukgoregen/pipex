/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:29:51 by omgorege          #+#    #+#             */
/*   Updated: 2024/10/14 10:13:24 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*s3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s3 = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, len1);
	ft_strlcat(s3, s2, len1 + len2 + 1);
	return (s3);
}
