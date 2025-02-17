#include <stdio.h>
#include <stdlib.h>

//cria o tipo de dado ArvoreNo
typedef struct arvNo ArvoreNo;              

//cria a estrutura de cada nó da árvore
struct arvNo                            
{
  char info;
  ArvoreNo* esquerda;
  ArvoreNo* direita;
};

//cria o tipo de dado Arvore
typedef struct arvore Arvore;           

//cria a estrutura da árvore apontando a raiz do nó
struct arvore
{
  ArvoreNo* raiz;
};

//função que cria o nó
ArvoreNo* criarNo (char elemento, ArvoreNo* esq, ArvoreNo* dir){
  ArvoreNo* p = (ArvoreNo*) malloc(sizeof (ArvoreNo));            //p = ponteiro
  p->info = elemento;
  p->esquerda = esq;
  p->direita = dir;

  return p;
}

//função que cria e aponta para o nó raiz
Arvore* criarArvore (ArvoreNo* r){
  Arvore* a = (Arvore*) malloc(sizeof(Arvore));               //a = ponteiro
  a->raiz = r;
  printf("\nÁrvore criada com sucesso: ");
  return a;
}

//função recursiva para percorrer a árvore e inserir o elemento
static ArvoreNo* inserir(ArvoreNo* atual, char elemento) {
  if (atual == NULL) {
    return criarNo(elemento, NULL, NULL);
  }

  if (elemento < atual->info) {
    atual->esquerda = inserir(atual->esquerda, elemento);
  } else if (elemento > atual->info) {
    atual->direita = inserir(atual->direita, elemento);
  } else {
    printf("Elemento já inserido na árvore.\n");
  }

  return atual;
}

//função que insere os elementos na árvore
void inserirElemento(Arvore* arvore, char elemento) {
  if (arvore == NULL) {
    printf("Crie uma árvore primeiro.");
    return;
  };

  if (arvore->raiz == NULL) {
    arvore->raiz = criarNo(elemento, NULL, NULL);
    return;
  }

  inserir(arvore->raiz, elemento);
}


//função auxiliar que exibe os elementos da árvore
static void imprime (ArvoreNo* r){
  if (r != NULL){
    printf("% c ", r->info);
    imprime(r->esquerda);
    imprime(r->direita);
  }
}

//função que imprime a árvore a partir da raiz
void imprimeArvore (Arvore* a){
  if (a == NULL) {
    printf("Crie a árvore primeiro.");
  };
  imprime(a->raiz);
}

//função auxiliar que libera a memória
static void liberarMemoria (ArvoreNo* r){
  if (r != NULL){
    liberarMemoria(r->esquerda);
    liberarMemoria(r->direita);
    free(r);
  }
}

//função que libera a memoria da raiz
void liberarRaiz (Arvore* a){
  liberarMemoria(a->raiz);
  free(a);
}

//função auxiliar que verifica se o elemento está na árvore
static int pertence (ArvoreNo* r, char c){
  if (r == NULL){
    return 0;
  }else{
    return c == r->info || pertence(r->esquerda, c) || pertence(r->direita, c);
  }
}

//função que verifica se o elemento é a raiz
int pertenceRaiz (Arvore* a, char c){
  return pertence(a->raiz, c);
}

//função auxiliar que busca e apresenta o elemento
static ArvoreNo* buscaElemento (ArvoreNo* r, char c){
  if (r == NULL){
    return NULL;
  }else if (c == r->info){
    return r;
  }else{
    ArvoreNo* p = buscaElemento(r->esquerda, c);
    if (p != NULL){
        return p;
    }else{
        return buscaElemento(r->direita, c);
    }
  }    
}

//função que busca e apresenta o elemento no nó raiz
ArvoreNo* buscaRaiz (Arvore* a, char c){
  return buscaElemento(a->raiz, c);
}

void menu() {
  printf("\nSEJA BEM-VINDO(A) À ÁRVORE DE BUSCA BINÁRIA COM AS LETRAS DO ALFABETO\n");

  int opcao;

  do {
    printf("\n====== MENU ======\n");
    printf("0 - Ir para dicas\n");
    printf("1 - Criar árvore binária de busca\n");
    printf("2 - Inserir elemento\n");
    printf("3 - Remover elemento\n");
    printf("4 - Imprimir árvore (Pré-ordem)\n");
    printf("5 - Total de nós\n");
    printf("6 - Total de folhas\n");
    printf("7 - Altura da árvore\n");
    printf("8 - Verificar se a árvore é própria\n");
    printf("9 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      char elemento;
      Arvore* arvore;

      case 0:
        printf("\nA cada vez que o programa roda só é aconselhado criar somente uma árvore, pois ao criar outra ela irá reescrever a anterior.");
        printf("\nSempre utilize o comando 9 para sair do programa e liberar espaço para evitar vazamento de memória.");
        printf("\nUtilize os caracteres do alfabeto para que árvore respeita a tabela ASCII ao inserir os elementos.");
        printf("\nAproveite nosso código, prof!");
        break;

      case 1:
        printf("\nDigite o elemento da raiz: ");
        scanf(" %c", &elemento);

        arvore = criarArvore(criarNo(elemento, NULL, NULL));
        imprimeArvore(arvore);
        printf("\n");
        break;

      case 2:
        printf("\nDigite o elemento a ser inserido: ");
        scanf(" %c", &elemento);
        inserirElemento(arvore, elemento);
        printf("\n Árvore atual: ");
        imprimeArvore(arvore);
        printf("\n");
        break;

          // case 3:
          //     printf("Digite o elemento a ser removido: ");
          //     scanf(" %c", &elemento);
          //     arvore->raiz = remover(arvore->raiz, elemento);
          //     break;

        case 4:
          printf("Árvore (Pré-ordem): ");
          imprimeArvore(arvore);
          printf("\n");
          break;

          // case 5:
          //     printf("Total de nós: %d\n", contarNos(arvore->raiz));
          //     break;

          // case 6:
          //     printf("Total de folhas: %d\n", contarFolhas(arvore->raiz));
          //     break;

          // case 7:
          //     printf("Altura da árvore: %d\n", calcularAltura(arvore->raiz));
          //     break;

          // case 8:
          //     printf("A árvore é %s\n", ehPropria(arvore->raiz) ? "própria" : "imprópria");
          //     break;

        case 9:
          printf("Saindo e liberando espaço na memória...\n");
          liberarRaiz(arvore);
          break;
    }
  } while (opcao != 9);
}

int main() {
  menu();

  return 0;
}