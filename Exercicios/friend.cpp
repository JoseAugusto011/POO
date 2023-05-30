#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;



class produto {

    int quantidade;
    float preco;

public:

    produto(int quantidade = 0, float preco = 0) {
        this->quantidade = quantidade;
        this->preco = preco;
    }

    int get_quantidade() {
        return quantidade;
    }

    void set_quantidade(int quantidade) {
        this->quantidade = quantidade;
    }

    float get_preco() {
        return preco;
    }

    void set_preco(float preco) {
        this->preco = preco;
    }

    friend class estoque; // declaração de amizade
    //metodos de estoque podem acessar os atributos privados de produto

};


class estoque {

    int total;

public:

    int get_total() {
        return total;
    }
    void set_total(int total) {
        this->total = total;
    }

   void retira(produto &p){
         total -= p.get_quantidade();
   }

   
};



int main(){

    produto p1(10, 2.5);
    produto p2(5, 3.5);

    estoque e1;
    e1.set_total(100);

    e1.retira(p1);
    e1.retira(p2);

    cout << e1.get_total() << endl;

    return 0;
}