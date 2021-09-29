#include <stdio.h>
#include <stdlib.h>


void imprime_saida(const int *pontuacao, int num_jogadores) {
    int vencedor = -1;
    int maior_pontuacao = -1;

    for (int jogador = 1; jogador <= num_jogadores; jogador++) {
        printf("Jogador %d: %d pontos\n", jogador, pontuacao[jogador]);

        if (pontuacao[jogador] > maior_pontuacao) {
            maior_pontuacao = pontuacao[jogador];
            vencedor = jogador;
        }
    }
    printf("\nO Jogador %d foi o vencedor!\n", vencedor);
}


int main() {
    int num_jogadores, num_cartas;

    scanf("%d %d", &num_jogadores, &num_cartas);
    
    // alocando um vetor dinâmico para armazenar a pontuação dos jogadores
    // [0]
    // [1] ==> Jogador 1
    // [2] ==> Jogador 2
    // [3] ==> Jogador 3
    // ...
    //
    // obs: lembre-se que o calloc já atribui valor 0 para cada elemento do vetor
    int *pontuacao = (int*) calloc(num_jogadores+1, sizeof(int));

    // alocando um vetor estático para armazenar o poço d'água
    // [0]
    // [1] ==> Camundongo (força 1)
    // [2] ==> Suricato (força 2)
    // [3] ==> Zebra (força 3)
    // ...
    //
    // obs: Vetores estáticos não possuem valores setados por padrão (como o calloc)
    //      logo, precisamos atribuir algum valor.
    //      No caso, como o poço d'água somará/contará/armazenará a qtde de cartas
    //      para cada animal (contador), precisamos começar com valor 0.
    int poco_dagua[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    // alternativamente
    // for (int i = 0; i < 9; i++) {
    //     poco_dagua[i] = 0;
    // }
    

    // para cada rodada (de 0 até num_cartas-1)
    for (int rodada = 0; rodada < num_cartas; rodada++) {
        // descobrindo o (índice) jogador da rodada
        // 0 ==> [1]
        // 1 ==> [2]
        // 2 ==> [3]
        // 3 ==> [1]
        // 4 ==> [2]
        // 5 ==> [3]
        // ...
        int jogador = (rodada % num_jogadores) + 1;

        // remove a carta do topo da pilha
        int carta;
        scanf("%d", &carta);

        // coloca a carta no poço d'água
        poco_dagua[carta]++;

        // se há 3 ou mais cartas do animal que eu acabei de jogar
        if (poco_dagua[carta] >= 3) {
            // tentar espantar animais

            // Caso Especial: se a carta jogada for de um camundongo
            if (carta == 1) {
                // se há elefantes na poça d'água
                if (poco_dagua[8] != 0) {
                    // some a pontuacao ao jogador da rodada
                    pontuacao[jogador] += poco_dagua[8];
                    // espante o elefante
                    poco_dagua[8] = 0;
                }
            }
            else {
                // espantar o animal mais fraco mais próximo
                for (int carta_animal_mais_fraco = carta - 1;
                         carta_animal_mais_fraco >= 1;
                         carta_animal_mais_fraco--) {
                    // se existe o animal `carta_animal_mais_fraco` na poça d'água
                    if (poco_dagua[carta_animal_mais_fraco] != 0) {
                        // espanta o animal mais fraco mais próximo
                        // some a pontuacao ao jogador da rodada
                        pontuacao[jogador] += poco_dagua[carta_animal_mais_fraco];
                        // espante o o animal mais fraco mais próximo
                        poco_dagua[carta_animal_mais_fraco] = 0;

                        // sai do for-loop
                        // não preciso mais procurar por animais mais fracos
                        break;
                    }
                }
            }
        }
    }

    // imprime a saída
    imprime_saida(pontuacao, num_jogadores);

    free(pontuacao);

    return 0;
}
