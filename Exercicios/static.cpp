#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

class Pessoa{
    private:
        static int totalIdade;
        static float totalAltura;

        float altura;
        int idade;
        static int qtdPessoas;
    public:
       
        Pessoa(float altura, int idade){

            setaltura(altura);
            setIdade(idade);
            totalIdade += idade;
            totalAltura += altura;

            qtdPessoas++;
            cout << "Construtor" << endl;

        }
        ~Pessoa(){

            qtdPessoas--;
            totalIdade -= idade;
            totalAltura -= altura;
            cout << "Destrutor" << endl;

        }

        void setaltura(float altura){
            this->altura = altura;
        }
        void setIdade(int idade){
            this->idade = idade;
        }
        
        void setQtdPessoas(int qtdPessoas){
            this->qtdPessoas = qtdPessoas;
        }
        float getAltura(){
            return altura;
        }
        int getIdade(){
            return idade;
        }
        
        int getQtdPessoas(){
            return qtdPessoas;
        }
        void imprime(){
            cout << "Altura: " << altura << endl;
            cout << "Idade: " << idade << endl;
            cout << "Quantidade de pessoas: " << qtdPessoas << endl;
        }

        static float mediaIdade(){
            if (qtdPessoas != 0)
                return totalIdade/qtdPessoas;
            else
                return 0;
        }
        static float mediaAltura(){
            if (qtdPessoas == 0)
                return 0;
            else
                return totalAltura/qtdPessoas;
        }
};


int Pessoa::totalIdade = 0;
int Pessoa::qtdPessoas = 0;
float Pessoa::totalAltura = 0;

int main(){
    Pessoa *p1, *p2, *p3;

    p1 = new Pessoa(1.70, 20);
    p2 = new Pessoa(1.80, 30);
    p3 = new Pessoa(1.90, 40);

    p1->imprime();
    p2->imprime();
    p3->imprime();

    cout << "Media de idade: " << Pessoa::mediaIdade() << endl;
    cout << "Media de altura: " << Pessoa::mediaAltura() << endl;

    delete p1;
    delete p2;
    delete p3;

    return 0;
}