#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*(Questão 1)
Faça em C++ um programa para controle de atividades acadêmicas. O sistema 
armazenará informações utilizando as classes descritas a seguir, com seus
respectivos atributos privados.
- Pessoa: CPF (int), idade (int) e altura (float); contador de pessoas 
  (int, variável de classe)
- Professor (estendendo Pessoa): matrícula (int), ano de admissão (int),
  titulação (int)
- Aluno (estendendo Pessoa): matrícula (int), CRA (float)
- Turma: professor responsável (instância de Professor), array de alunos,
  código da disciplina (int) - esta classe deve ser um Singleton (deve
  poder ser instanciada apenas uma vez).

Faça o programa cadastrar duas turmas com um professor diferente em cada e
três alunos e diferentes disciplinas. Depois use os métodos criados e exiba:
a) Quantidade de pessoas cadastradas no sistema (usar método de classe)
b) Média das notas dos alunos de cada uma das turmas
c) Média da altura das pessoas cadastradas no sistema
d) Média de idade dos professores e média de idade dos alunos

Destaque nos comentários o uso dos mecanismos de herança e composição e quais
são os atributos e métodos dos membros e das classes. 
*/

class Pessoa {

private:
    
    int cpf;
    int idade;
    float altura;
    static int contador;
    static int totalIdade;
    static float totalAltura;

public: 

  Pessoa(int c, int i, float a) {
    cpf = c;
    idade = i;
    altura = a;
    totalAltura += a;
    totalIdade += i;
    contador++;

  }
  ~Pessoa() {

    contador--;
    totalAltura -= altura;
    totalIdade -= idade;

  }

  int getCpf() {
    return cpf;
  }
  int getIdade() {
    return idade;
  }
  float getAltura() {
    return altura;
  }

  static int getContador() {
    return contador;
  }

  void setCpf(int c) {
    cpf = c;
  }
  void setIdade(int i) {
    idade = i;
  }
  void setAltura(float a) {
    altura = a;
  }
  float MediaAltura (){

    return totalAltura / contador;
  }
  float MediaIdade (){

    return totalIdade / contador;
  }
  static int totalPessoas (){

    return contador;
  }

};

class Professor : public Pessoa {

private:
    
    int matricula;
    int anoAdmissao;
    int titulacao;

    static int contadorProfessor;
    static int totalIdadeProfessor;


public:

  Professor (int c = 0, int i = 0, float a = 0, int m = 0, int aa = 0, int t = 0) : Pessoa(c, i, a) {
    matricula = m;
    anoAdmissao = aa;
    titulacao = t;
    contadorProfessor++;
    totalIdadeProfessor += i;

  }

  ~Professor() {
  }

  int getMatricula() {
    return matricula;
  }
  int getAnoAdmissao() {
    return anoAdmissao;
  }
  int getTitulacao() {
    return titulacao;
  }

  void setMatricula(int m) {
    matricula = m;
  }
  void setAnoAdmissao(int aa) {
    anoAdmissao = aa;
  }
  void setTitulacao(int t) {
    titulacao = t;
  }

  static int getContadorProfessor() {
    return contadorProfessor;
  }
  float MediaIdadeProfessor (){

    return totalIdadeProfessor / contadorProfessor;
  }

};


class Aluno : public Pessoa {

private:
    int matricula;
    float cra;
    static int contadorAluno;
    static int SomaNotas;
public :  

  Aluno (int c = 0, int i = 0, float a = 0, int m = 0, float cr = 0) : Pessoa(c, i, a) {
    matricula = m;
    cra = cr;
    contadorAluno++;
    SomaNotas += cr;

  }
  ~Aluno() {
    SomaNotas -= cra;
    contadorAluno--;
  }

  int getMatricula() {
    return matricula;
  }
  float getCra() {
    return cra;
  }

  void setMatricula(int m) {
    matricula = m;
  }
  void setCra(float cr) {
    cra = cr;
  }

  float MediaNotas (){

    return SomaNotas / contadorAluno;
  }
  static int getContadorAluno() {
    return contadorAluno;
  }
};


class Turma {

private:
    Professor professor;
    Aluno *alunos;
    int codigoDisciplina;
    static Turma* instancia;

    Turma(Professor p, Aluno *a, int cd) {
      professor = p;
      alunos = a;
      codigoDisciplina = cd;
    }
  public:

    static Turma* getInstancia(Professor p, Aluno *a, int cd) {
      if (instancia == NULL) {
        instancia = new Turma(p, a, cd);
      }
      return instancia;
    }

    static Turma* getInstancia() {
      return instancia;
    }

    ~Turma() {
      delete instancia;
      delete[] alunos;
    }

    Professor getProfessor() {
      return professor;
    }
    Aluno* getAlunos() {
      return alunos;
    }
    int getCodigoDisciplina() {
      return codigoDisciplina;
    }

    void setProfessor(Professor p) {
      professor = p;
    }
    void setAlunos(Aluno *a) {
      alunos = a;
    }
    void setCodigoDisciplina(int cd) {
      codigoDisciplina = cd;
    }
    float MediaNotasTurma (){

      int soma = 0;

      for (int i = 0; i < sizeof(alunos); i++) {
        soma += alunos[i].getCra();
      }
      return soma / sizeof(alunos);
    }
};



int Aluno::contadorAluno = 0;
int Aluno::SomaNotas = 0;

int Pessoa::contador = 0;
int Pessoa::totalIdade = 0;
float Pessoa::totalAltura = 0;





int main(){

  Professor *p1;
  Professor *p2;

  

  Aluno *a1, *a2, *a3, *a4, *a5, *a6;
  
  Turma *t1, *t2;

  t1 = Turma::getInstancia();
  t2 = Turma::getInstancia();

  t1->setCodigoDisciplina(1);
  t2->setCodigoDisciplina(2);
  t2->setCodigoDisciplina(3);

  p1 = new Professor(1, 30, 1.70, 1, 2010, 1);
  p2 = new Professor(2, 40, 1.80, 2, 2015, 2);

  a1 = new Aluno(3, 20, 1.60, 1, 8.0);
  a2 = new Aluno(4, 21, 1.70, 2, 7.0);
  a3 = new Aluno(5, 22, 1.80, 3, 6.0);
  a4 = new Aluno(6, 23, 1.90, 4, 5.0);
  a5 = new Aluno(7, 24, 2.00, 5, 4.0);
  a6 = new Aluno(8, 25, 2.10, 6, 3.0);

  t1->setProfessor(*p1);
  t2->setProfessor(*p2);

  t1->setAlunos(a1);
  t1->setAlunos(a2);
  t1->setAlunos(a3);

  t2->setAlunos(a4);
  t2->setAlunos(a5);
  t2->setAlunos(a6);

  cout << "Media de idade da turma 1: " << t1->getProfessor().MediaIdadeProfessor() << endl;
  cout << "Media de idade da turma 2: " << t2->getProfessor().MediaIdadeProfessor() << endl;
  cout << "Media de notas da turma 1: " << t1->MediaNotasTurma() << endl;
  cout << "Media de notas da turma 2: " << t2->MediaNotasTurma() << endl;
  cout << "Media de notas da turma 1: " << t1->getAlunos()->MediaNotas() << endl;
  cout << "Media de notas da turma 2: " << t2->getAlunos()->MediaNotas() << endl;
  cout << "Total de professores: " << Professor::getContadorProfessor() << endl;
  cout << "Total de alunos: " << Aluno::getContadorAluno()<< endl;
  cout << "Total de pessoas: " << Pessoa::totalPessoas() << endl;
}