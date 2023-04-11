#include <iostream>
#include <string>


// Tema carbon owl

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*

    //Referencias : 
    
    https://pt.stackoverflow.com/questions/25619/composi%C3%A7%C3%A3o-e-agrega%C3%A7%C3%A3o-quais-as-diferen%C3%A7as-e-como-usar    
    https://www.inf.unioeste.br/~adair/ED/Apostilas/Introducao%20POO%20C++.pdf
    http://www.linhadecodigo.com.br/artigo/943/uml-unified-modeling-language-generalizacao-agregacao-composicao-e-dependencia.aspx


    //Herança =  tipo de 
    //composição = todo/parte
        * Agregação 
        * composição 
        * Associação
    

    

    capitulo  -  Livro   (parte de)
    professor - grupo de pesquisa (parte de)
    orientação - orientação de doutorado (tipo de)


    

*/


class Tesoura{
    float tamanhoLamina;
    bool afiada;
public :
    Tesoura(float tamanhoLamina, bool afiada){
        setTamanhoLamina(tamanhoLamina);
        setAfiada(afiada);
        cout<<"Construtor da classe Tesoura"<<endl;
    }
    ~Tesoura(){
        cout<<"Destrutor da classe Tesoura"<<endl;
    }

    //gets e sets

    float getTamanhoLamina(){
        return tamanhoLamina;
    }
    void setTamanhoLamina(float tamanhoLamina){
        this->tamanhoLamina = tamanhoLamina;
    }
    bool getAfiada(){
        return afiada;
    }    
    void setAfiada(bool afiada){
        this->afiada = afiada;
    }

    //metodos
    void afiar(){
        cout<<"Afiando a tesoura..."<<endl;
        setAfiada(true);
    }
    void cortar(){
        cout<<"Cortando..."<<endl;
    }
    void guardar(){
        cout<<"Guardando a tesoura..."<<endl;
    }
};

class ChaveFenda{
    float tamanhoFenda;

public :
    ChaveFenda(float tamanhoFenda){
        setTamanhoFenda(tamanhoFenda);
        cout<<"Construtor da classe ChaveFenda"<<endl;
    }
    ~ChaveFenda(){
        cout<<"Destrutor da classe ChaveFenda"<<endl;
    }

    //gets e sets

    float getTamanhoFenda(){
        return tamanhoFenda;
    }
    void setTamanhoFenda(float tamanhoFenda){
        this->tamanhoFenda = tamanhoFenda;
    }

    //metodos
    void apertarParafuso(){
        cout<<"Apertando parafuso..."<<endl;
    }
    void guardar(){
        cout<<"Guardando a chave de fenda..."<<endl;
    }
};

class Canivete : public Tesoura, public ChaveFenda{
    int anoFabricacao;
public:
    Canivete(float tamanhoLamina, bool afiada, float tamanhoFenda, int anoFabricacao): Tesoura(tamanhoLamina, afiada), ChaveFenda(tamanhoFenda){
        setAnoFabricacao(anoFabricacao);
        cout<<"Construtor da classe Canivete"<<endl;
    }
    ~Canivete(){
        cout<<"Destrutor da classe Canivete"<<endl;
    }

    //gets e sets

    int getAnoFabricacao(){
        return anoFabricacao;
    }
    void setAnoFabricacao(int anoFabricacao){
        this->anoFabricacao = anoFabricacao;
    }

    //metodos

    void abrirLata(){
        cout<<"Barulho de lata abrindo... "<<endl;
    }
    void guardar(){
        cout<<"Guardando o canivete..."<<endl;
    }

}; // Herança múltipla


int main(){
    Canivete canivete(10, true, 5, 2019);
    canivete.afiar();
    canivete.cortar();
    canivete.apertarParafuso();
    canivete.abrirLata();

    canivete.Tesoura::guardar();
    canivete.ChaveFenda::guardar();
    canivete.guardar();

    

    return 0;
}
