#ifndef header_h
#define header_h

typedef enum {casado=1,solteiro,divorciado,viuvo}estado_civil;
typedef enum {fundamental=1,secundario,superior}grau_instrucao;
typedef enum {manha=1,tarde,noite}turno;
typedef enum {natacao=1,hidroginastica,danca,kungfu,violao,futebol,volei}atividade;

typedef struct
{
  int matricula, idade;
  char nome[25];
  estado_civil estadocivil;
  grau_instrucao grauinstrucao;
  turno turn;
  atividade ativ;
  
}SOCIO;
typedef struct
{
  int socMan, socTar, socNoi, socNat, socHid, medSup, medCas;
  char idoFut[255], idoKun[255];

}STATS;

void cadastrarSocios(int *contador, SOCIO *socio);
void mostrarSocios(int *contador, SOCIO *socio);
void estatisticaSocios(int *contador, SOCIO *socio);

#endif