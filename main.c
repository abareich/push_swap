/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  ++:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:09:36 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:09:47 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (ac < 2)
		return (0);
	pile_a = malloc(sizeof(t_pile));
	if (!pile_a)
		return (0);
	pile_b = malloc(sizeof(t_pile));
	if (!pile_b)
		return (free(pile_a), 0);
	pile_a->tableau = malloc(sizeof(int) * (ac - 1));
	if (!pile_a->tableau)
		return (free(pile_a->tableau), free(pile_a), free(pile_b), 0);
	pile_b->tableau = malloc(sizeof(int) * (ac - 1));
	if (!pile_b->tableau)
		return (free(pile_a->tableau), free(pile_b->tableau), free(pile_a),
			free(pile_b), 0);
	if (!init_tableau(ac, av, pile_a, pile_b))
	{
		free_pile(pile_a, pile_b);
		error_exit();
	}
	sort(pile_a, pile_b);
	free_pile(pile_a, pile_b);
}
