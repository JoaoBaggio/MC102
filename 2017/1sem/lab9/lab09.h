/* Laboratório 09: Alice no País das Maravilhas *
 * Arquivo de Cabeçalho: lab09.h *
 * Descrição:   Este arquivo contém o pragma/cabeçalho das funções a serem implementadas neste laboratório. Cada  *
 *              função contém uma breve descrição sobre o seu objetivo, a saída esperada e uma pequena explicação *
 *              dos parâmetros de entrada.
 */

/* -=-=-=-=-=-=-=-=-=-=-=- Pragmas/Cabeçalhos de Funções (à serem desenvolvidas) -=-=-=-=-=-=-=-=-=-=-=- */

/* Converter Graus                                                                                         *
 * Objetivo:    Dado um valor em graus, retorna o equivalente em movimentos de um ponteiro no relógio      *
 * Saída:       Número de movimentos de um ponteiro do relógio                                             *
 * Parâmetros:                                                                                             *
 *      - unsigned int entrada: Valor em graus a ser convertido                                            *
 */
unsigned int converter_graus(unsigned int entrada);

/* Qual Personagem                                                                  *
 * Objetivo:    Determinar qual personagem é encontrado em determinado momento      *
 * Saída:       Um caractere que representa um personagem                           *
 * Parâmetros:                                                                      *
 *      - unsigned int minutos: Posição do ponteiro de minutos                      *
 */
char qual_personagem(unsigned int minutos);

/* Rainha                                                                                   *
 * Objetivo:    Determinar se Alice ganha ou perde a partida de críquete com a rainha       *
 * Saída:       Booleana: 0, caso não; 1, caso sim;                                         *
 * Parâmetros:                                                                              *
 *      - unsigned int tempo: O tempo decorrido desde o início da jornada de Alice          *
 */
int rainha(unsigned int tempo);

/* Valete                                                                                               *
 * Objetivo:    Determinar se Alice é decapitada                                                        *
 * Saída:       Booleana: 0, caso não; 1, caso sim;                                                     *
 * Parâmetros:                                                                                          *
 *      - unsigned int jogou_criquete:  Booleano que diz se Alice já jogou uma partida de criquete      *
 *      - unsigned int ganhou_criquete: Booleano que diz se Alice já ganhou uma partida de criquete     *
 */
int valete(unsigned int jogou_criquete, unsigned int ganhou_criquete);

/* Coelho                                                                                         *
 * Objetivo:    Determinar se Alice sai com o coelho do País das Maravilhas                       *
 * Saída:       Booleana: 0, caso não; 1, caso sim;                                               *
 * Parâmetros:                                                                                    *
 *      - unsigned int jogou_criquete: Booleano que diz se Alice já jogou uma partida de críquete *
 */
int coelho(unsigned int jogou_criquete);

/* Imprimir Personagens                                                             *
 * Objetivo:    Imprimir uma lista de personagens e retornar seu tamanho atual      *
 * Saída:       O tamanho do vetor de personagens após a impressão                  *
 * Parâmetros:                                                                      *
 *      - char personagens[]: Um vetor com uma lista de personagens a ser impressa  *
 *      - int numero:         O tamanho atual do vetor                              *
 */
int imprimir_personagens(char personagens[], int numero);

/* Imprimir Horário                                                               *
 * Objetivo:    Imprimir um horário no formato HH:MM:SS dado um valor de segundos *
 * Saída:       _void_                                                            *
 * Parâmetros:                                                                    *
 *      - unsigned int segundos: Número de segundos a ser impresso                *
 */
void imprimir_horario(unsigned int segundos);
