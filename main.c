#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "RBTree.h"

int main(void){
    setlocale(LC_ALL, "Portuguese");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\nAlgoritmo para plotar arvores rubro negras\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    Sleep(2000);
    system("cls");
    Tree *T = createNTree();
    int k = 1;
    while(k!=0){
        printf("Digite a acao desejada:\n [1]-Adicionar no na arvore\n [2]-Ver a arvore\n [3]-Recomecar a arvore\n [0]-Sair do programa\n R: ");
        scanf("%d", &k);
        switch (k)
        {
        case 0:
        break;
        case 1:
            printf("Quantos nos deve-se adicionar na arvore?\nR: ");
            int i;
            scanf("%d", &i);
            for(int j=0; j<i; j++){
                int g;
                printf("Digite o numero a ser adicionado:\nR: ");
                scanf("%d", &g);
                insertRB(T, g);
            }
            Sleep(4000);
            system("cls");
            break;
        case 2:
            Terminal(T->root, "");
            printf("Digite [enter para continnuar]");
            scanf("%c");
            system("cls");
            break;
        case 3:
            T = createNTree();
            system("cls");
            break;
        default:
            printf("Operacao invalida\n");
            break;
        }
    }     
    return 0;
}