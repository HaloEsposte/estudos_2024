#include <stdio.h> 
#include <string.h>

int main() {
    char entrada[20]; // vetor para salvar a entrada do Úsuario
    long long int x;
    long long int fatorial;
    long long a;

    while (1) 
    {
        printf("\nDigite um número inteiro ou 'sair' para terminar: ");
        scanf("%s", entrada); //salva a entrada como str

        if (strcmp(entrada, "sair") == 0) //strcmp compara as str 'entrada' e 'sair' se forem iguais
        {
            printf("\nPrograma Finalizado. \n\n");
            break;
        }

        if (sscanf(entrada, "%lld", &x) == 1)  // sscanf compara pega a str 'entrada' e diz qual formato será interpretado '%d' e salva na variável 'x'
        {
            if (x < 0) 
            {
                printf("\nNão é possível calcular o fatorial de números negativos. Por favor, tente novamente.\n");
            } 

            else if (x > 15)
            {
                printf("O fatorial de %lld estrapola os limites, para testes precisos tente um número entre 0 e 15\n", x);
                
            }
            else 
            {
                printf("\nNúmero digitado: %lld\n", x);
                fatorial = 1;
                a = x;

                // Calcula o fatorial de x
                while (a > 1) 
                {
                    fatorial *= a;
                    a--;
                }

                printf("O fatorial de %lld é: %lld\n", x, fatorial);
            }
        }
    }

    return 0;
}
