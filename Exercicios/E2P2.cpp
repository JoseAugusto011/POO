/*(Questão 2)
Faça em C++ um programa para controle de um estoque de veiculos de uma
locadora, utilizando as classes descritas a segiuir, com seus respectivos
atributos e métodos.
- Veiculo: classe abstrata com atributos ano de fabricação (int), valor (float);
além dos 'gets' e 'sets' para os atributos, definir dois métodos protegidos e
virtuais: um (print_info) para exibir as informações do veículo na saída padrão
(cout) e outro (ipva_calculado) sem implementação, para retornar o valor do IPVA.
- Carro: classe que estende Veiculo e acrescenta os atributos motor (float) e
  quantidade de portas (int); além dos 'gets' e 'sets' para os atributos,
  sobreescrever o método print_info com as informações específicas do carro e
  implementar o método ipva_calculado usando a formula:
  ((idade do veículo) * (motor/10)) + (valor/1000)
- Moto: classe que estende Veiculo e acrescenta os atributos cilindradas (float)
  e aro (int); além dos 'gets' e 'sets' para os atributos, sobreescrever o método
  print_info com as informações específicas da moto e implementar o método
  ipva_calculado usando a formula:
  ((idade do veículo) * (cilindradas/100)) + (valor/1100)
- Caminhao: classe que estende Veiculo e acrescenta os atributos eixos (float)
  e carga (float); além dos 'gets' e 'sets' para os atributos, sobreescrever
  o método print_info com as informações específicas do caminhao e implementar
  o método ipva_calculado usando a formula:
  ((idade do veículo) * (eixos/2)) + (carga/1000) + (valor/900)

a) Cadastre uma instância de cada tipo de veículo.
b) Invoque o método print_info() de cada uma das instâncias. Explique o que foi
   feito para a implementação adequada deste método - como foi a herançae e
   posterior sobrescrita do método.
c) Insira todos os veiculos em um array de ponteiros para veículo e use esse
   array para calcular a média dos valores de IPVA dos veículos.
d) Descreva nos comentários o conceito de herança, e explique também o que é uma
   classe abstrata e qual sua relação com métodos virtuais em C++.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Veiculo
{

private:
    int ano;
    float valor;

protected:

   void Info()
    {

        cout << "Ano: " << ano << endl;
        cout << "Valor: " << valor << endl;
    }

public:
    Veiculo(int a = 0, float v = 0.0)
    {

        ano = a;
        valor = v;

        cout << "Veiculo criado" << endl;
    }
    ~Veiculo()
    {

        cout << "Veiculo destruido" << endl;
    }

    // setters

    void setAno(int a)
    {

        ano = a;
    }
    void setValor(float v)
    {

        valor = v;
    }

    // getters

    int getAno()
    {

        return ano;
    }
    float getValor()
    {

        return valor;
    }

    virtual float ipvaCalculado() = 0;


    virtual void printInfo()
    {
        Info();
    }
};

class Carro : public Veiculo
{

private:
    float motor;
    int portas;

public:
    Carro(int a = 0, float v = 0, float m = 0, int p = 0) : Veiculo(a, v)
    {

        motor = m;
        portas = p;

        cout << "Carro criado" << endl;
    }

    float getMotor()
    {

        return motor;
    }
    int getPortas()
    {

        return portas;
    }

    void setMotor(float m)
    {

        motor = m;
    }
    void setPortas(int p)
    {

        portas = p;
    }

    virtual void printInfo()
    {

        Veiculo::printInfo(); // chama o metodo printInfo da classe Veiculo
        cout << "Carro" << endl;
        cout << "Motor: " << motor << endl;
        cout << "Portas: " << portas << endl;
    }

    float ipvaCalculado()
    {

        return ((getAno()) * (getMotor() / 10)) + (getValor() / 1000);
    }
};

class Moto : public Veiculo
{

private:
    float cilindradas;
    int aro;

public:
    Moto(int a = 0, float v = 0, float c = 0, int ar = 0) : Veiculo(a, v)
    {

        cilindradas = c;
        aro = ar;

        cout << "Moto criada" << endl;
    }

    float getCilindradas()
    {

        return cilindradas;
    }
    int getAro()
    {

        return aro;
    }

    void setCilindradas(float c)
    {

        cilindradas = c;
    }
    void setAro(int ar)
    {

        aro = ar;
    }

    virtual void printInfo()
    {

        Veiculo::printInfo(); // chama o metodo printInfo da classe Veiculo
        cout << "Moto" << endl;
        cout << "Cilindradas: " << cilindradas << endl;
        cout << "Aro: " << aro << endl;
    }

    float ipvaCalculado()
    {

        return ((getAno()) * (getCilindradas() / 100)) + (getValor() / 1100);
    }
};

class Caminhao : public Veiculo
{

private:
    float eixos;
    float carga;

public:
    Caminhao(int a = 0, float v = 0, float e = 0, float c = 0) : Veiculo(a, v)
    {

        eixos = e;
        carga = c;

        cout << "Caminhao criado" << endl;
    }

    float getEixos()
    {

        return eixos;
    }
    float getCarga()
    {

        return carga;
    }
    void setEixos(float e)
    {

        eixos = e;
    }
    void setCarga(float c)
    {

        carga = c;
    }

    virtual void printInfo()
    {

        Veiculo::printInfo(); // chama o metodo printInfo da classe Veiculo
        cout << "Caminhao" << endl;
        cout << "Eixos: " << eixos << endl;
        cout << "Carga: " << carga << endl;
    }
    float ipvaCalculado()
    {

        return ((getAno()) * (getEixos() / 2)) + (getCarga() / 1000) + (getValor() / 900);
    }
};

#define TAM 3

int main()
{

    Carro *c1;
    Moto *m1;
    Caminhao *ca1;

    // Array de ponteiros para veiculos
    Veiculo *v[TAM];
    v[0] = new Carro(2010, 10000, 1.0, 4);
    v[1] = new Moto(2015, 5000, 100.0, 10.0);
    v[2] = new Caminhao(2018, 20000, 2, 1000);

    for (int i = 0; i < TAM; i++)
    {

        v[i]->printInfo();
        cout << "IPVA: " << v[i]->ipvaCalculado() << endl;
    }

    return 0;
}