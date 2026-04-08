# push_swap — Resume du projet

**Resume**
Ce projet consiste a trier une pile d'entiers avec un deuxieme stack et un ensemble limite d'operations. Le programme lit les arguments, valide les donnees, puis affiche la suite d'operations qui met la pile A en ordre croissant (du sommet vers la base).

**Exigences**
- Implementer `push_swap` qui lit des entiers depuis la ligne de commande.
- Verifier les erreurs (nombres valides, pas de doublons, pas de depassement d'int).
- Utiliser uniquement les operations autorisees (`sa`, `ra`, `rra`, `pa`, `pb`).
- Ecrire les operations sur la sortie standard, une par ligne.

**Representation des piles (array)**
- Les piles A et B sont gerees avec des tableaux dynamiques `int *tableau`.
- Un indice `top` represente le sommet de la pile (dernier element actif).
- Chaque operation agit directement sur le tableau (swap, rotation, push), sans liste chainee.

**Details de l'algorithme**
- **Normalisation (ranking)**: creation d'une copie triee du tableau, puis remplacement de chaque valeur par son rang (0..n-1). Cela reduit les valeurs et simplifie le tri binaire.
- **Petits cas**:
  - `n = 2` ou `n = 3`: sequences courtes d'operations pour corriger l'ordre.
  - `n <= 5`: on envoie les deux plus petits elements dans B (`pb`), on trie A, puis on remonte avec `pa`.
- **Cas general (radix sort binaire)**:
  - Calcul du nombre de bits maximum.
  - Pour chaque bit `i`, on parcourt A:
    - si le bit `i` du sommet vaut 1, on fait `ra`.
    - sinon, on pousse vers B avec `pb`.
  - A la fin du passage, on remonte tout B vers A avec `pa`.
- Cette strategie donne un tri stable et predictible pour des tailles plus grandes, avec un nombre d'operations controle.

**Resultat attendu**
- Une suite d'operations valide qui trie la pile A.
- Un comportement stable sur des listes longues ou des valeurs extremes.

**Apprentissages**
- Gestion de piles avec un tableau et un indice de sommet.
- Validation rigoureuse des entrees et gestion des erreurs.
- Conception d'un algorithme hybride (petits cas + radix).
- Optimisation des rotations pour reduire le nombre d'operations.
