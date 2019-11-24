/*

Este arquivo foi criado com a intenção de ler o conteúdo de um arquivo e
modificar os valores dos bytes, substituindo o n-ésimo valor de val_original[]
(3º parâmetro do construtor da classe) pelo n-ésimo valor de val_alterado[]
(4º parâmetro do construtor da classe). Ambos os arrays citados são obtidos
externamente a esse arquivo, de modo que é necessário criar tais arrays, de
acordo com a necessidade e passa-los como parâmetro para o construtor para o
funcionamento correto dos objetos da classe.

escrito por: Yuri Ventura
e-mail: yurisotc@gmail.com

*/

#include <cstdio>

class Mod_arquivo{
public:
    Mod_arquivo(FILE *arq_ini, char val_original[], char val_alterado[]);
    char *cont_arq_alt;
    long long tam_arquivo;
private:
    char *cont_arq_ori;
    //long long tam_arquivo;
    long long ret_tam_arq(FILE *arq);
    void le_arquivo(FILE *arq);
    void alt_arquivo(char val_original[], char val_alterado[]);
};

Mod_arquivo::Mod_arquivo(FILE *arq_ini, char val_original[], char val_alterado[]){
    long long i;
    this->tam_arquivo = ret_tam_arq(arq_ini);
    this->cont_arq_ori = new char[this->tam_arquivo];
    le_arquivo(arq_ini);
    this->cont_arq_alt = new char[this->tam_arquivo];
    alt_arquivo(val_original, val_alterado);
}


long long Mod_arquivo::ret_tam_arq(FILE *arq){
    long long tam = 0;
    if(arq == NULL)
        tam = -1;
    else
        do{
            fgetc(arq);
            ++tam;
        }while(!feof(arq));
    rewind(arq);
    return --tam;
}

void Mod_arquivo::le_arquivo(FILE *arq){
    fread(this->cont_arq_ori, 1, this->tam_arquivo, arq);
    *(this->cont_arq_ori + this->tam_arquivo) = '\0';
}

void Mod_arquivo::alt_arquivo(char val_original[], char val_alterado[]){
    char carac;
    long long i, j;
    for(i = 0; i < this->tam_arquivo; i++){
        j = 0;
        carac = *(this->cont_arq_ori + i);
        while(carac != val_original[j])
            ++j;
        *(this->cont_arq_alt + i) = val_alterado[j];
    }
    *(this->cont_arq_alt + i) = '\0';
}
