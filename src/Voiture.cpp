#include "Voiture.hpp"

#include <iostream>

Voiture::Voiture(int vitesseMax, int nbPlaces, int occupants) : 
    Vehicule(vitesseMax, nbPlaces, occupants)
{

}
    
void Voiture::demarrer() {
    std::cout << "Démarrage d'une voiture" << "\n";
}

void Voiture::arreter() {
    std::cout << "Arret d'une voiture" << "\n";
}