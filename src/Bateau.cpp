#include "Bateau.hpp"

#include <iostream>

Bateau::Bateau(int vitesseMax, int nbPlaces, int occupants) : 
    Vehicule(vitesseMax, nbPlaces, occupants)
{

}
    
void Bateau::demarrer() {
    std::cout << "Démarrage d'un bateau" << "\n";
}

void Bateau::arreter() {
    std::cout << "Arret d'un bateau" << "\n";
}