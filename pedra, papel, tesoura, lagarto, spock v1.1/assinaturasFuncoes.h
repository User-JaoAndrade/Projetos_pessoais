#ifndef PPTLS_h
#define PPTLS_h

void Menu(); //Menu do jogo
void ApagarLinhaAnterior(); //Apagar linha anterior pro jogador nao ver oq foi jogado
void Escolhas(); //Receber as escolhas dos jogadores
void Condicoes(char jogada[2]); //Condicoes baseadas nas escolhas dos jogadores
void FrasesDeEfeitoBala(char jogada[2]); //Mostrar quem venceu quem

#endif