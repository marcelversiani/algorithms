#include <TrocoSolver.h>

void TrocoSolverPD::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) {  
    std::vector<unsigned int> quant, ultima;
    coins.resize(denom.size(), 0); 
    quant.resize(value+1, 0); 
    ultima.resize(value+1, 0);
    for (unsigned int cents = 1; cents <= value; ++cents) {
        unsigned int quantProv = cents;
        unsigned int ultimaProv = 0;
        for (int j = 0; j < denom.size(); ++j) {
            if (denom[j] > cents) continue;
            if (quant[cents - denom[j]] + 1 < quantProv) {
                quantProv = quant[cents - denom[j]] + 1;
                ultimaProv = j;
            }
        }
        quant[cents] = quantProv;
        ultima[cents] = ultimaProv;
    }
    unsigned int moeda = value;
    while(moeda > 0) {
        coins[ultima[moeda]]++;
        moeda -= denom[ultima[moeda]];
    } 
}//solve
