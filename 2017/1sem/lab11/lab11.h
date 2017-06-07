/* Laboratório 11: Tripulação, decolagem autorizada *
 * Arquivo de Cabeçalho: lab11.h *
 * Descrição:   Este arquivo contém o pragma/cabeçalho das funções a serem implementadas neste laboratório. Cada  *
 *              função contém uma breve descrição sobre o seu objetivo, a saída esperada e uma pequena explicação *
 *              dos parâmetros de entrada.
 */


/*Define o número máximo de cidades atendidas em um dia*/
#define MAX 10


/* -=-=-=-=-=-=-=-=-=-=-=- Pragmas/Cabeçalhos de Funções (a serem desenvolvidas) -=-=-=-=-=-=-=-=-=-=-=- */

/* Avalia Combinação                                                                                                    *
 * Objetivo:    Dada uma combinação atual, e a melhor combinação que já havia encontrado, determina se a                *
                nova combinação é melhor do que a melhor combinação que já havia encontrado.                            *
                Se sim, atualiza a melhor combinação, e o tempo atual das aeronaves.                                    *
 * Saída:       void                                                                                                    *
 * Parâmetros:                                                                                                          *
 *      - int *combinacao: apontador para o vetor que armazena a nova combinação que será avaliada                      *
 *      - int *melhorCombinacao: apontador para o vetor que armazena a melhor combinação que já foi avaliada            *
 *      - int *tempoVoo: apontador para o vetor que armazena os tempos de voos para cada destino                        *
 *      - int *paxIda: apontador para o vetor que armazena o número de passageiros que vão a todos os destinos          *
 *      - int *paxVolta: apontador para o vetor que armazena o número de passageiros que voltam de todos os destinos    *
 *      - int *tempoA: apontador para um inteiro que armazena o tempo percorrido pela aeronave A na melhor combinação   *
 *      - int *tempoB: apontador para um inteiro que armazena o tempo percorrido pela aeronave B na melhor combinação   *
 *      - int n: número de cidades atendidas naquele dia                                                                *
 */
void avaliaCombinacao(int *combinacao, int *melhorCombinacao, int *tempoVoo, int *paxIda, int *paxVolta, int *tempoA, int *tempoB, int n);


/* Próxima Combinação                                                                                                           *
 * Objetivo:    Determina qual a próxima combinação a ser avaliada                                                              *
 * Saída:       Um inteiro que indica que já foram percorridas todas as combinações possíveis, ou não                           *
 * Parâmetros:                                                                                                                  *
 *      - int *combinacao: apontador para o vetor que armazena a combinação que está sendo avaliada, e que deve ser atualizado  *
 *      - int n: número de cidades atendidas naquele dia                                                                        *
 */
int proxCombinacao(int *combinacao, int n);
