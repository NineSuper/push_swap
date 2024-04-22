<h1 align="center">Projet Push_Swap</h1>

Bienvenue dans le dépôt du projet Push_Swap !

Ce projet vise à trier des données en utilisant deux piles et un ensemble limité d'instructions.

## Aperçu du Projet

- **Objectif :** Trier une pile d'entiers avec un ensemble limité d'instructions.
- **Piles :** Deux piles sont utilisées, pile A (contenant initialement un ensemble aléatoire d'entiers) et pile B (initialement vide).

- **Instructions :** Les instructions suivantes sont autorisées :
  - `sa` : Échanger les deux premiers éléments en haut de la pile A.
  - `sb` : Échanger les deux premiers éléments en haut de la pile B.
  - `ss` : `sa` et `sb` combinés.
  - `pa` : Pousser le premier élément en haut de la pile A vers le haut de la pile B.
  - `pb` : Pousser le premier élément en haut de la pile B vers le haut de la pile A.
  - `ra` : Faire tourner la pile A vers le haut.
  - `rb` : Faire tourner la pile B vers le haut.
  - `rr` : `ra` et `rb` combinés.
  - `rra` : Faire tourner la pile A vers le bas.
  - `rrb` : Faire tourner la pile B vers le bas.
  - `rrr` : `rra` et `rrb` combinés.

- **Objectif :** Trier la pile A par ordre croissant.

## Utilisation

1. Clonez le dépôt :

```bash
git clone https://github.com/NineSuper/push_swap.git
```

2. Compilez le programme :
```bash
make
```

3. Exécutez le programme :
```bash
./push_swap [liste_d_entiers]
```
Remplacez [liste_d_entiers] par la liste d'entiers que vous souhaitez trier, séparés par des espaces.

Exemple:
```bash
./push_swap 5 3 8 1 4
```
Cela affichera la série d'instructions pour trier la liste d'entiers donnée.

## Auteur
👨‍💻 [NineSuper](https://github.com/NineSuper)
