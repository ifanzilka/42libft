/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 20:52:53 by bmarilli          #+#    #+#             */
/*   Updated: 2020/11/02 18:56:31 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ENG
*/

/*
** RUS
**
** Функция strnstr() находит первое вхождение строки с нулевым окончанием
** в стоге сена строки, где ищется не более символов len
** Символы, которые появляются после символа "\0", не ищутся.
** Поскольку функция strnstr() является специфичным для FreeBSD API,
** ее следует использовать только
** когда переносимость не является проблемой.
**
** RETURN
**
** Введется поиск подстроки.Возвращает указатель на первое вхождение.
** Если не нашел возвращает 0.
*/

/*
**  SLOW VERSION
**
**	int		ft_find(const char *to_find, const char *find, size_t j, size_t len)
**	{
**		int		i;
**
**		i = 0;
**		while (to_find[i] && find[i])
**		{
**			if (j >= len)
**				return (0);
**			if (to_find[i] != find[i])
**				return (0);
**			i++;
**			j++;
**		}
**		return (1);
**	}
**
**	char	*ft_strnstr(const char *str, const char *dst, size_t len)
**	{
**		size_t	i;
**
**		if (*dst == '\0')
**			return ((char *)str);
**		i = 0;
**		if (ft_strlen(dst) > ft_strlen(str))
**			return (0);
**		while (i < len && (str + i))
**		{
**			if (ft_find((str + i), dst, i, len) == 1)
**				return ((char *)(str + i));
**			i++;
**		}
**		return (0);
**	}
*/

/*
** OLD
**
**	char	*ft_strnstr(const char *str, const char *sbstr, size_t len)
**	{
**		size_t	i;
**
**		i = 0;
**		if (!sbstr || !str)
**			return (NULL);
**		if (*sbstr == '\0')
**			return ((char*)str);
**		while (*str && len)
**		{
**			if (*str == *sbstr)
**				break ;
**			str++;
**			len--;
**		}
**		if (ft_strlen(sbstr) > len)
**			return (0);
**		while (*str && i <= ft_strlen(str) - ft_strlen(sbstr))
**		{
**			if (ft_strncmp(str, sbstr, ft_strlen(sbstr)) == 0)
**				return ((char *)str);
**			str++;
**			i++;
**		}
**		return (0);
**}
*/

static int	ft_strncmp_sp(const char *s1, const char *s2, size_t n)
{
	if (n < ft_strlen(s2))
		return (1);
	while ((*s1 && *s2) && n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

char		*ft_strnstr(const char *str, const char *sbstr, size_t len)
{
	if (!*sbstr)
		return ((char *)str);
	if (ft_strlen(str) < ft_strlen(sbstr))
		return (NULL);
	while (*str && len)
	{
		if (ft_strncmp_sp(str, sbstr, len) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (NULL);
}
