#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do produto
struct Produto {
    char nome[30];   // Nome do produto
    int codigo;      // Código do produto
    double preco;    // Preço do produto
};

// Definição da estrutura do nó da lista
typedef struct node {
    struct Produto produto;
    struct node* next;
} Node;

// Função para adicionar um produto ao final da lista
void adicionarProduto(Node** lista) {
    Node* novoProduto = (Node*)malloc(sizeof(Node));
    if (novoProduto == NULL) {
        printf("Erro: falha ao alocar memória para novo produto.\n");
        return;
    }

    printf("Digite o nome do produto: ");
    getchar(); // Limpa o buffer de entrada
    fgets(novoProduto->produto.nome, sizeof(novoProduto->produto.nome), stdin); // Lê o nome do produto com espaços
    novoProduto->produto.nome[strcspn(novoProduto->produto.nome, "\n")] = '\0'; // Remover o \n do final

    printf("Digite o código do produto: ");
    scanf("%d", &novoProduto->produto.codigo); // Lê o código do produto

    printf("Digite o preço do produto: ");
    scanf("%lf", &novoProduto->produto.preco); // Lê o preço do produto

    novoProduto->next = NULL;

    if (*lista == NULL) {
        *lista = novoProduto; // Lista vazia, novo produto é o primeiro da lista
    } else {
        Node* temp = *lista;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoProduto; // Adiciona o novo produto no final da lista
    }

    printf("Produto adicionado com sucesso!\n");
}

// Função para exibir todos os produtos da lista
void exibirLista(Node* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista de Produtos:\n");
    Node* temp = lista;
    while (temp != NULL) {
        printf("Nome: %s, Código: %d, Preço: %.2lf\n", temp->produto.nome, temp->produto.codigo, temp->produto.preco);
        temp = temp->next;
    }
}

// Função para buscar um produto pelo nome na lista
void buscarProdutoPorNome(Node* lista, const char* nomeBuscado) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node* temp = lista;
    while (temp != NULL) {
        if (strcmp(temp->produto.nome, nomeBuscado) == 0) {
            printf("Produto encontrado:\n");
            printf("Nome: %s, Código: %d, Preço: %.2lf\n", temp->produto.nome, temp->produto.codigo, temp->produto.preco);
            return;
        }
        temp = temp->next;
    }

    printf("Produto com o nome '%s' não encontrado.\n", nomeBuscado);
}

// Função para liberar a memória alocada para a lista
void liberarLista(Node** lista) {
    Node* temp = *lista;
    while (temp != NULL) {
        Node* prox = temp->next;
        free(temp);
        temp = prox;
    }
    *lista = NULL;
}

int main() {
    Node* listaProdutos = NULL;
    int opcao;
    char nomeBusca[30];

    do {
        printf("\nINSTRUÇÕES\n");
        printf("Digite um produto por vez\n");
        printf("Itens com nomes compostos podem ser adicionados (EX: Banana Prata)\n");
        printf("O código do produto não pode conter virgulas\n");
        printf("Utilize Ponto final (.) para separa o preçõ\n");


        printf("\nMenu:\n");
        printf("1. Adicionar produto\n");
        printf("2. Exibir lista de produtos\n");
        printf("3. Buscar produto por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        // Verificar se a entrada é um número válido
        if (scanf("%d", &opcao) != 1) {
            printf("Erro: opção inválida. Digite um número de 1 a 4.\n");
            scanf("%*s"); // Limpar o buffer de entrada
            continue;
        }

        switch (opcao) {
            case 1:
                adicionarProduto(&listaProdutos);
                break;
            case 2:
                exibirLista(listaProdutos);
                break;
            case 3:
                printf("Digite o nome do produto a ser buscado: ");
                getchar(); // Limpa o buffer de entrada
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Remover o \n do final
                buscarProdutoPorNome(listaProdutos, nomeBusca);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                liberarLista(&listaProdutos);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
