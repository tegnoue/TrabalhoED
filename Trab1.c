/******************************************************************************
 Estrutura de dados - 2025/01 -  Professora: Eliza Helena
Alunos: Guilherme Ferreira Brandão   231030691
        Guilherme Nascimento Tegnoue 231011909

    Nós Declaramos que somos os autores deste trabalho e que o código não foi copiado
    de outra pessoa nem repassado para alguém. Estamos cientes de que poderemos sofrer
    penalizações na avaliação em caso de detecção de plágio.    

  Historia de usuário
  Jorginho tem uma barbearia e ele precisa ter um controle da fila de clientes.
  Quer ter noção de quem é o primeiro e ultimo cliente
  qual posição de cada cliente, e quantos clientes tem na fila. 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
typedef struct filano FilaNo;
typedef struct pessoa Pessoa;

  struct pessoa{
      char nome[100];
      int id;
  };

  struct fila{
      FilaNo* prim;
      FilaNo* ult;
  };

  struct filano{
      Pessoa  cliente;
      FilaNo* prox;

  };
  
    Fila* criaFila(void){
      Fila* f = (Fila*)malloc(sizeof(Fila));
      f->prim = f-> ult = NULL;
      return f;
    };

    void inserir(Fila* f, Pessoa cliente){
        FilaNo* novo = (FilaNo*)malloc(sizeof(FilaNo));
        novo->cliente = cliente;
        novo->prox = NULL;
          if (f->prim != NULL){

              f->ult->prox = novo;

          } else {

              f->prim = novo;

          }
          
          f->ult = novo;  

    };
















int main(void){


  return 0;
}