/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:25:15 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/10 21:09:54 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			if (s1[i] > s2[i])
				return (1);
			else if (s1[i] < s2[i])
				return (-1);
		}
	}
	return (0);
}
/*
int	main(void)
{
	char *s1 = "ab";
	char *s2 = "aa";
	printf("%d\n", ft_strncmp(s1, s2, 3));
	
	//printf("%d\n", strncmp(s1, s2, 3));
}*/
