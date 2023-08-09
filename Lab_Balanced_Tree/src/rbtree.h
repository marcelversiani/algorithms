#ifndef RBTREE_H
#define RBTREE_H
#include <vector>

// Red-Black Tree class implementation.
class RB_Tree {
    
public:

    // Tree node.
    enum Color {RED, BLACK};
    struct node {
        Color color;
        long idx;
        double key;
        node *p, *left, *right;
    };

    // Tree constructor and destructor.
    RB_Tree ();
    ~RB_Tree ();

    // Tree methods.
    long size ();
    void insert ( double key, long idx );
    void find_interval( std::vector<long> &res, double first, double last );
    
private: 

    // We only need the pointers to the root and NIL.
    long size_;
    node *root_;
    node *NIL; 

    // Private auxiliary functions.
    void clear_tree (struct node *n);
    void left_rotate (struct node *n);
    void right_rotate (struct node *n);
    void tree_fixup (struct node *n);
    void find (struct node *n, std::vector<long> &res, double first, double last);

};//class
#endif