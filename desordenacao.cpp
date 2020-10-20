#include <cstdlib>


class Seq_aleatoria{
public:
	Seq_aleatoria(unsigned chave);
	char *seq_ordenada;
	char *seq_desordenada;
private:
	int tam_seq;
	unsigned chave;
    void ajusta_array(char *p, int pos, int *tam_atual);
	void desordena();
};

Seq_aleatoria::Seq_aleatoria(unsigned chave){
    this->chave = chave;
    this->tam_seq = 256;
    this->seq_ordenada = new char[this->tam_seq];
    for(int i = 0; i < this->tam_seq; i++)
        *(this->seq_ordenada + i) = char(i);
    this->desordena();
}

void Seq_aleatoria::ajusta_array(char *p, int pos, int *tam_atual){
    int i;
    for(i = pos; i < *tam_atual; i++)
        *(p + i) = *(p + i + 1);
    --(*tam_atual);
}

void Seq_aleatoria::desordena(){
	int i, tam_atual = this->tam_seq;
	int tam_original = this->tam_seq, v_aleatorio;
	char *cop_seq_ord;
	cop_seq_ord = new char[tam_original];
	for(i = 0; i < tam_original; i++)
        *(cop_seq_ord + i) = *(this->seq_ordenada + i);
	this->seq_desordenada = new char[tam_original];
	srand(this->chave);
	for(i = 0; i < tam_original; i++){
        v_aleatorio = rand()%tam_atual;
        *(this->seq_desordenada + i) = *(cop_seq_ord + v_aleatorio);
        this->ajusta_array(cop_seq_ord, v_aleatorio, &tam_atual);
	}
}
