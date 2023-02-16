/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:24:52 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/16 21:43:09 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printList(t_list *head)
{
	t_list	*node;

	node = head;
	while (node != NULL)
	{
		ft_putnbr_fd(node->value, 1);
		ft_putendl_fd("", 1);
		node = node->next;
	}
}
