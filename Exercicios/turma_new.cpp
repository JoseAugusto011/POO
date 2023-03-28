
#include <iostream>

using namespace std;

class turma {
    int codigo;
    int qtd_matriculas;
    int* matriculas;
public: 
    turma(int c, int q) {
        codigo = c;
        qtd_matriculas = q;
        matriculas = new int[q];
        cout << "Turma " << c << " criada!" << endl;
    }
    
    ~turma() {
        delete[] matriculas;
        cout << "Turma " << codigo << " finalizada!" << endl;
    }
    
    int add_matricula(int m, int pos) {
        if (pos >= qtd_matriculas) 
            return -1;
        else {
            matriculas[pos] = m;
            return pos;
        }
    }
    
    int get_matricula(int pos) {
        if (pos >= qtd_matriculas) 
            return -1;
        else {
            return matriculas[pos];
        }
    }
    
    int get_codigo() {
        return codigo;
    }
    
    void set_codigo(int c) {
        codigo = c;
    }
    
    int get_qtd_matriculas() {
        return qtd_matriculas;
    }
    
    void set_qtd_matriculas(int q) {
        int* new_mat = new int[q];
        if (q > qtd_matriculas) { // se a nova quantidade for maior que a antiga
            for (int i = 0; i < qtd_matriculas; i++) {
                new_mat[i] = matriculas[i]; // copia os valores antigos para o novo vetor
            }
        } else {
            for (int i = 0; i < q; i++) {
                new_mat[i] = matriculas[i];
            }
        }
        delete[] matriculas; // libera o espaço de memória do vetor antigo
        matriculas = new_mat;// aponta o ponteiro para o novo vetor
        qtd_matriculas = q;
    }
    
    void print_matriculas() {
        cout << "Quantidade de matriculas: ";
        cout << qtd_matriculas << endl;
        for (int i = 0; i < qtd_matriculas; i++) {
            cout << "[" << i << "] " << matriculas[i] << endl;
        }
    }
    
    
};

int main()
{
    turma t1(1011, 30);

    t1.add_matricula(20231010, 0);
    t1.add_matricula(20231011, 1);
    t1.add_matricula(20231012, 2);
    t1.add_matricula(20231013, 3);
    
    t1.print_matriculas();
    
    t1.set_qtd_matriculas(3);
    
    t1.print_matriculas();
    
    return 0;
}