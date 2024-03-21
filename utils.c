/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:10:49 by mtocu             #+#    #+#             */
/*   Updated: 2024/03/21 19:32:26 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strnstr(char *s1, char *s2, int n)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	if (ft_strlen(s2) > n)
		return (NULL);
	while (i + ft_strlen(s2) <= n && s1[i])
	{
		flag = 1;
		j = 0;
		while (j < ft_strlen(s2) && s2[j])
		{
			if (s1[i + j] != s2[j])
				flag = 0;
			++j;
		}
		if (flag == 1)
			return ((char *)&s1[i]);
		++i;
	}
	return (NULL);
}

//not sure if needed
char	*f_itoa(int nbr)
{
	int		n;
	int		len;
	char	*result;

	n = nbr;
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return ((char *)result);
}

void	initialize_directions(int *dir_row, int *dir_col)
{
	dir_row[0] = -1;
	dir_row[1] = 0;
	dir_row[2] = 1;
	dir_row[3] = 0;
	dir_col[0] = 0;
	dir_col[1] = 1;
	dir_col[2] = 0;
	dir_col[3] = -1;
}
