/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omgorege <omgorege@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:46:04 by omgorege          #+#    #+#             */
/*   Updated: 2024/10/15 09:53:49 by omgorege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	world_count(char const *s, char c)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			b++;
		}
	}
	return (b);
}

static int	control(size_t i, size_t a, char const *s)
{
	if (s[a + i])
		return (1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	a;
	size_t	b;

	a = 0;
	b = world_count(s, c);
	split = ft_calloc(b + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	b = 0;
	while (s[a])
	{
		i = 0;
		while (s[a + i] && s[a + i] != c)
			i++;
		if (i > 0)
		{
			split[b] = ft_substr(s, a, i);
			b++;
		}
		a += i + control(i, a, s);
	}
	return (split);
}
