#include <cstdint>
#include <time.h>
#include <random>
#include <iostream>

#include "Vehicule.hpp"
#include "Bateau.hpp"
using namespace std;


namespace util
{
    uint32_t getRandInt(uint32_t min, uint32_t max);
} // namespace util

void setVehiculePanne(Vehicule v);

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */

int main(int argc, char const *argv[])
{
    std::srand(time(NULL)); // Init random seed

    try {
        // Création d’un bateau (vitesse max 80 km/h, 8 places, 2 occupants)
        Bateau b(80, 8, 2);

        b.demarrer();
        b.accelerer(30);
        std::cout << "Bateau en mouvement à 30 km/h" << std::endl;

        b.arreter();
        std::cout << "État : " << b.getEtat() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    std::cout << "=== Fin du test Bateau ===" << std::endl;


    return 0;
}

uint32_t util::getRandInt(uint32_t min, uint32_t max)
{
    return min + (std::rand() % (max - min + 1));
}

// --------------------------------------------------
// 1 - Creation véhicule
// --------------------------------------------------

void setVehiculePanne(Vehicule v)
{
    double rNum = std::rand() / (double)RAND_MAX; // random number entre 0 et 1

    v.mettreEnPanne(rNum);
}