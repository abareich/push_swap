/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybareic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:10:17 by aybareic          #+#    #+#             */
/*   Updated: 2025/04/01 11:10:25 by aybareic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int	*tableau;
	int	top;
}		t_pile;

int		init_tableau(int ac, char **av, t_pile *pile_a, t_pile *pile_b);
int		is_number(char *str);
int		is_duplicates(t_pile *pile);
int		is_sorted(t_pile *pile);
int		ft_atoi_secure(char *str, int *error);
int		error_exit(void);
int		trouver_max(t_pile *pile);
int		trouver_min(t_pile *pile);
int		trouver_position(t_pile *pile, int valeur);
int		obt_max_bits(t_pile *pile);
int		obt_position_bit(int nbr, int position);
void	sa(t_pile *pile_a);
void	ra(t_pile *pile_a);
void	rra(t_pile *pile_a);
void	pa(t_pile *pile_a, t_pile *pile_b);
void	pb(t_pile *pile_a, t_pile *pile_b);
void	pivoter_vers_valeur(t_pile *pile, int valeur);
void	remplire_tableau(t_pile *pile, int *tableau);
void	creer_tableau_trie(t_pile *pile_a, int *trie);
void	rank_pile(t_pile *pile);
void	free_pile(t_pile *pile_a, t_pile *pile_b);
void	sort_2(t_pile *pile);
void	sort_3(t_pile *pile);
void	sort_5(t_pile *pile_a, t_pile *pile_b);
void	sort(t_pile *pile_a, t_pile *pile_b);

#endif