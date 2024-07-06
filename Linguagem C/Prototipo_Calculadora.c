#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Função que mostra um menu pro usuario
void Menu(); 
//Função que realiza o calculo pedidos pelo usuario
double Calculo(char simbolo, double numero1, double numero2);

int main (void) {
   Menu();
}

void Menu(){
   char simbolo = ' ';
   double numero1 = 0, numero2 = 0;

   printf(">>> PROTOTIPO CALCULADORA JAO <<<\n\n");
   printf("'+' para soma");
   printf("\n'-' para subtracao");
   printf("\n'x' para multiplicacao");
   printf("\n'/' para divisao\n\n");

   printf("========================================");

   printf("\n\nNumero 1: "); scanf("%lf", &numero1);
   printf("Nome provisorio: "); scanf ("%s", &simbolo);
   simbolo = tolower(simbolo);
   printf("Numero 2: "); scanf("%lf", &numero2);

   printf("Resultado: %.2f\n\n", Calculo(simbolo, numero1, numero2));

   printf("Digite qualquer tecla e aperte ENTER para continuar"); scanf("%s", &simbolo);
   if (simbolo) {
      system ("cls");
      Menu();
   }
}

double Calculo(char simbolo, double numero1, double numero2){
   switch(simbolo) {
      case '+':
         return numero1 + numero2;
         break;
      
      case '-':
         return numero1 - numero2;
         break;
      
      case 'x':
         return numero1 * numero2;
         break;
      
      case '/':
         return numero1 / numero2;
         break;
   }
}