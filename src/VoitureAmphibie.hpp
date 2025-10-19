#pragma once
#include <stdexcept>
#include <iostream>

#include "Voiture.hpp"
#include "Bateau.hpp"

using namespace std;

class VoitureAmphibie : public Voiture, public Bateau
{
protected:
    
public:

    VoitureAmphibie(int vitesseMaxVoiture = 130, int vitesseMaxBateau = 150, int nbPlaces = 4, int occupants = 0);
    
    void demarrer();
    
    void arreter();
    
    // Méthode supp pour afficher les deux vitesses max
    void afficherCaracteristiques();
};