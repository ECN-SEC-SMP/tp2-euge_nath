#include <cstdint>
#include <time.h>
#include <random>
#include <iostream>

#include "Vehicule.hpp"
#include "Voiture.hpp"
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
        // Création d'une voiture (vitesse max 180 km/h, 5 places, 1 occupant)
        Voiture v(180, 5, 1);

        v.demarrer();
        v.accelerer(50);
        std::cout << "Vitesse actuelle : " << 50 << " km/h" << std::endl;

        v.arreter();
        std::cout << "État : " << v.getEtat() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    std::cout << "=== Fin du test Voiture ===" << std::endl;

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
