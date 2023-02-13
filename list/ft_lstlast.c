/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:35:00 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/13 20:41:50 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *head) 
{
	t_list	*current_node;

	current_node = head;
	while (current_node->next)
	{
		current_node = current_node->next;
		if (current_node->next == NULL)
			return (current_node);
	}
	return (current_node);
}