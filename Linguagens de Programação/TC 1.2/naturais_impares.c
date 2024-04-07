#include <stdio.h>

int main()
{
    int n;
    printf("\nDigite um número inteiro POSITIVO: ");
    scanf("%d", &n);

    while (n < 1)
    {
        printf("O número precisa ser positivo e diferente de ZERO\n\n");
        printf("Digite um número inteiro POSITIVO: ");
        scanf("%d", &n);
        
        if(n >= 1)
        {
            break;
        }
    }

    int impar = 1;
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", impar);

        if (i < n - 1 )
        {
            printf(", ");
        }

        impar += 2;
        
    }
    printf("\n\n");
    return 0;
}