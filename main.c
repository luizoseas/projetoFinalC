#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    int vida = 6,
        AUX = 0,
        *ptrC = NULL,
        modo = 0,
        TamL = 6,
        TamC = 5,
        TamPalavra,
        NumAle,
        Comparacao = 0,
        acaba = 0,
        posicaoCorreta[5] = {0,0,0,0,0,0},
        Existe = 0,
        tamanhoDicionario = obterQuantidadePalavrasDicionario();

    char tabuleiro[6][TamC],
         tabuleiroVer[6][TamC],
         **Palavras,PalavraUsuario[6],
         PalavraSorteada[6];


    //Criar vetor1 para matriz
    Palavras = (int **) malloc(tamanhoDicionario*sizeof(int *));

    //Verificar se foi possivel alocar na memoria
    if(Palavras == NULL){
        printf("Erro: Memoria Insuficiente!\n");
        system("pause");
        exit(1);
    }

    //Criar vetores dentro do vetor1 Matriz.
    for(int i =0;i<tamanhoDicionario;i++){
        Palavras[i] = (char *) malloc((5+1)*sizeof(char));
        if(Palavras[i] == NULL){
            printf("Erro: Memoria Insuficiente!\n");
            system("pause");
            exit(1);
        }
    }

    //Pega todos as palavras do arquivo dicionario
    obterDicionario(tamanhoDicionario,Palavras);

    //Sortear uma palavra
    srand(time(NULL));
    NumAle = rand () %tamanhoDicionario;
    strcpy(PalavraSorteada, Palavras[NumAle]);
    for(int C = 0; C <= 5; C++){
        PalavraSorteada[C] = tolower(PalavraSorteada[C]);
    }
    //printf("%s", PalavraSorteada);
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
            tabuleiroVer[linha][coluna] = 'x';
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
        system("cls");

        //transforma a string que o usuario da em minusculo
        for(int C = 0; C <= 5; C++){
            PalavraUsuario[C] = tolower(PalavraUsuario[C]);
        }

        //escreve o tabuleiro
        printf("--------TABULEIRO--------\n");
        printf("-------------------------\n");
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
        printf("-------------------------\n");
        printf("\n");
        printf("----------DICA-----------\n");

        printf("A == letra na posicao correta\nC == letra na posicao errada\nE == letra incorreta\n");
        printf("-------------------------\n");
        Comparacao = 0;
        Existe = 0;
        //compara as duas strings para ver se são iguais
        for(int tamanho = 0;tamanho < 5;tamanho++){

            //verificar se a letra existe na palavra
            for(int tamanho2 = 0;tamanho2 < 5;tamanho2++){
                if(PalavraUsuario[tamanho] == PalavraSorteada[tamanho2] && tamanho != tamanho2){
                    Existe = 1;
                }
            }
            if(PalavraUsuario[tamanho] != PalavraSorteada[tamanho]){
                Comparacao = 1;
            }
            if(Existe){
                posicaoCorreta[tamanho] = 2;
                Existe = 0;
            }
            if(PalavraUsuario[tamanho] == PalavraSorteada[tamanho]){
                posicaoCorreta[tamanho] = 1;
            }
        }

        //escrever o tabuleiro Dica
        for(int linha = 0; linha < TamL; linha++){
            for(int coluna = 0; coluna < TamC; coluna++){
                if(linha == AUX){
                    if(posicaoCorreta[coluna] == 1){
                        tabuleiroVer[linha][coluna] = 'A';
                    }else if(posicaoCorreta[coluna] == 2){
                        tabuleiroVer[linha][coluna] = 'C';
                    }else{
                        tabuleiroVer[linha][coluna] = 'E';
                    }
                }
                if(tabuleiroVer[linha][coluna] == 'x'){
                    tabuleiroVer[linha][coluna] = ' ';
                }
            }
        }
        for(int linha = 0; linha < 5; linha++){
            posicaoCorreta[linha] = 0;
        }
        for(int linha = 0; linha < TamL; linha++){
            for(int coluna = 0; coluna < TamC; coluna++){
                printf("[ %c ]", tabuleiroVer[linha][coluna]);
            }
            printf("\n");
        }
        printf("-------------------------\n");

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

void VerificaChute (int comp, char Palavra[], int *vida, int *acaba){
    //escreve a mensagem dizendo que voce ganhou
    if(comp == 0){
        system("cls");
        printf("\nVOCE GANHOU!\n");
        printf("A Palavra era %s\n", Palavra);
        *acaba = 1;
    } else {
        *vida = *vida - 1;
    }

    //escreve a mensagem dizendo que perdeu
    if (*vida == 0){
        system("cls");
        printf("\nVOCE PERDEU!\n");
        printf("A Palavra era %s\n", Palavra);
    }
}
