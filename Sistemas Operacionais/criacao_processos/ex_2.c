#include <stdio.h>
#include <stdlib.h> // Para funções rand() e srand()
#include <time.h> // Para função time()
#include <unistd.h>
#include <sys/wait.h>


#define MAX_SIZE 100

int main()
{
    // Cria os dois vetores de tamanho N com valores aleatórios
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
    // Fim da criação de vetores 
    ////////////////////////////////////////////////////////////////

    //Variavéis para criação de processo
    pid_t newPid, me, parent;
    int status;
    newPid = fork();

    me = getpid();
    parent = getppid();
    
    if (newPid < 0)
    {
        perror("erro ao criar processo filho");
        return 1; 
    }

    else if (newPid == 0)
    {
        printf("Processo filho criado! Pid: %d\n", getpid());

        if ()
    }
    
}