#include<iostream>

using std::cout;
using std::endl;
using std::cin;


class motor{
    float tamanho;
    int serial;

public :
    motor(float t = 0, int s = 0){
        set_tamanho(t);
        set_serial(s);
        cout << "motor criado!" << endl;
    }
    float get_tamanho(){
        return tamanho;
    }
    void set_tamanho(float t){
        if (t < 0)
            tamanho = 0;
        else
            tamanho = t;
    }
    int get_serial(){
        return serial;
    }
    void set_serial(int s){
        if (s < 0)
            serial = 0;
        else
            serial = s;
    }
    ~motor(){
        cout << "motor finalizado!" << endl;
    }
    
};


class freio{
    int abs;
    float torque;
public :

    freio(int a = 0, float t = 0){
        set_abs(a);
        set_torque(t);
        cout << "freio criado!" << endl;
    }
    int get_abs(){
        return abs;
    }
    void set_abs(int a){
        if (a < 0)
            abs = 0;
        else
            abs = a;
    }
    float get_torque(){
        return torque;
    }
    void set_torque(float t){
        if (t < 0)
            torque = 0;
        else
            torque = t;
    }
    ~freio(){
        cout << "freio finalizado!" << endl;
    }

};

class pneu{
    int aro;
    float pressao;

public :
    pneu(int a = 0, float p = 0){
        set_aro(a);
        set_pressao(p);
        cout << "pneu criado!" << endl;
    }
    int get_aro(){
        return aro;
    }
    void set_aro(int a){
        if (a < 0)
            aro = 0;
        else
            aro = a;
       
    }
    float get_pressao(){
        return pressao;
    }
    void set_pressao(float p){
        if (p < 0)
            pressao = 0;
        else
            pressao = p;
    }
    ~pneu(){
        cout << "pneu finalizado!" << endl;
    }
};


class carro {

    motor *m;
    freio *f;
    pneu *p;
    int numPortas;
    int anoFabricacao;
    int numPneus;

public :

   carro(float t = 0, int s = 0, int a = 0, float t1 = 0, int a1 = 0, float p1 = 0, int nP = 0, int aF = 0, int nPn = 0){
       
        m = new motor(t, s);            
        f = new freio(a, t1);

        
       set_numPortas(nP);
       set_anoFabricacao(aF);
       p = new pneu[nPn];
       for (int i = 0; i < numPneus; i++){
                p[i] . set_aro(1);
                p[i] . set_pressao(1.0);
            }

        cout << "carro criado!" << endl;
   }

      
    ~carro(){
        cout<<endl;
        delete[] p;
        delete f;
        delete m;
        cout << "carro finalizado!" << endl;

    }


   


   void set_numPortas(int nP){
       if (nP < 0)
           numPortas = 0;
       else
           numPortas = nP;
   }

    void set_anoFabricacao(int aF){
         if (aF < 0)
              anoFabricacao = 0;
         else
              anoFabricacao = aF;
    }

    void set_numPneus(int nPn){
        if (nPn < 0){
            numPneus = 0;
            p == NULL;
        }
        else{

            
            p = new pneu[numPneus];

            for (int i = 0; i < numPneus; i++){
                p[i] . set_aro(1);
                p[i] . set_pressao(1.0);
            }

        }
            


    }

    int get_numPortas(){
        return numPortas;
    }

    int get_anoFabricacao(){
        return anoFabricacao;
    }

    int get_numPneus(){
        return numPneus;
    }

    // fazer gets e sets para devolver motor freio e numPneus
    //Ou um print info pra cada classe que e chamado no print info de carro





};


int  main(){

    carro c1 = carro(1.0, 1, 1, 1.0, 1, 1.0, 1, 1, 4);
    carro *c2;

    c2 = new carro(1.0, 1, 1, 1.0, 1, 1.0, 1, 1, 1);
    cout <<endl;
    cout<<"deletando carro 2"<<endl;


/*Não funciona ´pq tem que fazer osd gets e sets ou função print info

//mostrando informaçõesdo carro 2

    cout<<"informações do carro 2: "<<endl;

    for (int i = 0; i < get_qtd_matriculas(); i++){
        cout << "aro: " << c2->p[i].get_aro() << endl;
        cout << "pressao: " << c2->p[i].get_pressao() << endl;
    }
    cout << "tamanho: " << c2->m->get_tamanho() << endl;
    cout << "serial: " << c2->m->get_serial() << endl;
    cout << "abs: " << c2->f->get_abs() << endl;
    cout << "torque: " << c2->f->get_torque() << endl;
    cout << "numPortas: " << c2->numPortas << endl;
    cout << "anoFabricacao: " << c2->anoFabricacao << endl;
    cout << "numPneus: " << c2->numPneus << endl;


*/

                                                                              
    
    
    
    
    delete c2;
    
    return 0;

    
}
