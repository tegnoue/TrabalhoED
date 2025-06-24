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
#include <string.h>

//Essa parte do código é pra garantir que o sleep (delay) funcione
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void delay(unsigned int tempo) {
#ifdef _WIN32
    Sleep(tempo * 1000); 
#else
    sleep(tempo);
#endif
}

void limparTela(){
        #ifdef _WIN32
    system("cls");
    #else
    system("clear");
  #endif
    }

typedef struct fila Fila;
typedef struct filano FilaNo;
typedef struct pessoa Pessoa;

  struct pessoa{
      char nome[100];
      int id;
      int servico;
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

    Pessoa remover(Fila* f){
        FilaNo* temp = f->prim;
        Pessoa clienteSelecionado = temp->cliente;
        f->prim = f->prim->prox;
        if (f->prim == NULL) {
            f->ult = NULL;
        }
        free(temp);
        return clienteSelecionado;
    };

    
    void buscar(Fila* f, char clienteProcurado[100]){
      int contador = 1;
      for (FilaNo* p = f->prim; p != NULL; p = p->prox)
      {
        if(strcmp(p->cliente.nome , clienteProcurado)==0){
          printf("A posição de %s na fila eh: %d\n", clienteProcurado, contador);
          return;
        }
        contador++;
      }      
      printf("Não foi encontrado o cliente em questão.");
    }

    void imprimeFila(Fila* f){
      int contador = 1;
      for (FilaNo* p = f->prim; p != NULL; p = p->prox)
      {
        printf("%d - %s - %d\n", contador, p->cliente.nome, p->cliente.servico);
        contador++;
      }
    }

  void opcaoUm(Fila* f){
    char nomeCliente[100];
    int servico;
    Pessoa novoCliente;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nomeCliente);
    strcpy(novoCliente.nome, nomeCliente);
    printf("Agora escolha o serviço:\n1 - Barba\n2 - Barba e Cabelo\n3 - Cabelo\n");
    scanf("%d", &servico);
    novoCliente.servico = servico;
    inserir(f, novoCliente);
  }

    void opcaoDois(Fila* f){
      limparTela();
      if (f->prim == NULL) {
          printf("Fila vazia!\n");
      } else{
      Pessoa proximoCliente = remover(f);
      printf("É a vez de %s", proximoCliente.nome);
      }

    }

    void opcaoTres(Fila* f){
      limparTela();
      imprimeFila(f);
    }

    void opcaoQuatro(Fila* f){
      char nomeCliente[100];
      limparTela();
      printf("Digite o nome do cliente:");
      scanf(" %[^\n]", nomeCliente);
      buscar(f, nomeCliente);
    }
    void enterToBack(){
      printf("\n[ENTER para volta]\n\n");
      while (getchar() != '\n');
        getchar();

    }
    
void menuInicial(Fila* f){
    int escolhaMenu;
    int rodando = 1;
    while (rodando) {
        limparTela();
        printf("**********************MENU**********************\n\n");
        printf("1 - Acrescentar cliente na fila\n");
        printf("2 - Retirar o proximo cliente\n");
        printf("3 - Exibir fila completa\n");
        printf("4 - Procurar cliente na fila\n");
        printf("5 - Fechar \n\n");
        printf("Digite a opcao: ");
        scanf("%d", &escolhaMenu);

        switch (escolhaMenu)
        {
            case 1:
                opcaoUm(f);
                enterToBack();
                break;
            case 2:
                opcaoDois(f);
                enterToBack();
                break;
            case 3:
                opcaoTres(f);
                enterToBack();
                break;
            case 4:
                opcaoQuatro(f);
                enterToBack();
                break;
            case 5:
              rodando = 0; 
                break;

            default:
                limparTela();
                printf("Escolha uma opcao valida.\n\n");
                delay(2);
        }
    }
}

int main(void){
    Fila* fila = criaFila();
    menuInicial(fila);
    printf("Programa encerrado.\n");
    return 0;
}

