/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:54:37 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/13 20:49:33 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_push(t_list **destStack, t_list **srcStack)
{
	t_list	*current_node;
	t_list	*next;

	if (ft_lstsize(*srcStack) < 1)
		return (-1);
	current_node = *srcStack;
	next = current_node->next;
	if (!current_node)
		ft_error("Error during push");
	ft_lstadd_front(destStack, ft_lstnew(current_node->value));
	*srcStack = next;
	return (0);
}

int push(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		if (do_push(stack_a, stack_b) == -1)
			return (-1);
		ft_putendl_fd("pa", 1);
	}
	else if (flag == 'b')
	{
		if (do_push(stack_b, stack_a) == -1)
			return (-1);
		ft_putendl_fd("pb", 1);
	}
	return (0);
}