#include<iostream>

using namespace std;

class aluno{
    int matricula;
    float cra;
    public:
        aluno(int m= -1, float c=0){
            matricula = m;
            cra = c;
            cout << "aluno criado!" << endl; //endl = quebra de linha
        }
        int get_matricula(){
            return matricula;
        } 
        void set_matricula(int m){
            matricula = m;
        }
        float get_cra(){
        }
        void set_cra(float c){
        }
        ~aluno(){
            cout<<"aluno finalizado!"<<endl;
        }
};

int main(){
    aluno a1(2021, 8.9);
    int k = a1.get_matricula();
    a1.set_cra(59);
    float f = a1.get_cra();
    return 0;
} 