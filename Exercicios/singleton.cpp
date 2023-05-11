#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;




class kdb{
    char last_char;
    int buffer_size;

    static kdb* instance;

    kdb(char lc = ' ', int bs = 0){
        last_char = lc;
        buffer_size = bs;
        cout << "Kdb alocado" << endl;
    }

public :

    static kdb* getInstance(){
        if(instance == nullptr){
            instance = new kdb();
        }
        return instance;
    }

    // Se deixar metódos como static será preciso inicializar os metodos estáticas 
    // E se não forem usados, será um desperdício de memória

    // para inicializar metodos estáticos é preciso fazer isso:
    // kdb::setLastChar() = ' ';

    void setLastChar(char lc){
        last_char = lc;
    }
    void setBufferSize(int bs){
        buffer_size = bs;
    }
    char getLastChar(){
        return last_char;
    }
    int getBufferSize(){
        return buffer_size;
    }
    void imprime(){
        cout << "Last char: " << last_char << endl;
        cout << "Buffer size: " << buffer_size << endl;
    }
};

kdb* kdb::instance = nullptr;

int main(){
    
    // Se criar novas instâncias, elas serão iguais, pois só retornara o ponteiro para a instância já criada

        kdb* kdb1 = kdb::getInstance();
        kdb* kdb2 = kdb::getInstance();
    
        kdb1->setLastChar('a');
        kdb1->setBufferSize(10);
    
        kdb1->imprime();
        kdb2->imprime();
    
        kdb2->setLastChar('b');
        kdb2->setBufferSize(20);
    
        kdb1->imprime();
        kdb2->imprime(); // Valor será o mesmo, pois é a mesma instância
    
        return 0;
}