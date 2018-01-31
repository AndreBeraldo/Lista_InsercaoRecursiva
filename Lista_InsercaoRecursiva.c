/**      Desenvolvido por: Andre Vitor Beraldo
*   Instituicao: Universidade Federal de Itajuba (UNIFEI)
*           Curso: Ciencias da Computacao
*/

#include <stdio.h>
#include <stdlib.h>

struct no_lista {
    int dado;
    struct no *prox;
};

        //////////////////
        /*  PROTOTIPOS  */
        //////////////////

typedef struct no_lista NODE;
void bem_vindo();
NODE *inserir_Lista(NODE *lista, int elemento);
void exibe_lista (NODE *lista);
int main();

          ////////////
          /*  MAIN  */
          ////////////

int main(){
    NODE *lista = NULL;
    int valor_menu, elemento;
    while(1){
        bem_vindo();
        printf("\nEscolha uma opcao: ");
        printf("\n1 - Inserir elemento");
        printf("\n2 - Exibir lista");
        printf("\n0 - Sair da aplicacao\n\n");

        printf("Escolha: ");
            scanf("%d", &valor_menu);

            switch(valor_menu){
                case 1: //inserção na lista recursiva.
                    printf("\nElemento a ser inserido: ");
                    scanf("%d", &elemento);

                    lista = inserir_Lista(lista, elemento);

                    printf("\nAperte qualquer tecla para continuar...");
                    getch();
                    system("cls");
                break;

                case 2: //exibir lista recursiva.
                    exibe_lista(lista);

                    printf("\nAperte qualquer tecla para continuar...");
                    getch();
                    system("cls");
                break;
                case 0:
                    printf("\nObrigado pela execucao!\n");
                    exit(1);
                break;
            }
    }
}

        //////////////////
        /*   METODOS    */
        //////////////////

void bem_vindo(){
    printf("/--------------------------------------------------|\n");
    printf("|         UNIVERSIDADE FEDERAL DE ITAJUBA          |\n");
    printf("|          LISTA - INSERCAO RECURSIVA              |\n");
    printf("|--------------------------------------------------|\n");
    printf("|              ANDRE VITOR BERALDO                 |\n");
    printf("|--------------------------------------------------/\n");
}


NODE *inserir_Lista(NODE *lista, int elemento){
    if(lista == NULL){
        lista = (NODE*) malloc(sizeof(NODE));
        if(lista == NULL){
            printf("Erro de alocacao!\n");
            exit(1);
        }

        lista->dado = elemento;
        lista->prox = NULL;
    }else{
        lista->prox = inserir_Lista(lista->prox, elemento);
    }
    return (lista);
}


void exibe_lista (NODE *lista){

    if(lista == NULL){
        printf("\nLista vazia!\n");
        return;

    }else{
        printf("\nValores: ");

        while(lista != NULL){
            printf("%d ", lista->dado);
            lista = lista->prox;
        }
    }
}
