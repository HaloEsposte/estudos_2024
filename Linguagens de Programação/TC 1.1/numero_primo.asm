%INCLUDE "io.inc"

SECTION .text
global CMAIN
CMAIN:
    ; Definindo o número para verificar se é primo
    MOV EBX, [num]  ; Carrega o número a partir da seção .data

    ; Verificando se o número é primo
    CMP EBX, 1   ; Verifica se o número é 1
    JLE numero_nao_primo  ; Se for 1 ou menos, não é primo

    MOV ECX, 2   ; Começa a verificação a partir de 2
    JMP proximo_divisor  ; Salta para verificar o próximo divisor

proximo_divisor:
    CMP ECX, EBX  ; Verifica se ECX atingiu o valor de EBX
    JGE numero_primo  ; Se ECX for maior que EBX, então EBX é primo
    XOR EDX, EDX  ; Limpa EDX para armazenar o resultado da divisão
    MOV EAX, EBX  ; Move o valor de EBX para EAX para a divisão
    DIV ECX       ; Divide EAX por ECX (resultado em EAX, resto em EDX)
    CMP EDX, 0    ; Verifica se não há resto (n é divisível por ECX)
    JE numero_nao_primo  ; Se houver resto, n não é primo
    INC ECX       ; Incrementa ECX para verificar o próximo divisor
    JMP proximo_divisor  ; Salta para verificar o próximo divisor

numero_primo:
    PRINT_STRING "O numero e primo."
    JMP end_program

numero_nao_primo:
    PRINT_STRING "O numero nao e primo."
    JMP end_program

end_program:
    RET

SECTION .data
num DD 97  ; Número para verificar se é primo (substitua por qualquer número desejado)
