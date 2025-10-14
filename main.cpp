#include <cstdint>
#include <time.h>
#include <random>
#include <iostream>

// #include "Vehicule.hpp"

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
    std::srand(time(NULL));  // Init random seed

    return 0;
}

uint32_t util::getRandInt(uint32_t min, uint32_t max) {
    return min + ( std::rand() % ( max - min + 1 ) );
}

// --------------------------------------------------
// 1 - Creation véhicule
// --------------------------------------------------

void setVehiculePanne(Vehicule v) {
    double rNum = std::rand() / (double)RAND_MAX; // Get random number between 0 and 1
    // std::cout << "Rand = " << rNum << "\n";

    v.mettreEnPanne(rNum);

}

// --------------------------------------------------
// 2 - Voiture et Bateau
// --------------------------------------------------

// --------------------------------------------------
// 3 - Voiture Amphibie
// --------------------------------------------------

