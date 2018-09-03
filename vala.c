#include <stdio.h>
#include <stdlib.h>

//Criando a estrutura de Lista
typedef struct list{
  int num;
  struct list *next;
}list;

list *queue, *end;

//Criando estrutura para adicionar elementos
//precisei de ajuda dos amigos pois tive dificuldade em criar as estruturas
//para adicionar e retirar (pedir ajuda à Erico.)

void incluir(int num){
  list *new, *aux;
  //Adicionando um item à lista,alocando memoria para o mesmo no tamanho da lista
  new = (list *)malloc(1 * sizeof(list));
  new->num = num;
  new->next = NULL;
  if(!queue){
    //Se a fila for inexistente,no caso,nula...esse item será o primeiro da fila, será o NOVO
    //e ainda sim ele vai ser o primeiro E o ultimo
    queue = new;
    end = queue;
    return;
  }
  else{
    //Caso o número já exista na lista, Retornar um erro falando que o número já existe na fila
    //assumindo que nenhum identificador pode se repetir
    aux = end;
    if(aux != NULL){
      if(aux->num == num){
      printf("Erro, O número Já existe!");
      return;
    }
  }
  aux->next = new;
  end = aux->next;
  return;
}
}
//Criando a estrutura de Retirar itens da Lista.

void excluir(int num)
{
  list *last, *aux;
  last = queue;
  aux = NULL;
  //Enquanto ultimo não for vazio e ultimo não for o próprio número
  //o ponteiro auxiliar apontará para o ultimo e o ultimo para o proximo
  while((last != NULL ) && (last->num != num)){
      aux = last;
      last = last->next;
  }
  //Se o ultimo ponteiro for NULO, retornará um erro dizendo que o número não existe
  if(last == NULL){
      printf("Esse número não existe \n");
      return;
  }else{
      if(aux == NULL){
        //Se o ponteiro auxiliar for nulo, então ele apontará pro próximo
        //item da lista e a fila vai apontar pro auxiliar, liberando a memoria do ultimo    
        aux = last->next;
        queue = aux;
        free(last);       
        return;
      }else{
        aux->next = last->next;         
        free(last);
        return;             
      }   
  }      
}

//Criando um verificador pra checar se o ultimo é nulo e pular pro próximo ou não
//meu código estava dando TLE por isso precisei de ajuda para criar essa Struct

void checker(list *last){
  //apenas um IF fazendo o código buscar o ultimo ponteiro e verificar se ele é nulo
  //apontando esse ultimo ponteiro para o número se ele não for nulo
  //caso o ponteiro que aponte pro próximo seja diferente de Nulo, ele apontará para o próximo

  if(last != NULL){
    printf("%d ", last->num);
    if(last->next != NULL)
    checker(last->next);
  }
  return;
}
//Criando uma estrutura pra verificar se o número que irá entrar é muito grande e remove-lo automaticamente
void ingresso(int b){
  int num;
  if (b < 2){
    scanf("%i",&num);
    if(num <= 100000){
      incluir(num);
      return;
    }
    printf("Erro,Valor muito alto, Repita a operação \n");
    exit(2);
  }
  else{
    scanf("%i", &num);
    if(num <= 100000){
      incluir(num);
      b--;
      ingresso(b);
      return;
    }
    printf("Erro,Valor muito Alto \n");
    exit(2);
  }
}

//Criando um terceiro verificador para checar é muito alto e remove-lo automaticamente
void remover(int b){
  int num;
  if(b < 2){
    scanf("%i", &num);
    if(num <= 100000){
      excluir(num);
      return;
    }
    printf("Erro,Valor muito alto, Repita a operação. \n");
    exit(2);
  }else{
    scanf("%i", &num);
    if(num <= 100000){
      excluir(num);
      b--;
      remover(b);
      return;
    }
    printf("Erro,Valor muito alto Repita a operação. \n");
    exit(2);
  }
}

int main(){
  int i,num,b,c;
  
  scanf("%i",&b);

  if(b <= 5000){
    ingresso(b);
  }
  else{
    printf("Erro,Valor muito alto! \n");
    return 2;
  }

  scanf("%i",&c);
  if(c <= b){
    remover(c);
  }
  else{
    printf("Erro,Valor muito alto \n");
    return 2;
  }
  
  b -= c;
  
  list *last;
  
  last = queue;
  
  checker(last);
  
  printf("\n");
  
  free(queue);
  
  return 0;
}
