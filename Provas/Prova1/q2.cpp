// questão 2

#include <iostream>
#include <string>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*(Questão 2 - 7 pontos)
Considere uma classe Pessoa que possui os atributos nome, idade e cpf.
Crie um método construtor para inicializar esses atributos.

Agora, crie duas classes: Instrutor e Aluno, ambas com a relação adequada com a classe Pessoa.
 A classe Instrutor possui um atributo adicional chamado salario, enquanto a classe Aluno possui um atributo adicional chamado mensalidade.
  Crie métodos construtores para inicializar esses atributos.

Em seguida, crie uma classe Aula que possui os atributos nome, horario, duracao e um objeto do tipo Instrutor.
Crie um método construtor para inicializar esses atributos.
Além disso, crie um método chamado adicionarAluno que recebe como parâmetro um objeto do tipo Aluno e o adiciona a uma lista de alunos da aula.

Finalmente, crie uma classe Academia que possui um vetor de objetos do tipo Aula. Crie um método chamado adicionarAula que recebe como parâmetro um objeto do tipo Aula
 e o adiciona ao vetor. Além disso, crie um método chamado listarAulas que imprime na tela as informações de todas as aulas na academia.
 Crie o método construtor e destrutor da classe Academia adequadamente.

Faça um programa que cria objetos do tipo Instrutor, Aluno, Aula e Academia. Em seguida, o programa adiciona alunos à aula e adiciona a aula à academia.
Finalmente, o programa lista as informações das aulas na academia.*/

class Pessoa
{
private:
    string nome;
    int idade;
    string cpf;

public:
    Pessoa(string n = "", int i = 0, string c = "")
    {
        nome = n;
        idade = i;
        cpf = c;

        cout << "Pessoa criada com sucesso" << endl;
    }
    ~Pessoa()
    {
        cout << "Pessoa destruida com sucesso" << endl;
    }

    // setters
    void setNome(string n)
    {
        nome = n;
    }
    void setIdade(int i)
    {
        idade = i;
    }
    void setCpf(string c)
    {
        cpf = c;
    }
    // getters
    string getNome()
    {
        return nome;
    }
    int getIdade()
    {
        return idade;
    }
    string getCpf()
    {
        return cpf;
    }
};

class Instrutor : public Pessoa
{ // herança
private:
    float salario;

public:
    Instrutor(float s = 0)
    {
        setSalario(s);
        cout << "Instrutor criado com sucesso" << endl;
    }
    ~Instrutor()
    {
        cout << "Instrutor destruido com sucesso" << endl;
    }
    // setters
    void setSalario(float s)
    {
        salario = s;
    }
    // getters
    float getSalario()
    {
        return salario;
    }
};

class Aluno : public Pessoa
{ // herança
private:
    float mensalidade;

public:
    Aluno(float m = 0)
    {
        setMensalidade(m);
        cout << "Aluno criado com sucesso" << endl;
    }
    ~Aluno()
    {
        cout << "Aluno destruido com sucesso" << endl;
    }
    // setters
    void setMensalidade(float m)
    {
        mensalidade = m;
    }
    // getters
    float getMensalidade()
    {
        return mensalidade;
    }
};

class Aula
{ // composição
private:
    string nome;
    string horario;
    int duracao;
    Instrutor *instrutor;
    Aluno *alunos;
    int qtdAlunos;

public:
    Aula(string n = "", string h = "", int d = 0, Instrutor *i = NULL, Aluno *a = NULL, int q = 0)
    {   

        
        setNome(n);
        setHorario(h);
        setDuracao(d);
        setInstrutor(i);
        setAlunos(a);
        setQtdAlunos(q);
        cout << "Aula criada com sucesso" << endl;
    }
    ~Aula()
    {
        cout << "Aula destruida com sucesso" << endl;
        for (int i = 0; i < getQtdAlunos(); i++)
        { // deleta os alunos instanciados
            delete &alunos[i];
        }
    }
    // setters
    void setNome(string n)
    {
        nome = n;
    }
    void setHorario(string h)
    {
        horario = h;
    }
    void setDuracao(int d)
    {
        duracao = d;
    }
    void setInstrutor(Instrutor *i)
    {
        instrutor = i;
    }
    void setAlunos(Aluno *a)
    {
        alunos = a;
    }
    void setQtdAlunos(int q)
    {
        qtdAlunos = q;
        alunos = (Aluno *)malloc(sizeof(Aluno) * q);
    }

    // getters

    string getNome()
    {
        return nome;
    }
    string getHorario()
    {
        return horario;
    }
    int getDuracao()
    {
        return duracao;
    }
    Instrutor *getInstrutor()
    {
        return instrutor;
    }
    Aluno *getAlunos()
    {
        return alunos;
    }
    int getQtdAlunos()
    {
        return qtdAlunos;
    }

    // metodos

    void adicionarAluno(Aluno *a)
    {
        alunos = (Aluno *)realloc(alunos, sizeof(Aluno) * (getQtdAlunos() + 1));
        alunos[getQtdAlunos() + 1] = *a;
    }
};

class Academia
{
private:
    Aula *aulas;
    int qtdAulas;

public:
    Academia(int q = 0)
    {
        setQtdAulas(q);
        // setAulas();
        cout << "Academia criada com sucesso" << endl;
    }
    ~Academia()
    {
        cout << "Academia destruida com sucesso" << endl;
        for (int i = 0; i < getQtdAulas(); i++)
        {
            delete &aulas[i];
        }
    }
    // getters
    int getQtdAulas()
    {
        return qtdAulas;
    }
    Aula *getAulas()
    {
        return aulas;
    }
    // setters

    void setQtdAulas(int q)
    {
        qtdAulas = q;
    }
    void setAulas(Aula *a, int p)
    {
        aulas[p] = *a;
    }

    void listarAulas()
    {
        for (int i = 0; i < getQtdAulas(); i++)
        {

            cout << "Nome: " << aulas[i].getNome() << endl;
            cout << "Horario: " << aulas[i].getHorario() << endl;
            cout << "Duracao: " << aulas[i].getDuracao() << endl;
            cout << "Instrutor: " << aulas[i].getInstrutor()->getNome() << endl;
            cout << "Alunos: " << endl;
            for (int j = 0; j < aulas[i].getQtdAlunos(); j++)
            {
                cout << aulas[i].getAlunos()[j].getNome() << endl;
            }
        }
    }
};

int main()
{

    Aluno *a1, *a2, *a3, *a4, *a5;

    a1 = new Aluno(100);
    a2 = new Aluno(200);
    a3 = new Aluno(300);
    a4 = new Aluno(400);
    a5 = new Aluno(500);

    Instrutor *i1, *i2;

    i1 = new Instrutor(1000);
    i2 = new Instrutor(2000);

    Aula *aula1, *aula2;

    aula1 = new Aula("Aula 1", "10:00", 60, i1, a1, 1);
    aula2 = new Aula("Aula 2", "11:00", 60, i2, a2, 1);

    aula1->adicionarAluno(a3);
    aula2->adicionarAluno(a4);
    aula2->adicionarAluno(a5);

    Academia *academia;

    academia = new Academia(2);
    academia->setAulas(aula1, 0);
    academia->setAulas(aula2, 1);
    cout << "Listando aulas" << endl;
    academia->listarAulas();
}
