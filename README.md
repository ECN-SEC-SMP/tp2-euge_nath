# CPP TP2 Nathan Eugénie

## Build et Compilation

```bash
mkdir build
```
```bash
cmake -Bbuild .
```
```bash
cmake --build build/
```
```bash
./build/CPP_TP2_EUGE_NATH
```

## Class Diagram

Le diagramme de classes est fait avec mermaid.
> https://mermaid.js.org/syntax/classDiagram.html

```mermaid
---
title: Véhicule example
---
classDiagram
    Véhicule <|-- Voiture
    Véhicule <|-- Bateau
    Bateau <|-- VoitureAmphibie
    Voiture <|-- VoitureAmphibie
    Véhicule : #int vitesse_
    Véhicule : #int vitesseMax_
    Véhicule : #int nbPlaces_
    Véhicule : #int occupants_
    Véhicule : #int etat_
    Véhicule: +demarrer()
    Véhicule: +depanner()
    Véhicule: +accelerer(int increment)
    Véhicule: +monter(int nbOcc)
    Véhicule: +descendre(int nbOcc)
    Véhicule: +mettreEnPanne(double random)
    Véhicule: +getEtat() string
    class Voiture{
        +demarrer()
        +arreter()
    }
    class Bateau{
        +demarrer()
        +arreter()
    }
    class VoitureAmphibie{
        +demarrer()
        +arreter()
        +afficherCaracteristiques()
    }

Structure du projet

tp2-euge_nath/
├── src/
│   ├── Vehicule.cpp
│   ├── Vehicule.hpp
│   ├── Voiture.cpp
│   ├── Voiture.hpp
│   ├── Bateau.cpp
│   ├── Bateau.hpp
│   └── StateException.hpp   (classe d’exception personnalisée)
│
├── main_vehicule.cpp   (test de la classe Vehicule)
├── main_voiture.cpp    (test de la classe Voiture)
├── main_bateau.cpp     (test de la classe Bateau)
└── README.md

## StateException


Lorsqu'un véhicule est dans un état qui ne permet pas de faire certaines actions, on utilise la classe d'exception `StateException`.  
Cette classe hérite de `std::exception`.  
Quand on effectue une action avec un véhicule, s'il n'est pas dans un bon état, on peut le savoir plus précisément, au lieu de `catch` un *string*.

## 3

Comme faire en sorte que les attributs de Vehicule ne soient pas dupliqués si nécessaire ?  

> Si l'on veut que ne soit pas dupliquer, il faudrait que `Vehicule` et `Bateau` hérite de `Vehicule` en *virtual*.  

--------- Classes principales ----------
-> Vehicule

Classe de base commune à tous les véhicules.
Elle gère :
- la vitesse (vitesse_, vitesseMax_)
- le nombre d’occupants (occupants_, nbPlaces_)
- l’état du véhicule (ARRET, MARCHE, PANNE_LEGERE, PANNE_SEVERE)

Les méthodes lèvent des exceptions (StateException) dans les cas suivants :
- vitesse négative ou supérieure à la vitesse max
- démarrage d’un véhicule déjà en marche ou en panne
- ajout d’occupants au-delà de la capacité maximale
- descente d’un nombre d’occupants supérieur à celui présent

-> Voiture

Hérite de Vehicule
Spécifie ses propres comportements : demarrer() et arreter()

-> Bateau

Hérite de Vehicule
Spécifie ses propres comportements : demarrer() et arreter()

--------- Tests ---------

Le fichier main_*.cpp contient un scénario pour vérifier les méthodes principales. Pour le lancer effectuez la commande suivante :

-> Test de Vehicule

g++ src/Vehicule.cpp main_vehicule.cpp -o testVehicule -std=c++17 -Isrc
./testVehicule

Comportement attendu :
- Démarrage du véhicule
- Accélération
- Déclenchement d’une exception si la vitesse dépasse la vitesse maximale

-> Test de Voiture

g++ src/Vehicule.cpp src/Voiture.cpp main_voiture.cpp -o testVoiture -std=c++17 -Isrc
./testVoiture

Comportement attendu :
- Message “Démarrage d’une voiture”
- Accélération et arrêt
- Affichage de l’état final “Arret”

-> Test de Bateau

g++ src/Vehicule.cpp src/Bateau.cpp main_bateau.cpp -o testBateau -std=c++17 -Isrc
./testBateau

Comportement attendu :
- Message “Démarrage d’un bateau”
- Accélération puis arrêt
- Affichage de l’état final “Arret”