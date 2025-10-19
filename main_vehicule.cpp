#include <cstdint>
#include <time.h>
#include <random>
#include <iostream>

#include "Vehicule.hpp"

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

    try
    {
        cout << "[TEST 1] Création + dépassement de vitesse max\n";
        Vehicule v(150, 4, 1);
        v.demarrer();
        v.accelerer(50);
        v.accelerer(200); // dépasse la vitesse max → exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }
    
    try
    {
        cout << "[TEST 2] Double démarrage\n";
        Vehicule v(120, 4, 1);
        v.demarrer();
        v.demarrer(); // déjà démarré → exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    try
    {
        cout << "[TEST 3] Descendre trop d’occupants\n";
        Vehicule v(120, 4, 1);
        v.descendre(2); // Il n'y a qu'un seul occupant → exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    try
    {
        cout << "[TEST 4] Monter trop d'occupants\n";
        Vehicule v(120, 2, 2);
        v.monter(1); // Plus de place → exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

    try
    {
        cout << "[TEST 5] Mise en panne aléatoire\n";
        Vehicule v(120, 4, 1);
        setVehiculePanne(v);
        cout << "État actuel : " << v.getEtat() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "[Exception] " << e.what() << std::endl;
    }

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
