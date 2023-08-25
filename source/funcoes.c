#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu(char nome[]);
void executa();

void como_funciona(){
  system("clear");
  int opcao,aviso=0;

  do {
    printf(
        "|---------------------------------------------------------------|\n"
        "| O jogo funciona da seguinte forma: Você terá 10 chances para  |\n" 
        "| acertarum número de 1 a 100, haverá dicas para ajudar você    |\n"
        "|---------------------------------------------------------------|\n"
       );

    printf(
        "1)jogar\n"
        "2)Sair\n"
        ">> "
       );
     
    if( !scanf("%i",&opcao) ) {
      printf("Insira apenas números aqui!! O programa foi encerrado!!!\n");
      exit(1);
    }

    switch( opcao ) {
      case 1:
        executa();
      break;
      case 2:
        exit(1);
      break;
    }
    
    if(opcao <1 || opcao > 2){
      system("clear");
      aviso++;
      printf("Digite apenas 1 ou 2. Aviso(%i)\n",aviso);
    }

  }while(opcao < 1 || opcao > 2);
};

void executa(){
  srand(time(NULL));
  int random_num = rand() % 100 +1;
  int numero_testado;
  int chances=1;
  char dica[40] = "";
  
  system("clear");

  do {
    printf("Chances %i/10\n",chances);
    printf("Dica: %s\n",dica);
    printf("numero: ");
  
    if(!scanf("%i",&numero_testado)){
      printf("O programa foi encerrado, insira apenas numeros aqui!!!!\n");
      exit(1);
    }

    
    if(numero_testado == random_num){
      system("clear");
      printf("Parabens você ganhou!!\n");
      menu("jogar novamente   ");
    }else if(numero_testado > random_num){
      system("clear");
      strcpy(dica,"alto");
    }else if(numero_testado < random_num){
      system("clear");
      strcpy(dica,"baixo");
    }

    chances++;
  }while(chances <= 10);

  printf("Suas chances acabaram!! O número era %i\n",random_num);
  menu("Jogar novamente   ");
}


void menu(char nome[]){
  int opcao,aviso=0;

  do {
    printf(
    "|---------------------|\n"    
    "| 1)%s|\n"
    "| 2)Como jogar        |\n"
    "| 3)Sair              |\n"
    "|---------------------|\n",nome    
    );

     printf(">> ");
    if(!scanf("%i",&opcao)){
      printf("O programa foi abortado, apenas insira numero aqui!!\n");
      exit(1);
    };
    if(opcao < 1 || opcao > 3) {
      system("clear");
      aviso++;
      printf("Apenas insira 1 2 3 Aviso(%i)\n",aviso);
    }
  }while(opcao < 1 || opcao > 3 );
  
  switch( opcao ){
    case 1:
      executa();
    break;
    case 2:
      como_funciona();
    break;
    case 3:
      exit(0);
    break;
  } 

}


