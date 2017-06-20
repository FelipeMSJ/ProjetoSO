#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <semaphore.h>
#include <pthread.h>

#define N_CLIENTE 19

int sem =  1;//balcao_cliente
int tam_fila = 0;
int balcao =0;

int down() {
	sem = sem - 1;
	return sem;
}

int up(){
	sem = sem + 1;
	return sem;
}

void * atendente (void* argument){
	while(1){
		if(tam_fila==0){
			down();
			printf("Atendendente atendeu o cliente. \n");
			up();
		}
		return 0;
	}
}

void * cliente(void* argument){
	int cliente = * (int *) argument;
	sleep(cliente%3);

	if(balcao == 0){
		

		printf("\nCliente %d entrou na fila do caixa. \n", cliente);
		tam_fila++;
		down();
		printf("Cliente %d chegou ao balcão. \n", cliente);
		up();
		printf("Cliente %d deixou o balcão. \n\n", cliente);
		tam_fila = tam_fila - 1;
		
		if(tam_fila == 0){
			printf("Atendente olhando o WhatsApp. \n\n");
		}
	}

	else
		printf("Cliente não entra na fila. \n");

}

int main(){

	//Vetor de threads indicando a fila do caixa
	pthread_t t_atendente;
	pthread_t t_cliente[N_CLIENTE];

	int i;//Contador auxíliar
	int id[N_CLIENTE];//Vetor que identifica os clientes

	//Criação das threads dos clientes
	for(i = 0; i <= N_CLIENTE; i++){
		id[i] = i;

		pthread_create(&t_cliente[i], NULL, cliente, (void*) &id[i]);

	}

	//Criação da thread da atendente
	pthread_create(&t_atendente, NULL, atendente, NULL);

	//Chamada das thread dos clientes
	for(i =0; i < N_CLIENTE; i++){
		pthread_join(t_cliente[i],NULL);
	}

	return 0;
}
