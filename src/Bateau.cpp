#include "Bateau.hpp"

#include <iostream>

Bateau::Bateau(int vitesseMax=150, int nbPlaces=4, int occupants=0) : 
    Vehicule(vitesseMax, nbPlaces, occupants)
{

}
    
void Bateau::demarrer() {
    std::cout << "Démarrage d'un bateau" << "\n";
}

void Bateau::arreter() {
    std::cout << "Arret d'un bateau" << "\n";
}