#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char PalavraUsuario[6], PalavraSorteada[6] = "CACAU";
    int vida = 6, AUX = 0, *ptr, modo = 0;
    char tabuleiro[6][5];

    printf("---TERMO---\n\n");

    for(int linha = 0; linha < 6; linha++){
        for(int coluna = 0; coluna < 5; coluna++){
            tabuleiro[linha][coluna] = 'x';
        }
    }

    do{
        printf("VIDAS: %d\n",vida);
        printf("Digite a palavra: ");
        scanf("%s", PalavraUsuario);

        //transforma a string que o usuario da em maiusculo
        for(int C = 0; C <= 5; C++){
            PalavraUsuario[C] = toupper(PalavraUsuario[C]);
        }

        //escreve o tabuleiro
        for(int linha = 0; linha < 6; linha++){
            for(int coluna = 0; coluna < 5; coluna++){
                if(linha == AUX){
                    tabuleiro[linha][coluna] = PalavraUsuario[coluna];
                }
                if(tabuleiro[linha][coluna] == 'x'){
                    tabuleiro[linha][coluna] = ' ';
                }

            }
        }

        for(int linha = 0; linha < 6; linha++){
            for(int coluna = 0; coluna < 5; coluna++){
                printf("[ %c ]", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }

        if(strcmp(PalavraUsuario,PalavraSorteada) == 0){
            printf("\nACERTOU\n");
            break;
        } else {
            vida--;
        }
        AUX++;
    } while (vida > 0);

    return 0;
}
