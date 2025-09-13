# Convertisseur d'unités en C

## 📌 Description

Ce projet est un programme en langage **C** qui permet de convertir
différentes unités utilisées dans la vie courante.\
L'application est en mode console et propose un menu interactif pour
choisir la catégorie d'unité, saisir une valeur, et obtenir la
conversion.

## 🔧 Fonctionnalités

Le convertisseur prend en charge plusieurs types d'unités :

1.  **Longueur**
    -   m, cm, km, inch, ft, yd, mile
2.  **Masse / Poids**
    -   g, kg, t, lb, oz
3.  **Température**
    -   Celsius (C), Fahrenheit (F), Kelvin (K)
4.  **Vitesse**
    -   m/s, km/h, mph, knot
5.  **Volume / Capacité**
    -   L, mL, gal, cup, fl-oz

Chaque catégorie utilise un tableau de facteurs de conversion ou des
formules spécifiques (pour la température).

## 🖥️ Utilisation

1.  Compiler le programme :

    ``` bash
    gcc convertisseur.c -o convertisseur
    ```

2.  Exécuter le programme :

    ``` bash
    ./convertisseur
    ```

3.  Sélectionner la catégorie à convertir (ex: `1` pour la longueur).

4.  Entrer la valeur et les unités source et cible.

5.  Le résultat de la conversion sera affiché.

## 📂 Structure du code

-   **Fonctions principales de conversion** :
    -   `convert_length()`\
    -   `convert_weight()`\
    -   `convert_temperature()`\
    -   `convert_speed()`\
    -   `convert_volume()`
-   **Fonctions utilitaires** :
    -   `Lire_int(int *result)` → lecture sécurisée d'un entier
    -   `Lire_double(double *result)` → lecture sécurisée d'un flottant
    -   `Lire_str(char *str, size_t N)` → lecture sécurisée d'une chaîne
    -   `strcmp_ignoring_case(const char *str1, const char *str2)` →
        comparaison de chaînes sans tenir compte de la casse

## ✅ Exemple d'exécution

    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒Convertisseur d'unités▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
    █1. Longueur (m, cm, km, inch, ft, yd, mile)        █
    █2. Masse/Poids (g, kg, t, lb, oz)                  █
    █3. Température (C, F, K)                           █
    █4. Vitesse (m/s, km/h, mph, knot)                  █
    █5. Volume/Capacité (L, mL, gal, cup, fl oz)        █
    █0. Quitter                                         █
    ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

    Votre choix : 1
    Entrer valeur: 10
    De: km
    Vers: mile
    10.0000 km = 6.2137 mile

## 📊 Autres exemples d'utilisation

-   **Conversion de poids**

        Votre choix : 2
        Entrer valeur: 500
        De: g
        Vers: lb
        500.0000 g = 1.1023 lb

-   **Conversion de température**

        Votre choix : 3
        Entrer valeur: 100
        De: C
        Vers: F
        100.00 C = 212.00 F

-   **Conversion de vitesse**

        Votre choix : 4
        Entrer valeur: 120
        De: km/h
        Vers: mph
        120.0000 km/h = 74.5645 mph

-   **Conversion de volume**

        Votre choix : 5
        Entrer valeur: 2
        De: L
        Vers: cup
        2.0000 L = 8.4535 cup

---

## 👨‍💻 Auteur
Réalisé par salah eddine barri en C.
comme exercice pratique d’implémentation de jeu en console.  
