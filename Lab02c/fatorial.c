/* 
fontes:
    - https://www.geeksforgeeks.org/fork-system-call/
    - https://www.geeksforgeeks.org/factorial-calculation-using-fork-c-linux/
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc , char *argv[]){
	pid_t pid; 
	if (argc != 2) {
		printf("Falta ou excesso de argumentos\n");
		exit(0);
	}
	
	if ( atoi ( argv[1] ) < 0){
		printf("Nao se calcula fatorial de numero negativo. %d", atoi(argv[1]));
		exit(0);
	}
	pid=fork();
	
	if ( pid<0 ){
		printf("Falha ao criar o filho\n");
		exit(0);
	} else if ( pid==0 ){
		int k = 2;
        int i,j,n;
		n = atoi(argv[1]);
		int arr[n];
		arr[0] = 1;
		for (i=1 ; i<n; i++) {
			arr[i] = arr[i-1]*k;
			k++;
		}
        printf("fat(%d) = %d\n", n,arr[n-1]);
		exit(0);
	} else{
		wait(NULL);
	}
}
