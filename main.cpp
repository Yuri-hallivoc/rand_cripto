#include "desordenacao.cpp"
#include "mod_arquivo.cpp"
#include <iostream>
#include <locale>
#include <cstdio>
#include <cstring>
//#include <conio.h>

using namespace std;

//void pause(void);

void valida_string(char str[]);

int main(){
    int i;
    setlocale(LC_ALL, "portuguese");
    char opcao, origem[500], destino[500];
    FILE *arq_ini, *arq_fin;
    unsigned chave;
    cout << "O que você deseja fazer?" << endl << endl;
    cout << "a) criptografar um arquivo;" << endl;
    cout << "b) descriptografar um arquivo." << endl << endl;
    cin >> opcao;
    if(opcao == 'a'){
        cout << endl << endl << "----------------------------------------";
        cout << "------------------------------" << endl << endl;
        cout << "Digite o caminho para o arquivo a ser criptografado:" << endl << endl;
        setbuf(stdin, NULL);
        fgets(origem, 500, stdin);
        valida_string(origem);
        arq_ini = fopen(origem, "rb");
        cout << endl << endl;
        if(arq_ini == NULL){
            cout << "O arquivo não pode ser aberto." << endl << endl;
            //pause();
            exit(0);
        }
        cout << "Digite o caminho para o arquivo de destino:" << endl << endl;
        setbuf(stdin, NULL);
        fgets(destino, 500, stdin);
        valida_string(destino);
        arq_fin = fopen(destino, "wb");
        if(arq_fin == NULL){
            cout << "O arquivo não pode ser criado." << endl << endl;
            //pause();
            exit(0);
        }
        cout << "Digite a chave criptográfica:" << endl << endl;
        cin >> chave;
        Seq_aleatoria *Bytes = new Seq_aleatoria(chave);
        Mod_arquivo *Codificacao = new Mod_arquivo(arq_ini, Bytes->seq_ordenada, Bytes->seq_desordenada);
        for( i = 0; i < Codificacao->tam_arquivo; i++)
            fwrite((Codificacao->cont_arq_alt + i), 1, 1, arq_fin);
        fclose(arq_ini);
        fclose(arq_fin);
    }
    else{
        if(opcao != 'b'){
            cout << endl << endl << "Opção inválida!" << endl << endl;
            //pause();
            exit(0);
        }
        cout << endl << endl << "----------------------------------------";
        cout << "------------------------------" << endl << endl;
        cout << "Digite o caminho para o arquivo a ser descriptografado:" << endl << endl;
        setbuf(stdin, NULL);
        fgets(origem, 500, stdin);
        valida_string(origem);
        arq_ini = fopen(origem, "rb");
        cout << endl << endl;
        if(arq_ini == NULL){
            cout << "O arquivo não pode ser aberto." << endl << endl;
            //pause();
            exit(0);
        }
        cout << "Digite o caminho para o arquivo de destino:" << endl << endl;
        setbuf(stdin, NULL);
        fgets(destino, 500, stdin);
        valida_string(destino);
        arq_fin = fopen(destino, "wb");
        if(arq_fin == NULL){
            cout << "O arquivo não pode ser criado." << endl << endl;
            //pause();
            exit(0);
        }
        cout << "Digite a chave criptográfica:" << endl << endl;
        cin >> chave;

        Seq_aleatoria *Bytes = new Seq_aleatoria(chave);
        Mod_arquivo *Codificacao = new Mod_arquivo(arq_ini, Bytes->seq_desordenada, Bytes->seq_ordenada);
        for(int i = 0; i < Codificacao->tam_arquivo; i++)
            fwrite((Codificacao->cont_arq_alt + i), 1, 1, arq_fin);
        fclose(arq_ini);
        fclose(arq_fin);
    }
    return 0;
}

/*Após cada chamada de fgets() deve-se chamar a função a seguir
para eliminar a quebra de linha adicionada a string*/

void valida_string(char str[]){
    unsigned i;
    for(i = 0; i < strlen(str); i++)
        if(str[i] == '\n') str[i] = '\0';
}

/*void pause(void){
    cout << "pressione qualquer tecla para continuar...";
    getch();
}*/
