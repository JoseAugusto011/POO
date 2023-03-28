#include <iostream>

using namespace std;

class cor {
    int r;
    int g;
    int b;
public:
    cor(int rr = 0, int gg = 0, int bb = 0) {
        r = rr;
        g = gg;
        b = bb;
    }
    int get_r() {
        return r;
    }
    int get_g() {
        return g;
    }
    int get_b() {
        return b;
    }
};

class ponto {
    int x;
    int y;
    cor c;
public:
    ponto(cor cc, int xx = 0, int yy = 0) { 
        x = xx;
        y = yy;
        c = cc;
    }
    ponto() {
        cor c1(0,0,0);
        x = 0;
        y = 0;
        c = c1;
    }
    
    void set_x(int xx) {
        x = xx;
    }
    
    void set_y(int yy) {
        y = yy;
    }
    
    int get_x() {
        return x;
    }
    
    int get_y() {
        return y;
    }
    
    cor get_cor() {
        return c;
    }
};

class canvas {
    int qtd_pontos;
    ponto* pontos;
public:
    canvas(int q) {
        qtd_pontos = q;
        pontos = new ponto[q];
        cout << "Canvas criado: " << q << endl;
    }
    void print_pontos() {
        for (int i = 0; i < qtd_pontos; i++) {
            cout << i << ": ";
            cout << pontos[i].get_x() << ", ";
            cout << pontos[i].get_y() << endl;
            cout << "Cor: ";
            cout << pontos[i].get_cor().get_r();
            cout << ", ";
            cout << pontos[i].get_cor().get_g();
            cout << ", ";
            cout << pontos[i].get_cor().get_b();
            cout << endl;
        }
    }
    
    void add_ponto(ponto p, int pos) {
        pontos[pos] = p;
    }
};

int main() {
    cout << "Canvas start" << endl; 
    canvas c(10);
    cor c1(10, 20, 30);
    cor c2(0, 100, 200);
    cor c3(255, 255, 255);
    cor c4(57, 23, 56);
    
    ponto p1(c1, 10,20);
    ponto p2(c2, 30,40);
    ponto p3(c3, 50,60);
    ponto p4(c4);
    
    c.add_ponto(p1, 0);
    c.add_ponto(p2, 1);
    c.add_ponto(p3, 2);
    c.add_ponto(p4, 3);
    
    c.print_pontos();

    cout << "Canvas end" << endl; 
}