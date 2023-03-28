#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::cin;


// Funcionário
/*
    nome
    cpf 
    idade
    salario

*/

// Departamento
/*

    nome
    codigo
    array de funcionários
    
*/

// Empresa
/*

    nome
    cnpj
    array de departamentos

*/


class Funcionario{
    private:
        string nome;
        string cpf;
        int idade;
        float salario;
    public:
        Funcionario(string n = "0", string c = "0", int i = 0, float s = 0.0f){
            nome = n;
            cpf = c;
            idade = i;
            salario = s;
        }
        void setNome(string n){
            nome = n;
        }
        string getNome(){
            return nome;
        }
        void setCpf(string c){
            cpf = c;
        }
        string getCpf(){
            return cpf;
        }
        void setIdade(int i){
            idade = i;
        }
        int getIdade(){
            return idade;
        }
        void setSalario(float s){
            salario = s;
        }
        float getSalario(){
            return salario;
        }
        void printInfo(){
            cout << "\t\tInformações do Funcionário: "<<endl; 
            cout << "Nome: " << nome << endl;
            cout << "CPF: " << cpf << endl;
            cout << "Idade: " << idade << endl;
            cout << "Salario: " << salario << endl;
        }
};

class Departamento{
    private:
        string nome;
        int codigo;
        Funcionario *funcionarios;
        int qtdFuncionarios;
    public:
        Departamento(string n = "0", int c = 0, int qtd = 0){
            nome = n;
            codigo = c;
            qtdFuncionarios = qtd;
            funcionarios = new Funcionario[qtd];
        }
        void setNome(string n){
            nome = n;
        }
        string getNome(){
            return nome;
        }
        void setCodigo(int c){
            codigo = c;
        }
        int getCodigo(){
            return codigo;
        }
        void setQtdFuncionarios(int qtd){
            qtdFuncionarios = qtd;
        }
        int getQtdFuncionarios(){
            return qtdFuncionarios;
        }
        void setFuncionarios(Funcionario *f, int pos){
            funcionarios[pos] = *f;
        }
        Funcionario *getFuncionarios(){
            return funcionarios;
        }
        void printInfo(){
            cout << "\t\tInformações do Departamento: "<<endl; 
            cout << "Nome: " << nome << endl;
            cout << "Código: " << codigo << endl;
            cout << "Quantidade de Funcionários: " << qtdFuncionarios << endl;
            cout << "Funcionários: " << endl;
            for(int i = 0; i < qtdFuncionarios; i++){
                funcionarios[i].printInfo();
            }
        }
};

class Empresa{
    private:
        string nome;
        int cnpj;
        Departamento *departamentos;
        int qtdDepartamentos;
    public:
        Empresa(string n = "0", int  c = 0 , int qtd = 0){
            nome = n;
            cnpj = c;
            qtdDepartamentos = qtd;
            departamentos = new Departamento[qtd];
        }
        void setNome(string n){
            nome = n;
        }
        string getNome(){
            return nome;
        }
        void setCnpj(int c){
            cnpj = c;
        }
        int getCnpj(){
            return cnpj;
        }
        void setQtdDepartamentos(int qtd){
            qtdDepartamentos = qtd;
        }
        int getQtdDepartamentos(){
            return qtdDepartamentos;
        }
        void setDepartamentos(Departamento *d, int  pos){
            departamentos[pos] = *d;  //Recebe conteúdo instância
        }
        Departamento *getDepartamentos(){
            return departamentos;
        }
        void printInfo(){
            cout << "\t\tInformações da Empresa: "<<endl; 
            cout << "Nome: " << nome << endl;
            cout << "CNPJ: " << cnpj << endl;
            cout << "Quantidade de Departamentos: " << qtdDepartamentos << endl;
            cout << "Departamentos: " << endl;
            for(int i = 0; i < qtdDepartamentos; i++){
                departamentos[i].printInfo();
            }
        }
};

int main(){

    Funcionario *f1, *f2, *f3, *f4, *f5;
    Departamento *d1, *d2;
    Empresa *e1;

    f1 = new Funcionario("João", "123.456.789-00", 20, 1000.00f);
    f2 = new Funcionario("Maria", "987.654.321-00", 25, 2000.00f);
    f3 = new Funcionario("José", "123.456.789-00", 30, 3000.00f);
    f4 = new Funcionario("Ana", "987.654.321-00", 35, 4000.00f);
    f5 = new Funcionario("Pedro", "123.456.789-00", 40, 5000.00f);

    d1 = new Departamento("RH", 101, 2);
    d2 = new Departamento("TI", 741, 3);

    e1 = new Empresa("Empresa X", 123456789, 2);

    d1->setFuncionarios(f1, 0);
    d1->setFuncionarios(f2, 1);

    d2->setFuncionarios(f3, 0);
    d2->setFuncionarios(f4, 1);
    d2->setFuncionarios(f5, 2);
    
    e1->setDepartamentos(d1, 0);
    e1->setDepartamentos(d2, 1);

    cout<<"Empresa priori:"<<endl;
    e1->printInfo();

    cout<<"Informe um código: "<<endl;
    int codigo;
    cin>>codigo;

    for(int i = 0; i < e1->getQtdDepartamentos(); i++){
        if(e1->getDepartamentos()[i].getCodigo() == codigo){
            for(int j = 0; j < e1->getDepartamentos()[i].getQtdFuncionarios(); j++){
                e1->getDepartamentos()[i].getFuncionarios()[j].setSalario(e1->getDepartamentos()[i].getFuncionarios()[j].getSalario()* 1.1) ;
            }
        }
    }
    
    cout<<"Empresa posterior:"<<endl;
    e1->printInfo();


    return 0;
}