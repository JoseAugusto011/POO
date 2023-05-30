#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class complexo {
    int real;
    int imaginario;

public : 

    complexo(int real = 0, int imaginario = 0) {
        this->real = real;
        this->imaginario = imaginario;
    }

    complexo soma(complexo& c) {
        complexo aux;
        aux.real = this->real + c.real;
        aux.imaginario = this->imaginario + c.imaginario;
        return aux;
    }

    void set_real(int real) {
        this->real = real;
    }

    void set_imaginario(int imaginario) {
        this->imaginario = imaginario;
    }

    int get_real() {
        return real;
    }

    int get_imaginario() {
        return imaginario;
    }

    void print() {
        cout << real << " + " << imaginario << "i" << endl;
    }

    complexo operator+(complexo& c) {
        complexo aux;
        aux.real = this->real + c.real;
        aux.imaginario = this->imaginario + c.imaginario;
        return aux;
    }
    

    //friend complexo operator+(complexo& c1, complexo& c2);
    
    friend void operator++(complexo& c);

    complexo operator++(int){ // operador de incremento versão pós fixada
        complexo aux = *this;
        this->real++;
        this->imaginario++;
        return aux;
    }



};

void operator++(complexo& c){ // operador de incremento versão pré fixada
    c.real++;
    c.imaginario++;
}

/*complexo operator+(complexo& c1, complexo& c2) {
    complexo aux;
    aux.real = c1.real + c2.real;
    aux.imaginario = c1.imaginario + c2.imaginario;
    return aux;

}*/


int main(){
    complexo c1(1,2);
    complexo c2(3,4);
    complexo c3;
    complexo c4;
    
    //complexo c5 = c3.operator+(c4);

    complexo c5 = c3 + c4;

    c4 = c1 + c2;
    c3 = c1.soma(c2);

    // complexo errorMultiplosintancia = c1 + c2 + c3 + c4 + c5;  Usar o operador + para somar mais de dois complexos, para isso deve implementar como atributo da classe complexo
    //Não usar friend para sobrecarregar operadores, usar métodos da classe

    ++c5;
    c5++;

    c3.print();
    c4.print();
    c5.print();
    
    return 0;
}