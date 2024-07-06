#include "assinaturasFuncoes.h"

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

// Variáveis globais para pontuação
int pontos1 = 0, pontos2 = 0;


void ApagarLinhaAnterior() {
    printf("\x1b[A"); // Move o cursor para cima
    printf("\x1b[2K"); // Apaga a linha
}

void Menu() {
    int option; 
    printf("  >>>MEU PRIMEIRO PROGRAMA DE PEDRA, PAPEL, TESOURA, LAGARTO, SPOCK<<<\n\n");

    printf("  MENU\n");
    printf("  1 - Iniciar partida\n  2 - Regras\n  X - Finalizar o Jogo\n\n");
    printf("  Opcao: ");
    scanf("%d", &option);

    // Condição de término de jogo
    if (option != 1 && option != 2) {
        char gameover[10] = "GAME OVER";
        printf("  ");
        for (int i = 0; i < 9; i++) { //Loop que vai mostrar letra por letra na tela
            printf("%c", gameover[i]);
            usleep(200000);
        }
        char umNomeJaFeito[36] = "Vida longa a Sam Kass e Karen Bryla";
        printf("\n  ");
        for(int i = 0; i < 35; i++){
            printf("%c", umNomeJaFeito[i]);
            usleep(200000);
        }
        printf("\n");
        return 0;
    } else if (option == 2) { //]Chama a funcao de regras
        system("cls");
        Regras();
    } else { //Chama a funcao que comeca o jogo
        system("cls");
        Escolhas();
    }
}

//Funcao que vai mostrar as regras do jogo
void Regras() {
    char a;
    printf("\n   >>>>>> REGRAS <<<<<<");
    printf("\n\n    Meus caros colegas intelectuais, hoje estarei expandindo suas mentes para além das fronteiras convencionais do jogo de Pedra, Papel e Tesoura.\n");
    printf("  Preparem-se para adentrar em um reino de complexidade e estratégia que só é compreensível para as mentes mais aguçadas, com a introdução do jogo: Pedra, Papel, Tesoura, Lagarto, Spock.\n\n");

    printf("    Vamos começar com os elementos básicos: Pedra, Papel e Tesoura.\n");
    printf("  Como vocês sabem, Pedra esmaga Tesoura, Tesoura corta Papel e Papel envolve Pedra.\n");
    printf("  Nada muito complicado até aqui, apenas a dinâmica usual do Pedra, Papel e Tesoura que todos nós conhecemos e amamos.\n\n");

    printf("    Agora, permitam-me apresentar os elementos adicionais: Lagarto e Spock.\n");
    printf("  O Lagarto é envenenado por Pedra e esmagado por Tesoura.\n");
    printf("  No entanto, ele devora Papel e envenena Spock.\n");
    printf("  Por outro lado, Spock desmente a lógica do jogo: ele vaporiza a Pedra e quebra a Tesoura, mas é incapaz de resistir ao Lagarto e é, por sua vez, superado pelo Papel.\n\n");

    printf("    Vocês podem ver como a adição desses elementos adicionais não apenas aumenta o número de possíveis combinações, mas também adiciona uma camada extra de estratégia e complexidade ao jogo.\n");
    printf("  É como se estivéssemos elevando o jogo de Pedra, Papel e Tesoura para um nível totalmente novo de sofisticação, adequado apenas para mentes brilhantes como as nossas.\n\n");

    printf("    Portanto, meus amigos, espero que agora vocês apreciem a verdadeira grandiosidade do jogo Pedra, Papel, Tesoura, Lagarto, Spock.\n");
    printf("  Que as batalhas intelectuais comecem!\n\n");

    printf("  Aperte qualquer tecla para voltar ao menu ");
    scanf(" %c", &a);

    if (a) {
        system("cls");
        Menu();
    }
}

//Funcao que o usuario vai escolher os valores
void Escolhas() {
    char jogada[2];
    printf("  OPCOES DE JOGADAS\n\n");

    printf("  Digite uma letra correspondente a sua jogada\n");
    printf("\n  R = PEDRA");
    printf("\n  P = PAPEL");
    printf("\n  T = TESOURA");
    printf("\n  L = LAGARTO");
    printf("\n  S = SPOCK");

    printf("\n\n  Player 1: ");
    scanf(" %c", &jogada[0]); 
    jogada[0] = tolower(jogada[0]); //Deixar a letra minuscula
    ApagarLinhaAnterior();

    //Caso o jogador coloque um valor invalido
    if(jogada[0] != 'r' && jogada[0] != 'p' && jogada[0] != 't' && jogada[0] != 'l' && jogada[0] != 's') {
        do {
            printf("  Informe um valor valido: "); scanf(" %c", &jogada[0]);
            jogada[0] = tolower(jogada[0]);
            ApagarLinhaAnterior();
        } while (jogada[0] != 'r' && jogada[0] != 'p' && jogada[0] != 't' && jogada[0] != 'l' && jogada[0] != 's');
    }
    ApagarLinhaAnterior();

    printf("\n  Player 2: ");
    scanf(" %c", &jogada[1]);
    jogada[1] = tolower(jogada[1]);
    ApagarLinhaAnterior();

    //Caso o jogador coloque um valor invalido
    if(jogada[1] != 'r' && jogada[1] != 'p' && jogada[1] != 't' && jogada[1] != 'l' && jogada[1] != 's') {
        do {
            printf("  Informe um valor valido: "); scanf(" %c", &jogada[1]);
            jogada[1] = tolower(jogada[1]);
            ApagarLinhaAnterior();
        } while (jogada[1] != 'r' && jogada[1] != 'p' && jogada[1] != 't' && jogada[1] != 'l' && jogada[1] != 's');
    }
    ApagarLinhaAnterior();
    Condicoes(jogada);

    return 0; // Retorna um valor inteiro
}

