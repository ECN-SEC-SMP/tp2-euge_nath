#include "Vehicule.h"
#include <iostream>
#include <string>

//Constructeur
Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
    : vitesse_(0),
      vitesseMax_(vitesseMax),
      nbPlaces_(nbPlaces),
      occupants_(occupants),
      etat_(ARRET){}

//Méthode
void Vehicule::demarrer(){

}

void Vehicule::arreter(){

}

void Vehicule::depanner(){

}

void Vehicule::accelerer(int increment){

}

void Vehicule::monter(int nbOcc){

}
void Vehicule::descendre(int nbOcc){

}
void Vehicule::mettreEnPanne(double random){

}

string Vehicule::getEtat() const{

}

// Destructeur
Vehicule::~Vehicule()
{
    cout << "Destruction du véhicule." << endl;
}