#include <stdio.h>
#include <windows.h>
#include "RBTree.h"

int main(void){
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nAlgoritmo para plotar arvores rubro negras\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    Sleep(2000);
    system("cls");
    Tree *T = createNTree();
    int k;
    int V[] = {13, 8, 17, 1, 11, 15, 25, 6, 22, 27};
    int i=0;
    //scanf("%d", &k);
    do{
        insertRB(T, V[i]);
        //scanf("%d", &k);
        i++;
    }while(/*k!=-1 &&*/ i!=10);
    Terminal(T->root, "");
    return 0;
}