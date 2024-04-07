%INCLUDE "io.inc"

SECTION .text
global CMAIN

CMAIN:
    MOV EAX, [num]      ; Carrega o número cujo fatorial será calculado
    MOV EBX, 1          ; Inicializa o fatorial como 1
    MOV ECX, EAX        ; Copia o valor de EAX para ECX para ser usado como contador

calcular_fatorial:
    CMP ECX, 1          ; Verifica se o contador chegou a 1
    JLE end_calculation  ; Se chegou a 1, termina o cálculo
    IMUL EBX, ECX       ; Multiplica o fatorial atual pelo valor do contador (ECX)
    DEC ECX             ; Decrementa o contador
    JMP calcular_fatorial  ; Repete o processo

end_program:
    PRINT_UDEC 4, EBX   ; Imprime o fatorial calculado
    RET                 ; Retorna do programa

SECTION .data
num DD 6                 ; Número para o qual o fatorial será calculado
