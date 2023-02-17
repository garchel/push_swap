/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:54:37 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/17 04:20:27 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_push(t_list **dest_stack, t_list **source_stack)
{
	t_list	*new_element;
	t_list	*dest_head;
	t_list	*source_head;

	if (ft_lstsize(*source_stack) == 0)
		return (-1);
	dest_head = *dest_stack;
	source_head = *source_stack;
	new_element = source_head;
	source_head = source_head->next;
	*source_stack = source_head;
	if (!dest_head)
	{
		dest_head = new_element;
		dest_head->next = NULL;
		*dest_stack = dest_head;
	}
	else
	{
		new_element->next = dest_head;
		*dest_stack = new_element;
	}
	return (0);
}

int	push(t_list **stack_a, t_list **stack_b, char flag)
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
