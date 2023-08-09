#include <SubsetSumSolver.h>



 bool SSPSolverPD::solve(const std::vector< long> &input,
                            long value, std::vector< char> &output) {
    
    std::vector<std::vector<long>> B (input.size()+1, std::vector<long>(value+1, 0));
    
    for(long k = 1; k <= input.size(); ++k) {
        for(long i = 0; i <= value; ++i) {
            if(input[k-1] > i) B[k][i] = B[k-1][i];
            else B[k][i] = std::max(B[k-1][i], B[k-1][i-input[k-1]] + input[k-1]);
        }
    }

    output.resize(input.size(), false);
    if(B[input.size()][value] == value) {
        long weight = value;
        for(int k = input.size()-1; k >= 0; --k) {
            if(B[k][weight] < B[k+1][weight]) {
                output[k] = true;
                weight -= input[k];
            }
        }
        return true;
    }
    return false;
}
