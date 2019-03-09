/*
 * File Name:    RBTree.cpp
 * Author:       sunowsir
 * Mail:         sunowsir@protonmail.com
 * GitHub:       github.com/sunowsir
 * Created Time: 2019年03月08日 星期五 16时01分01秒
 * */

#include "./RBTree.h" 
#include <iostream>
#include <stdlib.h>

namespace Sunow_RBT_Lib {
    template <typename KEY, typename VALUE>
    class RBTree {
    private : 
        struct RBTNode {
            KEY key;
            VALUE value; 
            int color;
            RBTNode *lchild, *rchild;
        };
        const int RED = 0;
        const int BLACK = 1;
        const int DOUBLE_BLACK = 2;
        RBTNode *NIL, *root;
        
        void init_NIL();
        RBTNode *get_new_node(KEY key, VALUE value) {
            RBTNode *node = new RBTNode;
            node->key = key;
            node->value = value;
            node->color = RED;
            node->lchild = node->rchild = NIL;
            return node;
        }
    public : 
        RBTree(); 
        ~RBTree();
        bool insert(KEY key, VALUE value);
        bool erase(KEY key, VALUE value);
        bool erase_key(KEY key);
        bool erase_value(VALUE value);
        VALUE search_key(KEY key);
        KEY search_value(VALUE value);
    };
}

template <typename KEY, typename VALUE>
void Sunow_RBT_Lib::RBTree<KEY, VALUE>::init_NIL() {
    this->NIL = new RBTNode;
    this->NIL->color = BLACK;
    this->NIL->lchild = this->NIL->rchild = this->NIL;
    return ;
}

template <typename KEY, typename VALUE>
Sunow_RBT_Lib::RBTree<KEY, VALUE>::RBTree() {
    init_NIL();
    this->root = NIL;
}

template <typename KEY, typename VALUE>
Sunow_RBT_Lib::RBTree<KEY, VALUE>::~RBTree() {
    if (root == this->NIL) return ;
    this->root = this->root->lchild;
    ~RBTree();
    this->root = this->root->rchild;
    ~RBTree();
    free(this->root);
}







