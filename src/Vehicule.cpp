#include "Vehicule.hpp"
#include "StateException.hpp"
#include <iostream>
#include <string>

/* Écrivez le fichier Vehicule.cpp en levant des exceptions invalid_argument https://en.cppreference.
com/w/cpp/error/invalid_argument dans les cas suivants :
— si la vitesse devient négative
— si la vitesse dépasse la vitesse maximum
— si on cherche à démarrer un véhicule déjà en marche ou en panne
— si on cherche à ajouter un occupant mais que le véhicule est déjà plein
— si on cherche à faire descendre plus d’occupants qu’il y en avait dans le véhicule
*/


//Constructeur
Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
    : vitesse_(0),
      vitesseMax_(vitesseMax),
      nbPlaces_(nbPlaces),
      occupants_(occupants),
      etat_(ARRET){

      }

// Exceptions

//Méthode
void Vehicule::demarrer(){
    if(etat_==MARCHE){
        throw StateException{ErrorCause::Invalide, "State = MARCHE"};
    }
    if(etat_==PANNE_SEVERE){
        throw StateException{ErrorCause::Invalide, "State = PANNE_LEGERE"};
    }
    if(etat_==PANNE_SEVERE){
        throw StateException{ErrorCause::Invalide, "State = PANNE_SEVERE"};
    }
}

void Vehicule::arreter(){
    if(etat_ != MARCHE) {
        throw StateException{ErrorCause::Invalide, "Vehicule n'est pas en marche"};
    }
    etat_ = ARRET;
    vitesse_ = 0;
    return;
}

void Vehicule::depanner(){
    if(etat_ != PANNE_LEGERE && etat_ != PANNE_SEVERE){
        throw StateException{ErrorCause::Invalide, "Vehicule n'est pas en panne"};
    }
    etat_ = ARRET;
    vitesse_=0;
    return;
}

void Vehicule::accelerer(int increment){
    vitesse_ += increment;
    if(vitesse_<0){
        throw StateException{ErrorCause::Invalide, "Vitesse < 0"};
    }
    if(vitesse_>vitesseMax_){
        throw StateException{ErrorCause::Invalide, "Vitesse > Vitesse Max"};
    }
}

void Vehicule::monter(int nbOcc){
    if(occupants_ + nbOcc > nbPlaces_){
        throw StateException{ErrorCause::Invalide, "Véhicule plein"};
    }
    occupants_ += nbOcc;
}
void Vehicule::descendre(int nbOcc){
    if(nbOcc>occupants_){
        throw StateException{ErrorCause::Invalide, "Vehicule deja vide"};
    }
    occupants_ -= nbOcc;

}
void Vehicule::mettreEnPanne(double random){
    if(etat_ == PANNE_LEGERE){
        etat_ = ARRET;
    }
    if(etat_ == PANNE_SEVERE){
        etat_ = ARRET;
    }
}

string Vehicule::getEtat() const{
    if(etat_ == ARRET){
        return std::string("Arret");
    }
    if(etat_ == MARCHE){
        return std::string("Marche");    }
    if(etat_ == PANNE_LEGERE){
        return std::string("Panne Legere");
    }
    if(etat_ == PANNE_SEVERE){
        return std::string("Panne Severe");
    }
    
    return "Etat inconnu";
}

// Destructeur
Vehicule::~Vehicule()
{
    cout << "Destruction du véhicule." << endl;
}