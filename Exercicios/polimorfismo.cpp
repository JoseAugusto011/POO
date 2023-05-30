#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class coisa {

    int  x;
    float y;

public:

    coisa(int x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }

    coisa (int x = 0 , float y = 0,string nome = "coisa") {
        this->x = x;
        this->y = y;
        cout<<nome<<endl;
 
    }

    coisa (int x, float y, int z) {
        this->x = x;
        this->y = y;
        cout<<z<<endl;
    }

};


class Ponto {
    int x;
    int y;

public:

    Ponto(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void soma(int x, int y) {
        this->x += x;
        this->y += y;
    }

    void soma(Ponto& p) {
        this->x += p.x;
        this->y += p.y;
    }

    void soma(Ponto* p) {
        this->x += p->x;
        this->y += p->y;
    }

    /*void soma(Ponto p) {
        this->x += p.x;
        this->y += p.y;
    }*/

      //assinaura da funcao friend dentro da classe 
    friend void Mod_coord(Ponto& p, int x, int y);

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    void imprime() {
        cout << "(" << x << "," << y << ")" << endl;
    }

  
};





void  Mod_coord(Ponto& p, int x, int y) {
    p.x = x;
    p.y = y;
}


int main(){
    
        //coisa c1(1,2.0); is ambiguous
        coisa c2(1,2.0,"coisa");
        coisa c3(1,2.0,3);
        // coisa c4; is ambiguous


        Ponto p1(1,2);
        Ponto p2(3);
        Ponto p3;

        p1.soma(1,1);
        p1.imprime();

        p3.soma(p1);

        p3.imprime();

        Mod_coord(p3, 10, 10); // não pode chamar a paertir de um objeto, pois não é um método da classe

    
        return 0;
}