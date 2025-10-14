#include "Voiture.hpp"

#include <iostream>

Voiture::Voiture(int vitesseMax=130, int nbPlaces=2, int occupants=0) : 
    Vehicule(vitesseMax, nbPlaces, occupants)
{

}
    
void Voiture::demarrer() {
    std::cout << "Démarrage d'une voiture" << "\n";
}

void Voiture::arreter() {
    std::cout << "Arret d'une voiture" << "\n";
}