#include <SubsetSumSolver.h>


/// Aluno2: segunda solucao do aluno = Meet-in-the-Middle OU Branch & Bound
 bool SSPSolverAluno2::solve(const std::vector< long> &input,
                            long value, std::vector< char> &output) {

    // Solução Meet-in-the-Middle
    std::vector<long> left(input.begin(), input.begin()+input.size()/2);
    std::vector<long> right(input.begin()+input.size()/2, input.end());
    std::vector<long> leftSum, rightSum;
    leftSum.resize((1 << left.size()), 0);
    rightSum.resize((1 << right.size()), 0);
    
    for(unsigned int i = 0; i < (1 << left.size()); ++i) {
        for(unsigned int j = 0; j < left.size(); ++j)
            if(i & (1 << j)) leftSum[i] += left[j];
    }
    for(unsigned int i = 0; i < (1 << right.size()); ++i) {
        for(unsigned int j = 0; j < right.size(); ++j)
            if(i & (1 << j)) rightSum[i] += right[j];
    }

    output.resize(input.size(), false);
    for(unsigned int i = 0; i < leftSum.size(); ++i) {
        for(unsigned int j = 0; j < rightSum.size(); ++j) {
            if(leftSum[i] + rightSum[j] == value) {
                for(unsigned int k = 0; k < left.size(); ++k)
                    if(i & (1 << k)) output[k] = true;
                for(unsigned int k = 0; k < right.size(); ++k)
                    if(j & (1 << k)) output[k+left.size()] = true;
                return true;
            }
        }
    }
    return false;
}
