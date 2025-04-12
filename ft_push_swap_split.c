/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbechtle <zbechtle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 12:34:13 by zbechtle          #+#    #+#             */
/*   Updated: 2025/04/12 22:03:55 by zbechtle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//static int	count_words(char *s, char c)
//{
//	int		count;
//	int		inside_word;
//
//	count = 0;
//	while (*s)
//	{
//		inside_word = 0;
//		while (*s == c)
//			++s;
//		while (*s != c && *s)
//		{
//			if (!inside_word)
//			{
//				++count;
//				inside_word = 1;
//			}
//			++s;
//		}
//	}
//	return (count);
//}

char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + len] != c) && s[cursor + len])
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

//char	**ft_split(char *s, char c)
//{
//	char	**res;
//	int		i;
//	int		j;
//	int		k;
//
//	if (!s || !(res = malloc(sizeof(char *) * (count_words(s, c) + 1))))
//		return (NULL);
//	i = 0;
//	k = 0;
//	while (s[i])
//	{
//		while (s[i] == c)
//			i++;
//		j = i;
//		while (s[i] && s[i] != c)
//			i++;
//		if (i > j)
//		{
//			res[k] = malloc(sizeof(char) * (i - j + 1));
//			if (!res[k])
//				return (NULL);
//			ft_strlcpy(res[k++], &s[j], i - j + 1);
//		}
//	}
//	res[k] = NULL;
//	return (res);
//}

void	free_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}
