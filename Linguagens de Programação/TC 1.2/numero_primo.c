#include <stdio.h>

int main() {
    int n;
    int acumulador; // Variável para determinar se o número é primo

    printf("Digite um número inteiro ou 0 para sair: ");
    scanf("%d", &n);

    while (n != 0) {
        acumulador = 1; // Inicializa o acumulador como verdadeiro (primo)

        if (n <= 1) 
        {
            printf("Não existe número primo menor do que 2. Tente novamente.\n");
        }

        else 
        {
            // Divide o número até não poder mais
            for (int i = 2; i <= n / 2; i++) 
            {
                if (n % i == 0)
                {
                    acumulador = 0; // O número não é primo
                    break;
                }
            }
            if (acumulador) 
            {
                printf("O número %d é primo\n", n);
            } 
            else 
            {
                printf("O número %d não é primo\n", n);
            }
        }

        printf("Digite um número inteiro ou 0 para sair: ");
        scanf("%d", &n); // Atualiza o valor de n para a próxima iteração
    }

    printf("Programa finalizado.\n");

    return 0;
}
