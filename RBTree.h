#ifndef RBTree_h
#define RBTree_h

typedef struct RBtree{
  int key;
  int color;
  struct RBtree *r;
  struct RBtree *l;
  struct RBtree *p;
}RBtree;

typedef struct {
  RBtree *root;
}Tree;

Tree *createNTree();
void insertRB(Tree *T, int key);
void Terminal(RBtree *root);
#endif