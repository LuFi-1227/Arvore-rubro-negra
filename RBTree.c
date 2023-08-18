#include "RBTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Preto "\033[30m"
#define Vermelho "\033[31m"
#define RESET "\x1B[0m"
#define BLACK 0
#define RED 1

Tree *createNTree(){
  Tree *aux = malloc(sizeof(Tree));
  aux->root = NULL;
  return aux;
}

RBtree *insertNkey(int key) {
  RBtree *aux = malloc(sizeof(RBtree));
  aux->key = key;
  aux->color = RED;
  aux->l = NULL;
  aux->p = NULL;
  aux->r = NULL;

  return aux;
}

void RightRot(Tree *T, RBtree *x) {
  RBtree *y = x->r;
  if(y!=NULL){
    x->r = y->l;
  if(y->l!=NULL){
    y->l->p = x;
  }
  y->p = x->p;
  if(x->p==NULL){
    T->root = y;
  }else{
    if(x==x->p->l){
      x->p->l = y;
    }else{
      x->p->r = y;
    }
  }
  y->l = x;
     x->p = y;
  }
}

void LeftRot(Tree *T, RBtree *x) {
  RBtree *y = x->l;
  x->l = y->r;
  if(y->r!=NULL){
    y->r->p = x;
  }
  y->p = x->p;
  if(x->p==NULL){
    T->root = y;
  }else{
    if(x==x->p->r){
      x->p->r = y;
    }else{
      x->p->l = y;
    }
  }
  y->r = x;
  x->p = y;
}

void RBInsertFix(Tree *T, RBtree *z){
  if(z->p!=NULL){
    if(z->p->color == RED){
      if (z->p == z->p->p->l) {
        RBtree *y;
        if(z->p->p->r!=NULL){
          y = z->p->p->r;
        }else{
          y = malloc(sizeof(RBtree));
          y->color = BLACK;
          y->p = z->p->p;
          z->p->p->r = y;
        }
        if (y->color == RED) {
          z->p->color = BLACK;
          y->color = BLACK;
          z->p->p->color = RED;
          z = z->p->p;
        } else {
          free(y);
          z->p->p->r = NULL;
          if (z == z->p->r) {
            z = z->p;
            LeftRot(T, z);
          }
          z->p->color = BLACK;
          z->p->p->color = RED;
          RightRot(T, z->p->p);
        }
      } else {
        RBtree *y;
        if(z->p->p->l!=NULL){
          y = z->p->p->l;
        }else{
          y = malloc(sizeof(RBtree));
          y->color = BLACK;
          y->p = z->p->p;
          z->p->p->l = y;
        }
        if (y->color == RED) {
          z->p->color = BLACK;
          y->color = BLACK;
          z->p->p->color = RED;
          z = z->p->p;
        } else {
          free(y);
          z->p->p->l = NULL;
          if (z == z->p->l) {
            z = z->p;
            RightRot(T, z);
          }
          z->p->color = BLACK;
          z->p->p->color = RED;
          LeftRot(T, z->p->p);
        }
      }
      RBInsertFix(T, z);
    }
  }else{
     T->root->color = BLACK;
    return;
  }
}

void insertRB(Tree * T, int key) {
  RBtree *aux3 = insertNkey(key), *aux2 = NULL, *aux = T->root;
  while (aux != NULL) {
    aux2 = aux;
    if (key > aux->key) {
      aux = aux->r;
    } else {
      aux = aux->l;
    }
  }
  aux3->p = aux2;
  if (aux2 == NULL) {
    T->root = aux3;
  } else {
    if (key > aux2->key) {
      aux2->r = aux3;
    } else {
      aux2->l = aux3;
    }
  }
  RBInsertFix(T, aux3);
}

void Terminal(RBtree *root) {
  if (root != NULL) {
    if (root->l != NULL)
      Terminal(root->l);
    if(root->color == BLACK)
      printf(Preto "%d, ", root->key);
    else
      printf(Vermelho "%d, ", root->key);
    if (root->r != NULL)
      Terminal(root->r);
  }
  printf(RESET);
}