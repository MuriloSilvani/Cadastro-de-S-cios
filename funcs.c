#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"

void cadastrarSocios(int *contador, SOCIO *socio){
  int confirma=0;
  do
  {
    system("cls");
    socio+=*contador;
    fflush(stdin);
    printf("Nome do Socio: ");
    fgets(socio->nome,255,stdin);
    printf("Idade: ");
    scanf("%d", &socio->idade);
    do{	
      printf("Estado Civil:\n\t1 - Casado\n\t2 - Solteiro\n\t3 - Divorciado\n\t4 - Viuvo\n\tR: ");
      scanf("%d", &socio->estadocivil);
    }while(socio->estadocivil<1||socio->estadocivil>4);
    do{	
      printf("Grau de Instrucao:\n\t1 - Fundamental\n\t2 - Secundario\n\t3 - Superior\n\tR: ");
      scanf("%d", &socio->grauinstrucao);
    }while(socio->grauinstrucao<1||socio->grauinstrucao>3);
    do{	
      printf("Turno: \n\t1 - Manha\n\t2 - Tarde\n\t3 - Noite\n\tR: ");
      scanf("%d", &socio->turn);
    }while(socio->turn<1||socio->turn>3);
    do{	
      printf("Atividade: \n\t1 - Natacao\n\t2 - Hidroginastica\n\t3 - Danca\n\t4 - Kung Fu\n\t5 - Violao\n\t6 - Futebol\n\t7 - Volei\n\tR: ");
      scanf("%d", &socio->ativ);
    }while(socio->ativ<1||socio->ativ>7);
    socio->matricula = *contador+1001;
    
    system("cls");
    printf("Confimarma Cadastro:\n");
    printf("\tMatricula: %d\n\tNome: %s\tIdade: %d\n\tEstado Civil: %d\n\tGrau de Instrucao: %d\n\tTurno: %d\n\tAtividade: %d", 
    socio->matricula,socio->nome,socio->idade,socio->estadocivil,socio->grauinstrucao,socio->turn,socio->ativ);
    printf("\n\n1 - Confirmar Cadastro\n2 - Refazer Cadastro\n3 - Cancelar Cadastro");
    scanf("%d", &confirma);
    if(confirma==3){*contador-=1;confirma=1;}
  }while(confirma!=1);
  *contador+=1;
}
void mostrarSocios(int *contador, SOCIO *socio){
  for(int i = 0 ; i < *contador; i++){
    printf("-----------------------\n");
    
    printf("Matricula: %d\n", socio->matricula);
    printf("Nome: %s", socio->nome);
    printf("Idade: %d\n", socio->idade);
    printf("Estado Civil: %d\n", socio->estadocivil);
    printf("Grau de Instrucao: %d\n", socio->grauinstrucao);
    printf("Turno: %d\n", socio->turn);
    printf("Atividade: %d\n", socio->ativ);
    
    printf("\n-----------------------\n");
    socio+=1;
    
  }
  char menu;
  fflush(stdin);
  printf("Pressione uma tecla para continuar");
  scanf("%c", &menu);
}
void estatisticaSocios(int *contador, SOCIO *socio){
  STATS estatisticas={0,0,0,0,0,0,0,"",""};
  int medSupe=0,medCasa=0,idoFute=0, idoKung=99;
  for(int i=0; i<*contador;i++){

    if(socio->turn==1){estatisticas.socMan+=1;}
    if(socio->turn==2){estatisticas.socTar+=1;}
    if(socio->turn==3){estatisticas.socNoi+=1;}
    if(socio->grauinstrucao==3){medSupe+=1;estatisticas.medSup=estatisticas.medSup+socio->idade;}
	if(socio->estadocivil==1){medCasa+=1;estatisticas.medCas=estatisticas.medCas+socio->idade;}
    if(socio->ativ==1){estatisticas.socNat=+1;}
    if(socio->ativ==2){estatisticas.socHid=+1;}
    if(socio->ativ==6 && socio->idade > idoFute){
      idoFute = socio->idade;
      strcpy(estatisticas.idoFut,socio->nome);
    }
    if(socio->ativ==4 && socio->idade < idoKung){
      idoKung = socio->idade;
      strcpy(estatisticas.idoKun,socio->nome);
      
    }
    socio+=1;
  }
  if(medSupe>0){estatisticas.medSup=estatisticas.medSup/medSupe;}
  if(medCasa>0){estatisticas.medCas=estatisticas.medCas/medCasa;}
  
  printf("------------------------------------\n");
  printf("Total de Socios: %d\n", *contador);
  printf("------------------------------------\n");
  printf("Socios Matutinos: %d\n", estatisticas.socMan);
  printf("Socios Verpertinos: %d\n", estatisticas.socTar);
  printf("Socios Noturnos: %d\n", estatisticas.socNoi);
  printf("------------------------------------\n");
  printf("Media de idade dos socios com Ensino Superior: %d\n", estatisticas.medSup);
  printf("Media de idade dos Socios Casados: %d\n", estatisticas.medCas);
  printf("------------------------------------\n");
  printf("Total de socio que fazem Natacao: %d\n", estatisticas.socNat);
  printf("Total de socio que fazem Hidroginastica: %d\n", estatisticas.socHid);
  printf("------------------------------------\n");
  printf("Socio mais idoso que faz Futebol: %s\n", estatisticas.idoFut);
  printf("Socio mais jovem que faz Kung Fu: %s\n", estatisticas.idoKun);
  printf("------------------------------------\n");

  char menu;
  fflush(stdin);
  printf("\n\nPressione uma tecla para continuar");
  scanf("%c", &menu);
  
}