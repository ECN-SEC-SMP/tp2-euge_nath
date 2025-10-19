#include "VoitureAmphibie.hpp"

#include <iostream>

VoitureAmphibie::VoitureAmphibie(int vitesseMaxVoiture, int vitesseMaxBateau, int nbPlaces, int occupants) 
    : 
      Voiture(vitesseMaxVoiture, nbPlaces, occupants),
      Bateau(vitesseMaxBateau, nbPlaces, occupants)
{

}
    
void VoitureAmphibie::demarrer() {
    std::cout << "Démarrage d'une voiture amphibie" << "\n";
}

void VoitureAmphibie::arreter() {
    std::cout << "Arret d'une voiture amphibie" << "\n";
}

void VoitureAmphibie::afficherCaracteristiques() {
    Voiture:: vitesse_;
    Bateau:: vitesse_;
}