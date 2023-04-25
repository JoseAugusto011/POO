// Questão 1

/*
    Autor : José Augusto da Silva Barbosa[
    Matricula: 20210094705
    curso: CDIA
    Disciplina: POO
    Prova 1
    ]

*/

#include <iostream>
#include <string>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define TAM 2 // tamanho do vetor de contas exigido no enunciado

/*(Questão 1 - 7 pontos)
Considere uma classe Conta que possui os atributos numero, saldo e titular. Crie um método construtor para inicializar esses atributos. Além disso, crie dois métodos:
depositar e sacar, que recebem como parâmetro um valor e atualizam o saldo da conta de acordo.

Agora, crie duas classes: ContaCorrente e ContaPoupanca, utilizando adequadamente a relação com a classe Conta. A classe ContaCorrente possui um atributo adicional chamado limite,
enquanto a classe ContaPoupanca possui um atributo adicional chamado rendimento.
Crie métodos construtores para inicializar esses atributos.
Além disso, sobrescreva o método sacar na classe ContaCorrente acrescentando uma mensagem.

Finalmente, crie uma classe Banco que possui um vetor de ponteiros para objetos do tipo Conta. Crie um método chamado adicionarConta que recebe como parâmetro um objeto do
tipo Conta e o adiciona ao vetor. Além disso, crie um método chamado listarContas que imprime na tela as informações de todas as contas no banco.
Crie o método construtor e destrutor da classe Banco adequadamente.

Faça um programa que cria um objeto do tipo Banco e adiciona a ele duas contas: uma do tipo ContaCorrente e outra do tipo ContaPoupanca. Em seguida,
o programa lista as informações das contas e realiza algumas operações de saque e depósito (pelo menos uma de cada em cada conta).
Finalmente, o programa lista novamente as informações das contas para mostrar o resultado das operações.
Discorra sobre as mensagens exibidas (qual método foi chamado em qual situação).
*/

class Conta
{
private:
    int numero;
    float saldo;
    string titular;

public:
    Conta(int n = 0, float s = 0, string t = "")
    {
        numero = n;
        saldo = s;
        titular = t;

        cout << "Conta criada com sucesso" << endl;
    }
    ~Conta()
    {
        cout << "Conta destruida com sucesso" << endl;
    }

    // setters
    void setNumero(int n)
    {
        numero = n;
    }
    void setSaldo(float s)
    {
        saldo = s;
    }
    void setTitular(string t)
    {
        titular = t;
    }
    // getters
    int getNumero()
    {
        return numero;
    }
    float getSaldo()
    {
        return saldo;
    }
    string getTitular()
    {
        return titular;
    }
    // metodos extras
    void depositar(float valor)
    {
        setSaldo(getSaldo() + valor);
    }
    void sacar(float valor)
    { // Sobreescrita
        if (valor <= getSaldo())
        {
            setSaldo(getSaldo() - valor); // Verifica se valores sao validos
            cout << "Saque realizado com sucesso" << endl;
            cout << "Seu novo saldo e: " << getSaldo() << endl;
        }
        else
        {
            cout << "Saldo insuficiente" << endl;
            cout << "Seu saldo atual e: " << getSaldo() << endl;
        }
    }
    void mostrarDados()
    {
        cout << "Numero: " << getNumero() << endl;
        cout << "Saldo: " << getSaldo() << endl;
        cout << "Titular: " << getTitular() << endl;
    }
};

