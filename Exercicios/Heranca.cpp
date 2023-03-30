#include<iostream>

using std::cout;
using std::endl;


class Animal
{
    int idade;

public:
    Animal(int i)
    {
        cout<<"Construtor de Animal"<<endl;
        set_idade(i);
        
    }
    ~Animal()
    {
        cout<<"Destrutor de Animal"<<endl;
    }
   
    void set_idade(int i)
    {
        idade = i;
    }
    int get_idade()
    {
        return idade;
    }
    void respirar()
    {
        cout<<"Respirando"<<endl;
    }
    int envelhecer()
    {
        idade++;
        return idade;
    }
};

class Ave : public Animal
{  
    bool voa;

public:
    Ave(int i, bool v) : Animal(i)
    {
        cout<<"Construtor de Ave"<<endl;
        set_voa(v);

    }
    ~Ave()
    {
        cout<<"Destrutor de Ave"<<endl;
    }
    void set_voa(bool v)
    {
        voa = v;
    }
    bool get_voa()
    {
        return voa;
    }
    void bicar()
    {
        cout<<"Bicando"<<endl;
    }
    void nidificar()
    {
        cout<<"Nidificando"<<endl;
    }
};

class Mamifero : public Animal
{
    bool pelo;

public:

    Mamifero(int i, bool p) : Animal(i)
    {
        cout<<"Construtor de Mamifero"<<endl;
        set_pelo(p);
    }
    ~Mamifero()
    {
        cout<<"Destrutor de Mamifero"<<endl;
    }
    void set_pelo(bool p)
    {
        pelo = p;
    }
    bool get_pelo()
    {
        return pelo;
    }

    void mamar()
    {
        cout<<"Mamando"<<endl;
    }


};


int main()
{
    Ave a(2, true);
    Mamifero m(4, true);

    cout<<"Idade: "<< a.get_idade()<<endl;
    cout<<"Voa: "<< a.get_voa()<<endl;
    cout<<endl;
    cout<<"Idade: "<< m.get_idade()<<endl;
    cout<<"Pelo: "<< m.get_pelo()<<endl;
    cout<<endl;
    a.bicar();
    a.respirar();   
    m.mamar();
    m.respirar();
    cout<<endl;
    a.envelhecer();
    m.envelhecer();
    cout<<endl;
    cout<<"Idade: "<< a.get_idade()<<endl;
    cout<<"Idade: "<< m.get_idade()<<endl;
    cout<<endl;

    return 0;
}