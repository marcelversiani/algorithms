
#include <IndexPointsAluno.h>

/// returns the number of elements in the index
long IndexPointsAluno::size () { return _tree.size(); }

/// adds new element to the index. 
void IndexPointsAluno::add (double key, long idx ) { 
  _tree.insert(key, idx); }


void IndexPointsAluno::find (std::vector<long> &res, double first, double last ) {
  _tree.find_interval(res, first, last); 
}//find
