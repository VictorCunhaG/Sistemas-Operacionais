/*
************************************************
 Sistemas Operacionais
 Prof. Eduardo Ferreira dos Santos
 Projeto 02 - Condição de Corrida
************************************************
 Nome:  João Pedro Rodrigues Alves
 TIA:   42083605
 Nome:  Pedro Henrique Carvalho
 TIA:   41910974
 Nome:  Victor Cunha Leite Goulart de Araujo
 TIA:   42031729
************************************************
*/

#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <semaphore.h>
 
// 64kB stack
#define FIBER_STACK 2048*64
sem_t trava_mutex;

struct c {
    int saldo;
};

typedef struct c conta;

conta from, to;
int valor;


// THe child will execute this funcition
int transferencia(void *arg){
    
    if(from.saldo >= valor){
        sem_wait(&trava_mutex);
        from.saldo -= valor;
        to.saldo += valor;
        sem_post(&trava_mutex);
    }
    else if(to.saldo >= valor){
        sem_wait(&trava_mutex);
        to.saldo -= valor;
        from.saldo += valor;
        sem_post(&trava_mutex);
    }
    printf("Transferencia concluida com sucesso!\n");
    printf("Saldo de c1: %d\n", from.saldo);
    printf("Saldo de c2: %d\n", to.saldo);
    return 0;
}

int main(){
  
    void* stack;
    int thread_pid[10];
    int i;
    int status;
    sem_init(&trava_mutex, 0, 1);

    // Allocate the stack
    stack = malloc ( FIBER_STACK );
    if ( stack == 0){

        perror("malloc: could no allocate stack");
        exit(1);
    }

    // Todas as contas come�am com saldo 100
    from.saldo = 980;
    to.saldo = 100;

    printf( " Transferindo 10 para a conta c2\n" );
    valor = 10;

    for (i=0; i<100; i++){
        // Call the clone system call to recreate the child thread
        thread_pid[i] = clone( &transferencia, (char*) stack + FIBER_STACK, SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0 );
  
    pid_t pid = waitpid(thread_pid[i], &status, 0);
    }
    
    // Free the stack
    free( stack );
    printf("Transferencias concluidas e memoria liberada.\n");

    return(0);
}
