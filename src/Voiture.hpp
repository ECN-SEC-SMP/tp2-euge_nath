#ifndef Voiture_hpp
#define Voiture_hpp

#include <stdexcept>
#include <iostream>

#include "Vehicule.h"

using namespace std;

class Voiture : public Vehicule
{
protected:
    
public:

    Voiture(int vitesseMax=130, int nbPlaces=2, int occupants=0);
    
    void demarrer();
    
    void arreter();
    
    friend ostream& operator<<(ostream& s,Voiture const& v);

};

// opérateur d'affichage
ostream& operator<<(ostream& s,Voiture const& v);

#endif /* Voiture_hpp */