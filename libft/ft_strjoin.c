/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:28:05 by pauvicto          #+#    #+#             */
/*   Updated: 2022/07/22 22:53:10 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	bothsizes;
	char	*newstring;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	bothsizes = ft_strlen(s1) + ft_strlen(s2);
	newstring = (char *) malloc(sizeof(char) * (bothsizes + 1));
	if (newstring == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		newstring[i] = s1[i];
	while (s2[i - ft_strlen(s1)] != '\0')
	{
		newstring[i] = *(s2 + (i - ft_strlen(s1)));
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
