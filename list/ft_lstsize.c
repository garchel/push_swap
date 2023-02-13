/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:08:08 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/13 20:41:56 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*node;

	node = head;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
