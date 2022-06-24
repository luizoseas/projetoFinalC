#include <stdio.h>
//ler o arquivo dicionario
void obterDicionario(int qntPalavras,char **dicionario){
    int coluna = 0;
    int linha = 0;
    FILE *arquivo = fopen("dicionario.txt","r");
    if(arquivo != NULL){
        char ch = getc(arquivo);
        while(linha < qntPalavras){
            if(ch == '\n'){
                linha++;
                coluna = 0;
            }else{
                dicionario[linha][coluna] = ch;
                coluna++;
            }
            ch = getc(arquivo);
        }

    }else{
        printf("Erro: O arquivo <dicionario.txt> não foi encontrado...");
        system("pause");
        exit(1);
    }
    fclose(arquivo);
}

//obtem a quantidade de palavras no arquivo
int obterQuantidadePalavrasDicionario(){
    int contador = 0;
    FILE *arquivo = fopen("dicionario.txt","r");
    if(arquivo != NULL){
        char ch = getc(arquivo);
        while(ch != EOF){
            if(ch == '\n'){
                contador++;
            }
            ch = getc(arquivo);
        }
    }else{
        printf("Erro: O arquivo <dicionario.txt> não foi encontrado...");
        system("pause");
        exit(1);
    }
    fclose(arquivo);
    return contador;
}
