/* Laboratório 12: RubixCaptcha 
   Arquivo de Cabeçalho: lab12.h   */

/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente a uma placa do cubo
   Saida:    Nao ha

   Objetivo: Rotacionar a placa 90 graus no sentido Horario      */
void rotate_board_CW(char* board);



/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente a uma placa do cubo
   Saida:    Nao ha

   Objetivo: Rotacionar a placa 90 graus no sentido Anti-Horario */
void rotate_board_CCW(char* board);



/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente ao cubo
   Saida:    Nao ha

   Objetivo: Rotacionar todas as placas 90 graus no sentido 
             Horario                                             */
void rotate_all_CW(char* cube);



/* Entrada:  Apontador para um vetor (linearizado) de caracteres
             correspondente ao cubo
   Saida:    Nao ha

   Objetivo: Rotacionar todas as placas 90 graus no sentido
             anti-Horario                                        */
void rotate_all_CCW(char* cube);

