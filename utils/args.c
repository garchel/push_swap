/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:30:26 by pauvicto          #+#    #+#             */
/*   Updated: 2023/02/09 16:30:26 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_argv(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	verify_input_args(int argc, char **argv)
{
	int		i;
	long	current_value;
	char	**args;

	i = 0; 
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		current_value = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error("Error");
		if (is_in_argv(current_value, args, i))
			ft_error("Error");
		if (current_value < INT_MIN || current_value > INT_MAX)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
