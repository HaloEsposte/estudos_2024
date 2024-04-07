/* add as bibliotecas

    leia (escreva uma frase)
    leia ( digite uma palavra para a busca ) 
    ENQUANTO palavra sair não for digitada mantem o programa funcionando
        PARA toda a frase procurar a palavra digitada
            percorrer a frase, se achar a primeira letra da palavra salva e 
            confere a segunda, se for igual salva novamente até acabr a frase

            tem que contar quantas vezes a palavra apareceu 
*/


#include <stdio.h>
#include <string.h> // necessário para ler strings
#include <ctype.h>  // necessário para o tolower()

int main() 
{   
    char frase[100];
    char palavra[100];
    int conta_palavra = 0;
    

    // Ler a frase
    printf("\nATENÇÃO CUIDADO COM  OS ACENTOS ELES INFUENCIAM NA PESQUISA DAS PALAVRAS");
    printf("\nDigite uma frase: ");
    fgets(frase, sizeof(frase), stdin);// o fgets evita overflow, mas gera uma quebra de linha que precisa ser removida
    // Remove o caractere de nova linha, se presente
    frase[strcspn(frase, "\n")] = '\0';

    // Ler a palavra
    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    // Remove o caractere de nova linha, se presente
    palavra[strcspn(palavra, "\n")] = '\0';

    // variável para armazenar o tamanho da palavra
    // 'strlen' mostra o tamanho da string
    int tamanho_da_palavra = strlen(palavra);

    for(int i = 0; frase[i] != '\0'; i++)
    {
        int encontrou = 1; //variável para encontrar a letra inicial da palavra
        for(int j = 0; j < tamanho_da_palavra; j++)
        {
            // se algum caractere nãom corresponder, parade verificar
            if(tolower(frase[i+j]) != tolower(palavra[j]))
            {
                encontrou = 0;
                break;
            }
        }
        
        // Incrementa o contador quando a palavra for encontrada
        if (encontrou)
        {
            conta_palavra++;
            i += tamanho_da_palavra - 1;// pula os carcteres da palavra encontrada
        }

    }


    printf("\nFrase digitada: %s\n", frase);
    printf("Palavra digitada: %s\n", palavra);
    printf("Numero de vezes que a palavra %s aparece é igual a %d\n\n", palavra, conta_palavra);


    return 0;
}



