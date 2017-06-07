/* Laboratório 10: Blackjack de Solteiro *
 * Arquivo de Cabeçalho: lab10.h *
 * Descrição:   Este arquivo contém o pragma/cabeçalho das funções a serem implementadas neste laboratório. Cada  *
 *              função contém uma breve descrição sobre o seu objetivo, a saída esperada e uma pequena explicação *
 *              dos parâmetros de entrada.
 */

/* -=-=-=-=-=-=-=-=-=-=-=- Definições que podem ser utilizadas na main() -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#define TAMANHO_HAND 11
#define TAMANHO_BARALHO 52

/* -=-=-=-=-=-=-=-=-=-=-=- Pragmas/Cabeçalhos de Funções (à serem desenvolvidas) -=-=-=-=-=-=-=-=-=-=-=- */

/* Basic Strategy                                                                                           *
 * Objetivo:    Dadas a mão do jogador e a carta visível do crupiê, decide qual jogada deverá ser realizada *
 * Saída:       Jogada a ser realizada: 0, caso "Hit"; 1, caso "Double Down"; 2, caso "Stand"               *
 * Parâmetros:                                                                                              *
 *      - char maoJogador[]:        um vetor que representa a mão do jogador                                *
 *      - int valorCartaCrupie:     o valor da carta do crupiê                                              *
 */
int basicStrategy(char maoJogador[], int valorCartaCrupie);

/* Hit                                                                              *
 * Objetivo:    Retirar uma carta do topo do _baralho_ e colocá-la em uma _mao_.    *
 * Saída:       _void_                                                              *
 * Parâmetros:                                                                      *
 *      - char baralho[]:   um vetor que representa o baralho.                      *
 *      - char mao[]:       um vetor que representa uma mao do jogo.                *     
 */
void hit(char baralho[], char mao[]);

/* Valor                                                                                    *
 * Objetivo:    Calcula o valor de uma mao                                                  *
 * Saída:       O valor da mão. Caso a mão seja uma "soft-hand", retorne o valor _negativo_ *
 * Parâmetros:                                                                              *
 *      - char mao[]:    um vetor que representa a mão de um jogador                        *
 */
int valor(char mao[]);

/* Crupiê                                                                 *
 * Objetivo:    Jogar a mão do crupiê.                                    *
 * Saída:       O valor da mão final do crupiê.                           *
 * Parâmetros:                                                            *
 *      - char baralho[]:     um vetor que representa o baralho.          *
 *      - char mao[]:         um vetor que representa a mão do crupiê.    *
 */
int crupie(char baralho[], char mao[]);

/* Blackjack                                                                  *
 * Objetivo:    Verificar se uma mão inicial é um Blackjack, ou seja, (A, 10) *
 * Saída:       Booleana: 0, caso não; 1, caso sim;                           *
 * Parâmetros:                                                                *
 *      - char mao[]:    vetor que representa a mão de um jogador.            *
 */
int blackjack(char mao[]);

/* Print Cards                                                            *
 * Objetivo:    Imprimir as cartas na mão de um jogador (ou crupiê)       *
 * Saída:       _void_                                                    *
 * Parâmetros:                                                            *
 *      - char mao[]:        um vetor que representa a mao de um jogador. *
 */
void printCards(char mao[]);