class ContaCorrente : public Conta
{ // herança
private:
    float limite;

public:
    ContaCorrente(int n = 0, float s = 0, string t = "", float l = 0) : Conta(n, s, t)
    {
        setLimite(l);
        cout << "Conta Corrente criada com sucesso" << endl;
    }
    ~ContaCorrente()
    {
        cout << "Conta Corrente destruida com sucesso" << endl;
    }
    // setters
    void setLimite(float l)
    {
        limite = l;
    }
    // getters
    float getLimite()
    {
        return limite;
    }
    // metodos extras
    void sacar(float valor)
    { // limite = vai ser valor extra que pode ser sacado
        if (valor <= getSaldo() + getLimite())
        {
            setSaldo(getSaldo() - valor);

            cout << "Saque realizado com sucesso" << endl;
        }
        else
        {
            setSaldo(getSaldo() - valor);
            cout << "Cuidado! Voce esta usando o limite" << endl;
            cout << "Seu saldo atual e: " << getSaldo() << endl;
        }
    }
    void mostrarDados()
    {
        cout << "Numero: " << getNumero() << endl;
        cout << "Saldo: " << getSaldo() << endl;
        cout << "Titular: " << getTitular() << endl;
        cout << "Limite: " << getLimite() << endl;
    }
};

class ContaPoupanca : public Conta
{ // herança
private:
    float rendimento;

public:
    ContaPoupanca(int n = 0, float s = 0, string t = 0, float r = 0) : Conta(n, s, t)
    {
        rendimento = r;
        cout << "Conta Poupanca criada com sucesso" << endl;
    }
    ~ContaPoupanca()
    {
        cout << "Conta Poupanca destruida com sucesso" << endl;
    }
    // setters
    void setRendimento(float r)
    {
        rendimento = r;
        // alterar o saldo
        setSaldo(getSaldo() + (getSaldo() * rendimento)); // Atualiando o saldo com o rendimento
    }
    // getters
    float getRendimento()
    {
        return rendimento;
    }

    // metodos extras
    void mostrarDados()
    {
        cout << "Numero: " << getNumero() << endl;
        cout << "Saldo: " << getSaldo() << endl;
        cout << "Titular: " << getTitular() << endl;
        cout << "Rendimento: " << getRendimento() << endl;
    }
};

class Banco
{ // composicao
private:
    Conta *contas[TAM];

public:
    Banco()
    {

        cout << "Banco criado com sucesso" << endl;
        cout << "Qtd de contas: " << sizeof(contas) / sizeof(contas[0]) << endl;
    }
    ~Banco()
    {
        for (int i = 0; i < TAM; i++)
        { // Exclui todas as contas individualmente

            delete contas[i];
        }
        cout << "Banco destruido com sucesso" << endl;
    }
    void adicionarConta(Conta *c)
    {
        for (int i = 0; i < TAM; i++)
        { // Adiciona a conta no primeiro espaço vazio, para não sobrescrever
            if (contas[i] == NULL)
            {
                contas[i] = c;
                break;
            }
        }
    }
    void listarContas()
    {
        for (int i = 0; i < TAM; i++)
        { // Lista todas as contas
            if (contas[i] != NULL)
            {
                contas[i]->mostrarDados(); // Polimorfismo, chama o metodo mostrarDados da classe ContaCorrente ou ContaPoupanca
            }
        }
    }
};

int main()
{
    Banco banco;
    ContaCorrente *cc;
    ContaPoupanca *cp;

    cc = new ContaCorrente(1, 1000, "Joao", 1000);
    cp = new ContaPoupanca(2, 1000, "Maria", 0.05);

    banco.adicionarConta(cc); // Permite fazer essa operação pois ContaCorrente é uma Conta e conta corrente tem mais parametro que conta
    // porém não é possivel fazer o contrario, pois faltaraão parametros
    banco.adicionarConta(cp);
    cout << "Informacoes das contas: \n";
    banco.listarContas();
    cout << endl;

    cc->sacar(2000); // limite = 1000, portanto é possivel sacar valor solicitado
    cp->sacar(2000); // limite = 0, portanto nao é possivel sacar valor solicitado, além disso, o saldo é insuficiente
    cp->setRendimento(0.15);
    cout << endl;
    cout << "Atualizacao das contas: \n";
    banco.listarContas();
    /*
    Conta corrente terá saldo negativo pois está usando o limite
    Conta poupança terá saldo positivo pois está usando o rendimento
    valor será atualizado de acordo com o rendimento
    que será o rendimento anterior + o rendimento atual + o saldo
    */

    cout << endl;

    return 0;
}
