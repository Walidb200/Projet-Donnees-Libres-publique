---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

# Rapport de projet *Données libres*

:::{admonition} Consignes

Les consignes comme celui-ci vous donnent des indications sur le
contenu attendu; ils sont à supprimer une fois votre rapport rédigé.

Ce rapport pourra servir de support pour votre présentation orale.

Soyez objectifs et factuels! Vous ne serez pas évalué sur ce que vous
affirmez, mais sur la pertinence et la justesse de ce que vous
affirmez.

:::

+++

## Auteurs

- Nom, prénom, courriel, groupe
- Nom, prénom, courriel, groupe

+++

## Résumé du travail effectué

:::{admonition} Consignes

Pour chaque exercice, décrivez brièvement l'avancement de votre projet.

Exemples de réponses : «non traitée», «réalisée, documentée, testée»,
«réalisée, sauf 2.3», «réalisée mais non testée», «réalisée sauf ...
pour lequel notre programme ne compile pas» ou «pour lequel les tests
de la fonction D ne passent pas».

Décrivez plus en détail les questions difficiles. Précisez et décrivez
les applications que vous avez réalisées, les difficultés rencontrées,
les choix d'implantation que vous avez fait, etc.

En plus du rapport, la documentation de chaque fonction dans le code
devra préciser son auteur et votre degré de confiance dans
l'implantation, ainsi que les éléments factuels motivant cette
confiance: présence de tests, bogues et limitations connus, etc.

:::

- Partie 1 :
  - Exercice 1 : ...
  - Exercice 2 : ...
  - ...
- Partie 2 : 
  - Question 1 : réalisée, testée
  - Question 2 : réalisée, testée
  - Question 3 : réalisée, testée
  - Question 4 : réalisée, testée
  - Question 5 : réalisée, testée
  - Question 6 : non traitée
- Partie 3 :
  - Exercice 7 :
    - Question 1 : consultée, testée
    - Question 2 : réalisée, testée
  - Exercice 8 :
    - Question 1 : réalisée, testée
    - Question 2 : réalisée, testée

+++

## Démonstration

:::{admonition} Consignes

Soutenez ce que vous affirmez dans la section précédente au moyen de
quelques exemples **bien choisis**. Vous pouvez par exemple compiler
et lancer certains de vos programmes, lancer des tests, etc.

À titre d'inspiration, vous trouverez ci-dessous un début de
démonstration pour les premiers exercices.

Notez comment on lance une commande shell en la préfixant d'un point
d'exclamation (mais cela ne permet pas l'interaction avec
l'utilisateur).

Ne gardez que des exemples pertinents qui mettent en valeur votre
travail. Inutile de perdre du temps sur le premier programme si vous
avez fait les suivants plus compliqués; l'auditeur se doutera bien que
vous avez réussi à le faire.

:::

+++

### Partie 1

#### Exercice 1

```{code-cell} ipython3
! clang++ mariage-total.cpp -o mariage-total
```

```{code-cell} ipython3
! ./mariage-total
```

```{code-cell} ipython3
! clang++ mariage-samedi.cpp -o mariage-samedi
```

```{code-cell} ipython3
! ./mariage-samedi
```

#### Exercice 2

```{code-cell} ipython3
! clang++ prenoms.cpp -o prenoms
```

Exécutez le programme `./prenoms` dans un terminal pour tester (demande une année)

+++

### Partie 2

#### Exercice 6

```{code-cell} ipython3
! clang++ mariage-complet-3.cpp -o mariage-complet-3
```

```{code-cell} ipython3
! ./mariage-complet-3
```

```{code-cell} ipython3
! clang++ prenoms-tableau-avance.cpp -o prenoms-tableau-avance
```

```{code-cell} ipython3
! ./prenoms-tableau.avance
```

### Partie 3

#### Exercice 7

```{code-cell} ipython3
! clang++ prenoms-csv.cpp -o prenoms-csv
```

```{code-cell} ipython3
! ./prenoms-csv
```

```{code-cell} ipython3
! clang++ tableau-lecture-csv.cpp -o tableau-lecture-csv
```

```{code-cell} ipython3
! ./tableau-lecture-csv
```

### Tout exécuté et testé

```{code-cell} ipython3
! make clean
```

```{code-cell} ipython3
! make all
```

```{code-cell} ipython3
! make test
```

## Organisation du travail

:::{admonition} Consignes
Décrivez en quelques phrases comment vous vous êtes organisés pour
travailler sur le projet: nombre d'heures consacrées au projet,
répartition du travail dans le binôme, moyens mis en œuvre pour
collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle de
vos enseigants), précisez le.
:::

+++

## Prise de recul

:::{admonition} Consignes
Décrivez en quelques phrases les difficultés rencontrées, ce que vous
avez appris à l'occasion du projet, le cas échéant comment vous vous y
prendriez si vous aviez à le refaire.
:::
