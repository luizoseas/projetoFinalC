#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char PalavraUsuario[6], PalavraSorteada[6] = "CACAU";
    int vida = 6, AUX = 0, *ptrL = NULL,*ptrC = NULL, modo = 0, TamL = 6, TamC = 5;
    char tabuleiro[6][5];

    //cria a tabela de modos e verifica se esta dentro de 1 a 3
    do {
        printf("----MODOS----\n");
        printf("FACIL -> 1\n");
        printf("MEDIO -> 2\n");
        printf("DIFICIL -> 3\n");
        printf("\nDigite o modo: ");
        scanf("%d", &modo);
        system("cls");
    } while (modo < 1 || modo > 3);

    //faz todo o tabuleiro receber x, para fazer a substituição depois
    for(int linha = 0; linha < TamL; linha++){
        for(int coluna = 0; coluna < TamC; coluna++){
            tabuleiro[linha][coluna] = 'x';
        }
    }

    printf("---TERMO---\n");

    do{
        printf("VIDAS: %d\n",vida);
        //verifica se a palavra digitada tem 5 letras
        do{
            printf("Digite a palavra: ");
            scanf("%s", PalavraUsuario);
        } while (strlen(PalavraUsuario) < 5 || strlen(PalavraUsuario) > 5);

        //transforma a string que o usuario da em maiusculo
        for(int C = 0; C <= 5; C++){
            PalavraUsuario[C] = toupper(PalavraUsuario[C]);
        }

        //escreve o tabuleiro
        for(int linha = 0; linha < TamL; linha++){
            for(int coluna = 0; coluna < TamC; coluna++){
                if(linha == AUX){
                    tabuleiro[linha][coluna] = PalavraUsuario[coluna];
                }
                if(tabuleiro[linha][coluna] == 'x'){
                    tabuleiro[linha][coluna] = ' ';
                }
            }
        }

        //verifica se a pessoa acertou ou errou o chute
        for(int linha = 0; linha < TamL; linha++){
            for(int coluna = 0; coluna < TamC; coluna++){
                printf("[ %c ]", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }

        if(strcmp(PalavraUsuario,PalavraSorteada) == 0){
            system("cls");
            printf("\nACERTOU!\n");
            printf("A Palavra era %s\n", PalavraSorteada);
            break;
        } else {
            vida--;
        }
        AUX++;
    } while (vida > 0);

    return 0;
}
