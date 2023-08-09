#include <TrocoSolver.h>

unsigned int countCoins(std::vector<unsigned int> &coins) {
    unsigned int quantCoins = 0;
    for(int i = 0; i < coins.size(); ++i) quantCoins += coins[i];
    return quantCoins;
}

void DCSolve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins, std::vector<unsigned int> &coinsAux, long &recursivecalls) {
    recursivecalls++;
    if(value == 0 && countCoins(coinsAux) < countCoins(coins)) {
        coins = coinsAux;
        return;
    }
    for(int i = 0; i < denom.size(); ++i) {
        if(denom[i] > value) continue;
        coinsAux[i]++;
        DCSolve(denom, value-denom[i], coins, coinsAux, recursivecalls);
        coinsAux[i]--;
    }
}

void TrocoSolverDivConquer::solve(const std::vector<unsigned int> &denom, unsigned int value, std::vector<unsigned int> &coins) { 
    recursivecalls = 0;
    coins.resize(denom.size(), 999); 
    std::vector<unsigned int> coinsAux;
    coinsAux.resize(denom.size(), 0);
    DCSolve(denom, value, coins, coinsAux, recursivecalls);
}//solve