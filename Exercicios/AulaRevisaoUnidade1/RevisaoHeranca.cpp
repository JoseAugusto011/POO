#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Animal{
    char nome;
    int idade;
public:
    Animal(char nome, int idade){
        this->nome = nome;
        this->idade = idade;
        cout<<"Animal criado"<<endl;
    }
    ~Animal(){
        cout<<"Animal destruido"<<endl;
    }
    void setNome(char nome){
        this->nome = nome;
    }
    void setIdade(int idade){
        this->idade = idade;
    }
    char getNome(){
        return nome;
    }
    int getIdade(){
        return idade;
    }
    void print(){
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
    }
};


class Papagaio: public Animal{
    float envergadura;
    bool fala;

public:

    Papagaio(char nome, int idade, float envergadura, bool fala): Animal(nome, idade){
        this->envergadura = envergadura;
        this->fala = fala;
        cout<<"Papagaio criado"<<endl;
    }
    ~Papagaio(){
        cout<<"Papagaio destruido"<<endl;
    }	
    void setEnvergadura(float envergadura){
        this->envergadura = envergadura;
    }
    void setFala(bool fala){
        this->fala = fala;
    }
    float getEnvergadura(){
        return envergadura;
    }
    bool getFala(){
        return fala;
    }
    void print(){
        Animal::print();
        cout << "Envergadura: " << envergadura << endl;
        cout << "Fala: " << fala << endl;
    }
};

class Gato: public Animal{

    string pelagem;
    float tamanhoGarra;


public:

    Gato(char nome, int idade, string pelagem, float tamanhoGarra): Animal(nome, idade){
        this->pelagem = pelagem;
        this->tamanhoGarra = tamanhoGarra;
        cout<<"Gato criado"<<endl;
    }
    ~Gato(){
        cout<<"Gato destruido"<<endl;
    }
    void setPelagem(string pelagem){
        this->pelagem = pelagem;
    }
    void setTamanhoGarra(float tamanhoGarra){
        this->tamanhoGarra = tamanhoGarra;
    }
    string getPelagem(){
        return pelagem;
    }
    float getTamanhoGarra(){
        return tamanhoGarra;
    }
    void print(){
        Animal::print();
        cout << "Pelagem: " << pelagem << endl;
        cout << "Tamanho da Garra: " << tamanhoGarra << endl;
    }
};


class Arara: public Animal{

    float envergadura, tamanhoBico;
public:

    Arara(char nome, int idade, float envergadura, float tamanhoBico): Animal(nome, idade){
        this->envergadura = envergadura;
        this->tamanhoBico = tamanhoBico;
        cout<<"Arara criada"<<endl;
    }
    ~Arara(){
        cout<<"Arara destruida"<<endl;
    }
    void setEnvergadura(float envergadura){
        this->envergadura = envergadura;
    }
    void setTamanhoBico(float tamanhoBico){
        this->tamanhoBico = tamanhoBico;
    }
    float getEnvergadura(){
        return envergadura;
    }
    float getTamanhoBico(){
        return tamanhoBico;
    }
    void print(){
        Animal::print();
        cout << "Envergadura: " << envergadura << endl;
        cout << "Tamanho do Bico: " << tamanhoBico << endl;
    }
};

class Cachorro: public Animal{

    string pelagem;
    bool adestrado;

public:

    Cachorro(char nome, int idade, string pelagem, bool adestrado): Animal(nome, idade){
        this->pelagem = pelagem;
        this->adestrado = adestrado;
        cout<<"Cachorro criado"<<endl;
    }
    ~Cachorro(){
        cout<<"Cachorro destruido"<<endl;
    }
    void setPelagem(string pelagem){
        this->pelagem = pelagem;
    }
    void setAdestrado(bool adestrado){
        this->adestrado = adestrado;
    }
    string getPelagem(){
        return pelagem;
    }
    bool getAdestrado(){
        return adestrado;
    }
    void print(){
        Animal::print();
        cout << "Pelagem: " << pelagem << endl;
        cout << "Adestrado: " << adestrado << endl;
    }
};

    