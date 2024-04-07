%INCLUDE "io.inc"

SECTION .text
global CMAIN

CMAIN:
    ; Carregando o valor de n a partir da seção .data
    MOV EAX, [n]

    ; Inicializando o contador de números ímpares impressos e o número atual
    MOV EBX, 0
    MOV ECX, 1

verificacao_impares:
    ; Verificando se já imprimimos todos os números ímpares desejados
    CMP EBX, EAX
    JE end_program  ; Se EBX == EAX, todos os números ímpares foram impressos

    ; Imprimindo a vírgula entre os números, exceto antes do primeiro número
    CMP EBX, 0
    JZ imprimir_numero_impar
    PRINT_STRING ", "

imprimir_numero_impar:
    ; Imprimindo o número ímpar atual
    PRINT_UDEC 2, ECX

    ; Incrementando o contador de números ímpares impressos
    INC EBX

    ; Indo para o próximo número ímpar
    ADD ECX, 2
    JMP verificacao_impares

end_program:
    ; Imprimindo uma nova linha após a lista de números ímpares
    PRINT_CHAR 10

    ; Finalizando o programa
    RET

SECTION .data
n DD 20  ; Número de números ímpares a serem impressos
