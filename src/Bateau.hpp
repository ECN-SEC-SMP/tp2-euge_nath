#pragma once
#include <stdexcept>
#include <iostream>

#include "Vehicule.hpp"

using namespace std;

class Bateau : public Vehicule
{
protected:
    
public:

    Bateau(int vitesseMax=150, int nbPlaces=4, int occupants=0);
    
    void demarrer();
    
    void arreter();
    
    friend ostream& operator<<(ostream& s,Bateau const& v);

};

// opérateur d'affichage
ostream& operator<<(ostream& s,Bateau const& v);