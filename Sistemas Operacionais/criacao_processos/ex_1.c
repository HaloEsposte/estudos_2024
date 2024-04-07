#include <stdio.h>
#include <stdlib.h> // para funções rande() e srand()
#include <time.h> // para função time()
#include <sys/wait.h>
#include <unistd.h>


//Exercicio 1 de Criacao de Processos primero bim.

#define MAX_SIZE 100 

int main()
{
    int n;
    printf("Digite a dimensão dos vetores (N): ");
    scanf("%d", &n);

    if(n <= 0 || n > MAX_SIZE)
    {
        printf("Dimensão invalida. Por favor, escolha um valor entre 1 e %d\n", MAX_SIZE);
        return 1;
    }


    int vetor1[n];
    int vetor2[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) // Prencher o vetor 1
    {
        vetor1[i] = rand() % 100; //gera valores aleatórios entre 0 e 99
    }

    for (int j = 0; j < n; j++) // Prencher o vetor 2
    {
        vetor2[j] = rand() % 100;
    }

    //Imprime o vetor 1
    printf("\nVetor 1: [");
    for (int i = 0; i < n; i++)
    {
        printf("%d", vetor1[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    } 
    printf("]\n");

    //Imprime o vetor 2
    printf("\nVetor 2: [");
    for (int j = 0; j < n; j++)
    {
        printf("%d", vetor2[j]);
        if (j < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n\n");

    pid_t newPid, me, parent, x;
    int status;

    newPid = fork();

    me = getpid();
    parent = getppid();


    if (newPid == 0) // processo filho
    {
        printf("Processo filho criado! newPid: %d\n", me);
        // Lógica do processo filho
        // Este código será executado pelo processo filho

    }
    else //processo pai
    {
        printf("Processo pai! PID do filho: %d\n", newPid);
        //Lógica do processo pai
        // Este código será executado apenas pelo processo pai

    }

    return 0;
}