//Funcao que vai comparar os valores
void Condicoes (char jogada[2]){
    char a;

    //Caso Tesoura vença
    if ((jogada[0] == 't' && jogada[1] == 'p') || (jogada[0] == 't' && jogada[1] == 'l')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 1 Venceu");
        pontos1++;
    } 
    else if ((jogada[0] == 'p' && jogada[1] == 't') || (jogada[0] == 'l' && jogada[1] == 't')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 2 Venceu");
        pontos2++;
    }

    //Caso Pedra vença
    else if ((jogada[0] == 'r' && jogada[1] == 'l') || (jogada[0] == 'r' && jogada[1] == 't')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 1 Venceu");
        pontos1++;
    } 
    else if ((jogada[0] == 'l' && jogada[1] == 'r') || (jogada[0] == 't' && jogada[1] == 'r')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 2 Venceu");
        pontos2++;
    }

    //Caso Papel vença
    else if ((jogada[0] == 'p' && jogada[1] == 'r') || (jogada[0] == 'p' && jogada[1] == 's')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 1 Venceu");
        pontos1++;
    } 
    else if ((jogada[0] == 'r' && jogada[1] == 'p') || (jogada[0] == 's' && jogada[1] == 'p')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 2 Venceu");
        pontos2++;
    }

    //Caso Lagarto vença
    else if ((jogada[0] == 'l' && jogada[1] == 's') || (jogada[0] == 'l' && jogada[1] == 'p')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 1 Venceu");
        pontos1++;
    } 
    else if ((jogada[0] == 's' && jogada[1] == 'l') || (jogada[0] == 'p' && jogada[1] == 'l')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 2 Venceu");
        pontos2++;
    }

    //Caso Spock vença
    else if ((jogada[0] == 's' && jogada[1] == 't') || (jogada[0] == 's' && jogada[1] == 'r')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 1 Venceu");
        pontos1++;
    } 
    else if ((jogada[0] == 't' && jogada[1] == 's') || (jogada[0] == 'r' && jogada[1] == 's')) {
        FrasesDeEfeitoBala(jogada);
        printf("  Player 2 Venceu");
        pontos2++;
    }
    else { //Caso de empate
        printf("  EMPATE!!");
    }

    printf("\n\n  Pressione qualquer tecla para voltar ao menu "); scanf(" %c", &a);

    if(a) {
        system("cls");
        printf("  Player 1: %d Vitorias\n  Player 2: %d Vitorias\n\n", pontos1, pontos2);
        Menu();
    }
}

//Funcao pra mostrar as frases de vitoria
void FrasesDeEfeitoBala(char jogada[2]){
    printf("\n  IIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n\n");
    //Vitoria TESOURA
    if((jogada[0] == 't' && jogada[1] == 'p') || (jogada[0] == 'p' && jogada[1] == 't')){
        printf("   TESOURA CORTA PAPEL \n");
    }
    else if((jogada[0] == 't' && jogada[1] == 'l') || (jogada[0] == 'l' && jogada[1] == 't')){
        printf("   TESOURA DECAPITA O LAGARTO\n");
    }

    //Vitoria PEDRA
    else if((jogada[0] == 'r' && jogada[1] == 'l') || (jogada[0] == 'l' && jogada[1] == 'r')){
        printf("   PEDRA ESMAGA LAGARTO \n");
    }
    else if((jogada[0] == 'r' && jogada[1] == 't') || (jogada[0] == 't' && jogada[1] == 'r')){
        printf("   PEDRA QUEBRA TESOURA \n");
    }

    //Vitoria PAPEL
    else if((jogada[0] == 'p' && jogada[1] == 'r') || (jogada[0] == 'r' && jogada[1] == 'p')){
        printf("  PAPEL COBRE A PEDRA ");
    }
    else if((jogada[0] == 'p' && jogada[1] == 's') || (jogada[0] == 's' && jogada[1] == 'p')){
        printf("   PAPEL REFUTA O SPOCK \n");
    }

    //Vitoria LAGARTO
    else if((jogada[0] == 'l' && jogada[1] == 's')|| (jogada[0] == 's' && jogada[1] == 'l')){
        printf("  LAGARTO ENVENENA O SPOCK \n");
    }
    else if((jogada[0] == 'l' && jogada[1] == 'p') || (jogada[0] == 'p' && jogada[1] == 'l')){
        printf("   LAGARTO COME PAPEL \n");
    }

    //VITORIA SPOCK
    else if((jogada[0] == 's' && jogada[1] == 't') || (jogada[0] == 't' && jogada[1] == 's')){
        printf("   SPOCK QUEBRA A TESOURA \n");
    } 
    else{
        printf("   SPOCK VAPORIZA A PEDRA \n");
    }
    printf("\n  IIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n\n");
}
