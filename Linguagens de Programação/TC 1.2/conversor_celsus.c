#include <stdio.h>
#include <string.h>

int main()
{
    char entrada[20];
    float f;
    float c;

    while(1)
    {
        printf("\nDigite a temperatura em Fahrenheit ou 'sair' para finalizar o programa: ");
        scanf("%s", entrada);

        if (strcmp(entrada, "sair") == 0)
        {
            printf("\nPrograma Finalizado. \n\n");
            break;
        }

        if (sscanf(entrada, "%f", &f) == 1)
        {
            c = ((f - 32)*5)/9;
            printf("\n\n%.2f graus em Fahrenheit equivale a %.2f graus Celsus\n\n", f,c);
        }
    }
}