#include "hashfunctions.h"


/**
 * \brief hashing by division
 * \param str the string to be hashed
 * \param m size of hash table. Auxiliary functions are used to fix the value. This implementation works for any size.
 * \return the hash value of the input string
 */
int hashdiv(std::string str, int m ) {
    int hash_value = 0;
    for (char c : str) {
        hash_value += (int)c;
    }
    return (hash_value % m);   
     
}//hashdiv

// convenience function to fix the size to 29
int hashdiv29(std::string str) {
    return hashdiv(str,29);
}


