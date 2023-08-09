#include "rbtree.h"

// returns the size of the tree.
long RB_Tree::size () {
    return size_;
}

// find keys on an interval and inserts on vector.
void RB_Tree::find_interval( std::vector<long> &res, double first, double last ) {
    res.clear();
    find(root_, res, first, last);  
}

// recursive auxiliary function for find function.
void RB_Tree::find(struct node *x, std::vector<long> &res, double first, double last ) {
    if (x != NIL) {
        if (x->key > first && x->key < last) {
            res.push_back(x->idx);
            find(x->left, res, first, last);
            find(x->right, res, first, last);
        }
        else if (x->key < first) {
            find(x->right, res, first, last);
        }
        else {
            find(x->left, res, first, last);
        }
    }
}

// inserts a new element to the index in the tree.
void RB_Tree::insert (double key, long idx ) {
    node *z = new node;
    node *y = NIL;
    node *x = root_;
    z->key = key;
    z->idx = idx;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }
    z->p = y;
    if (y == NIL) {
        root_ = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->left = NIL;
    z->right = NIL;
    z->color = RED;
    tree_fixup(z);
    size_ += 1;
    return;
}

// left rotation of the pointers at node x.
void RB_Tree::left_rotate (struct node *x) {
    node *y = x->right; // set y
    x->right = y->left; // turn y's left subtree into x's right subtree
    if (y->left != NIL) {
        y->left->p = x;
    }
    y->p = x->p; // link x's parent to y
    if (x->p == NIL) {
        root_ = y;
    }
    else if (x == x->p->left) {
        x->p->left = y;
    }
    else {
        x->p->right = y;
    }
    y->left = x;
    x->p = y;
}

// right rotation of the pointers at node y.
void RB_Tree::right_rotate (struct node *y) {
    node *x = y->left; // set x
    y->left = x->right; // turn x's right subtree into y's left subtree
    if (x->right != NIL) {
        x->right->p = y;
    }
    x->p = y->p; // link y's parent to x
    if (y->p == NIL) {
        root_ = x;
    }
    else if (y == y->p->left) {
        y->p->left = x;
    }
    else {
        y->p->right = x;
    }
    x->right = y;
    y->p = x;
}

// restore the Red-Black properties at node z subtree.
void RB_Tree::tree_fixup (struct node *z) {
    node *y;
     while (z->p->color == RED) {
        if (z->p == z->p->p->left) {
            y = z->p->p->right;
            if (y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else {
                if (z == z->p->right) {
                    z = z->p;
                    left_rotate(z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                right_rotate(z->p->p);
            }
        }
        else {
           y = z->p->p->left;
            if (y->color == RED) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            }
            else {
                if (z == z->p->left) {
                    z = z->p;
                    right_rotate(z);
                }
                z->p->color = BLACK;
                z->p->p->color = RED;
                left_rotate(z->p->p);
            } 
        }
        root_->color = BLACK;
     }
}

// class constructor.
RB_Tree::RB_Tree () {
  root_ = new node;
  NIL = new node;
  size_ = 0;

  NIL->color = BLACK;
  root_->color = BLACK;
  NIL->left = NIL->right = NIL->p = NIL;
  root_->left = root_->right = root_->p = NIL;
}

// class destructor.
RB_Tree::~RB_Tree () {
  clear_tree(root_);
  delete NIL;
}

// recursevely clears the node x subtree.
void RB_Tree::clear_tree (struct node *x) {
  if (x != NIL) {
    clear_tree(x->left);
    clear_tree(x->right);
    delete x;
  }
}