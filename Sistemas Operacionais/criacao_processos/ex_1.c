#include <stdio.h>
#include <stdlib.h> // Para funções rand() e srand()
#include <time.h> // Para função time()
#include <unistd.h>
#include <sys/wait.h>

#define MAX_SIZE 100 

int main() 
{
    int n;
    printf("Digite a dimensão dos vetores (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) 
    {
        printf("Dimensão inválida. Por favor, escolha um valor entre 1 e %d.\n", MAX_SIZE);
        return 1;
    }

    // Variáveis para a criação de vetores
    int vetor1[n];
    int vetor2[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) 
    {
        vetor1[i] = rand() % 100;
        vetor2[i] = rand() % 100;
    }

    printf("\nVetor 1: [");
    for (int i = 0; i < n; i++) 
    {
        printf("%d", vetor1[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");

    printf("\nVetor 2: [");
    for (int j = 0; j < n; j++) 
    {
        printf("%d", vetor2[j]);
        if (j < n - 1) printf(", ");
    }
    printf("]\n\n");

    // Variáveis para o processo
    pid_t newPid;
    int status;
    newPid = fork();

    if (newPid < 0) 
    {
        perror("Erro ao criar processo filho");
        return 1;
    } 
    else if (newPid == 0) 
    {
        printf("Processo filho criado! PID: %d\n", getpid());

        printf("Esperando processo filho executar a multiplicação...\n\n");
        sleep(5); //Faz com que fique visível a multplicação

        int resultado[n]; //para armazenar o resultsado da multiplicação

        //Multiplica os vetores e armazena em resultados
        for (int i = 0; i < n; i++) 
        {
            resultado[i] = vetor1[i] * vetor2[i];
        }

        //Percorre o vetor 'resultados' e imprime um por um 
        printf("Resultado da multiplicação: [");
        for (int i = 0; i < n; i++) 
        {
            printf("%d", resultado[i]);
            if (i < n-1) printf(", ");
        }
        printf("]\n");

        exit(0);
    } 
    else // newPid é diferente de zero
    {
        waitpid(newPid, &status, 0);
        printf("Processo filho com PID %d terminou.\n", newPid);
    }

    return 0;
}
