#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"

int main()
{
  int contador = 0;
  char finalizar = '0';
  
  SOCIO socio[100];//limite de socios 100//

  do{
    printf("---- OI SOCIO :) ----\n\n");
    printf("1 - cadastrar\n2 - mostrar cadastrados\n3 - Estatisticas\n4 - sair\n\n");
    scanf("%c", &finalizar);
    if(finalizar<1|| finalizar>4){printf("Digita certo");}
    switch(finalizar)
    {
      case '1':
      system("cls");
      
      cadastrarSocios(&contador, socio);
      
      system("cls");
      break;
      case '2':
      system("cls");
      
      mostrarSocios(&contador, socio);
      
      system("cls");
      break;
      case '3':
      system("cls");

      estatisticaSocios(&contador, socio);
      
      system("cls");
      break;
      case '4':
      system("cls");
      
      printf("\n\n------- Falou -------\n\n");
      
      break;
      default :
      system("cls");
    }
    
  }while(finalizar!='4');
  
  return 0;
}