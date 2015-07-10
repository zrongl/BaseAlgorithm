//
//  binary_tree.c
//  Algorithm
//
//  Created by ronglei on 14-7-1.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "data_structure.h"

void init_binary_tree(Binary_Tree_Node_Ptr *tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *tree = NULL;
    }else{
        *tree = (Binary_Tree_Node_Ptr)malloc(sizeof(Binary_Tree_Node));
        if (*tree == NULL) {
            exit(-1);
        }
        
        (*tree)->data = ch;
        
        init_binary_tree(&((*tree)->lchild));
        init_binary_tree(&((*tree)->rchild));
    }
}

void pre_order_traverse(Binary_Tree_Node_Ptr tree)
{
    if (tree == NULL) {
        return;
    }
    
    printf("%c", tree->data);
    
    pre_order_traverse(tree->lchild);
    pre_order_traverse(tree->rchild);
}

void mid_order_traverse(Binary_Tree_Node_Ptr tree)
{
    if (tree == NULL) {
        return;
    }
    
    mid_order_traverse(tree->lchild);
    printf("%c", tree->data);
    mid_order_traverse(tree->rchild);
}

void last_order_traverse(Binary_Tree_Node_Ptr tree)
{
    if (tree == NULL) {
        return;
    }
    
    last_order_traverse(tree->lchild);
    last_order_traverse(tree->rchild);
    
    printf("%c", tree->data);
}
