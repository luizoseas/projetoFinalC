#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void VerificaChute (int comp, char Palavra[], int *vida, int *acaba){
    //escreve a mensagem dizendo que voce ganhou
    if(comp == 0){
            system("cls");
            printf("\nVOCE GANHOU!\n");
            printf("A Palavra era %s\n", Palavra);
            *acaba = 1;
        } else {
            *vida--;
        }

        //escreve a mensagem dizendo que perdeu
        if (*vida == 0){
            system("cls");
            printf("\nVOCE PERDEU!\n");
            printf("A Palavra era %s\n", Palavra);
        }
}

int main(){
    char PalavraUsuario[6], PalavraSorteada[6], Palavras[10][6] = {"CACAU","OSTRA","ERROS","ENVIA","EDUCA","DUCHA","DRENA","DIZER","COPIA","AMIGO"};
    int vida = 6, AUX = 0, *ptrC = NULL, modo = 0, TamL = 6, TamC = 5, TamPalavra, NumAle, Comparacao, acaba = 0;
    char tabuleiro[6][TamC];

    srand(time(NULL));
    NumAle = rand () %10;

    strcpy(PalavraSorteada, Palavras[NumAle]);

    printf("%s", PalavraSorteada);

    ptrC =  &TamL;
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

    //utiliza o ponteiro para definir o tamanho do tabuleiro juntamente com a quantidade de vida
    if(modo == 2){
        *ptrC = 4;
        vida = 4;
    } else if (modo == 3){
        *ptrC = 2;
        vida = 2;
    }


    //faz todo o tabuleiro receber x, para fazer a substituição depois
    for(int linha = 0; linha < TamL; linha++){
        for(int coluna = 0; coluna < TamC; coluna++){
            tabuleiro[linha][coluna] = 'x';
        }
    }

    printf("---TERMO---\n");

    do{
        //verifica se a palavra digitada tem 5 letras
        do{
            printf("Digite a palavra: ");
            scanf("%s", PalavraUsuario);
            TamPalavra = strlen(PalavraUsuario);
        } while (TamPalavra < 5 || TamPalavra > 5);

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

        //escreve na tela o tabuleiro com o chute do usuario
        for(int linha = 0; linha < TamL; linha++){
            for(int coluna = 0; coluna < TamC; coluna++){
                printf("[ %c ]", tabuleiro[linha][coluna]);
            }
            printf("\n");
        }

        //compara as duas strings para ver se são iguais
        Comparacao = strcmp(PalavraUsuario,PalavraSorteada);

        //funcao responsavel por determinar se o jogador ganhou ou perdeu
        VerificaChute(Comparacao, PalavraSorteada, &vida, &acaba);

        //da o fim para o programa
        if(acaba == 1){
            break;
        }
        AUX++;
    } while (vida > 0);

    return 0;
}
