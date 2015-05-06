//
//  binary_tree.c
//  Algorithm
//
//  Created by ronglei on 14-7-1.
//  Copyright (c) 2014年 ronglei. All rights reserved.
//

#include "data_structure.h"

void bitree_init(BiTree *tree)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        *tree = NULL;
    }else{
        *tree = (BiTree)malloc(sizeof(BiTNode));
        if (*tree == NULL) {
            exit(-1);
        }
        
        (*tree)->data = ch;
        
        bitree_init(&((*tree)->lchild));
        bitree_init(&((*tree)->rchild));
    }
}

void pre_order_traverse(BiTree tree)
{
    if (tree == NULL) {
        return;
    }
    
    printf("%c", tree->data);
    
    pre_order_traverse(tree->lchild);
    pre_order_traverse(tree->rchild);
}

void mid_order_traverse(BiTree tree)
{
    if (tree == NULL) {
        return;
    }
    
    mid_order_traverse(tree->lchild);
    printf("%c", tree->data);
    mid_order_traverse(tree->rchild);
}

void last_order_traverse(BiTree tree)
{
    if (tree == NULL) {
        return;
    }
    
    last_order_traverse(tree->lchild);
    last_order_traverse(tree->rchild);
    
    printf("%c", tree->data);
}
