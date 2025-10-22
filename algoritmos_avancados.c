#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da Sala (nó da árvore)
typedef struct Sala {
    char nome[50];           // Nome da sala
    struct Sala* esquerda;   // Ponteiro para a sala à esquerda
    struct Sala* direita;    // Ponteiro para a sala à direita
} Sala;

// Função para criar uma nova sala
Sala* criarSala(char nome[]) {
    Sala *nova = (Sala*) malloc(sizeof(Sala)); // Aloca memória

    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    strcpy(nova->nome, nome);   // Copia o nome
    nova->esquerda = NULL;
    nova->direita = NULL;

    return nova; // Retorna o ponteiro para a sala criada
}

//Função para conectar salas
void conectarSalas(Sala* principal, Sala* esquerda, Sala* direita) {
    principal-> esquerda = esquerda;
    principal-> direita = direita;
}


// Função para Explorar as salas
void explorarSalas(Sala* atual) {
    char opcao;

    while (1) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        printf("Digite 'e' para ir à esquerda, 'd' para ir à direita ou 's' para sair: ");
        scanf(" %c", &opcao);
        
        if (opcao =='s') {
            printf("Exploração encerrada.Até a próxima!\n");
            break;
        }    
        
        else if (opcao == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else{
                printf("Não há sala à esquerda!\n");
            }

            
        }
        else if (opcao == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("Não há sala à direita!\n");
            }
        }
        else {
            printf("opção inválida! Tente novamente.\n");
        }

        
        

    }
    
}

//Programa principal

int main() {
    printf("Desafio 🌱 Nível Novato jogo Detective Quest - Mapa da Mansão!\n");

    Sala *hall = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *sotao = criarSala("Sotão");
    Sala *jardim = criarSala("Jardim");

    //conexoes entre as salas
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, sotao, NULL);
    conectarSalas(cozinha,NULL, jardim);

    //Iniciar exploração
    explorarSalas(hall);

    //Lideração da memória
    free(hall);
    free(biblioteca);
    free(cozinha);
    free(sotao);
    free(jardim);

    return 0;
}

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().



