
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
#include <vector>

class Conjunto
{
private:
    int QtdElementos;
    int *Elementos;
    void create_Elementos(int qtd)
    {
        Elementos = (int *)malloc(sizeof(int) * qtd);
        printf("Funcao create_Elementos executada!\n");
    }

public:
    Conjunto()
    {
        setQtdElementos(0);
        printf("\nConjunto criado com  espaço para %d elementos!\n", getQtdElementos());
        create_Elementos(getQtdElementos());
    }
    Conjunto(int QtdElementos)
    {
        setQtdElementos(QtdElementos);
        printf("\nConjunto criado com  espaço para %d elementos!\n", getQtdElementos());
        create_Elementos(getQtdElementos());
    }
    ~Conjunto()
    {   
        if (Elementos != NULL)
        {
            free(Elementos);
        }
        printf("\nConjunto destruido!\n");
    }
    int getQtdElementos()
    {
        return QtdElementos;
    }
    void setQtdElementos(int n)
    {
        QtdElementos = n;
    }

    // Metodos dos conjuntos
    void MostraElementos() //OK
    {
        if (getQtdElementos() == 0)
        {
            printf("\nNão é possivel mostrar um grupo vazio!\n");
            return;
        }
        else
        {

            printf("\nElementos do grupo: ");
            for (int i = 0; i < getQtdElementos(); i++) //Percorre o vetor de elementos e mostra na tela
            {
                printf("%d ", Elementos[i]);
            }
            printf("\n");
            
        }
    }
    void InsereElementos() //OK
    {

        for (int i = 0; i < getQtdElementos(); i++) //Percorre o vetor de elementos e insere valores
        {
            printf("\nDigite o elemento %d: ", i + 1);
            cin >> Elementos[i];
        }
        printf("\nElementos inseridos com sucesso!\n");
    }
    void RemoveElementos() //OK
    {
        if (getQtdElementos() == 0) //Se a quantidade de elementos for igual a 0, não é possivel remover !
        {
            printf("\nNão é possivel remover um grupo vazio!\n");
        }
        else
        {
            int Elemento; //Elemento que será removido
            printf("\nDigite o elemento que deseja remover: ");
            cin >> Elemento;
            for (int i = 0; i < getQtdElementos(); i++)//Percorre o vetor de elementos e verifica se o elemento existe
            {
                if (Elementos[i] == Elemento) //Se o elemento existir, ele é substituido por 999
                {
                    Elementos[i] = 999;
                    printf("\nElemento removido com sucesso!\n");
                    break;
                }
                else
                {
                    printf("\n...\n");
                }
            }
            // Ordenação dos elementos
            for (int i = 0; i < getQtdElementos(); i++)  //999 será o ultimo elemento
            {
                for (int j = i + 1; j < getQtdElementos(); j++)
                {
                    if (Elementos[i] > Elementos[j])
                    {
                        int aux = Elementos[i];
                        Elementos[i] = Elementos[j];
                        Elementos[j] = aux;
                    }
                }
            }
            // Remoção do elemento 999
            setQtdElementos(getQtdElementos() - 1); //Diminui a quantidade de elementos em 1 eliminando o ultimo elemento --> 999
            MostraElementos();
            

        }
    }
    void ModificaElementos() //OK
    {
        if (getQtdElementos() == 0) //Se a quantidade de elementos for igual a 0, não é possivel modificar !
        {
            printf("\nNão é possivel modificar um grupo vazio!\n");
            return;
        }
        else
        {
            int Elemento, NovoElemento; //Elemento que será modificado
            printf("\nDigite o elemento que deseja modificar: ");
            cin >> Elemento;
            for (int i = 0; i < getQtdElementos(); i++)
            {
                if (Elementos[i] == Elemento) //Se o elemento existir, ele é substituido pelo novo elemento
                {
                    printf("\nDigite o novo elemento: ");
                    cin >> NovoElemento;
                    Elementos[i] = NovoElemento;
                    printf("\nElemento modificado com sucesso!\n");
                    break;
                }
                else
                {
                    printf("\nElemento não encontrado!\n");
                }
            }
        }
    }
    /*
    
    void PreencheElementoVazio() //Testar
    {
        for (int i = 0; i < getQtdElementos(); i++)
        {
            if (Elementos[i] == -999)
            {
                printf("\nElemento vazio encontrado na posicao %d!\n", i + 1);
                printf("\nDigite o elemento que deseja inserir: ");
                cin >> Elementos[i];
                printf("\nElemento inserido com sucesso!\n");
            }
        }
    }


    */  
    void Uniao(Conjunto B) //OK
    {

        if (getQtdElementos() == 0 && B.getQtdElementos() == 0) //Se os dois conjuntos forem vazios, a união é vazia
        {
            printf("\nNão é possivel realizar a união de conjuntos vazios!\n");
            printf("\nVAZIO + VAZIO = VAZIO\n");
        }
        else
        {
            int tamanho = getQtdElementos() + B.getQtdElementos() , indice = 0 , redimensionado = 0, valores_repetidos = 0;
            // Tamnho do novo conjunto será a soma dos tamanhos dos conjuntos A e B           
            Conjunto C(tamanho);
            

            // União dos conjuntos
            //Percorre o vetor de elementos do conjunto A e insere no vetor de elementos do conjunto C
            for (int i = 0; i < getQtdElementos(); i++) 
            {
                C.Elementos[i] = Elementos[i];
            }
            
            for (int i = 0; i < B.getQtdElementos(); i++)
            {
                //Insere os elementos do conjunto B no conjunto C, a partir da posição do ultimo elemento do conjunto A
                C.Elementos[i + getQtdElementos()] = B.Elementos[i]; 
            }
            // Contagem de valores repetidos
            for (int i = 0; i < C.getQtdElementos(); i++)
            {
                for (int j = i + 1; j < C.getQtdElementos(); j++)
                {
                    if (C.Elementos[i] == C.Elementos[j])
                    {
                        valores_repetidos++;
                    }
                }
            }
            // Ordenação dos elementos
            for (int i = 0; i < C.getQtdElementos(); i++)
            {
                for (int j = i + 1; j < C.getQtdElementos(); j++)
                {
                    if (C.Elementos[i] > C.Elementos[j])
                    {
                        int aux = C.Elementos[i];
                        C.Elementos[i] = C.Elementos[j];
                        C.Elementos[j] = aux;
                    }
                }
            }

            // Redirecionamento dos elementos repetidos para o final do vetor
            for (int i = 0; i < C.getQtdElementos(); i++)
            {
                for (int j = i + 1; j < C.getQtdElementos(); j++) //Compara o elemento com todos os outros elementos
                {
                    if (C.Elementos[i] == C.Elementos[j]) 
                    //Se o elemento for igual a algum outro elemento, ele é movido para o final do vetor
                    {
                        int aux = C.Elementos[i];
                        C.Elementos[i] = C.Elementos[j];
                        C.Elementos[j] = aux;
                    }
                }
            }


            // Redimensionamento do vetor
            if (valores_repetidos > 0)
            {
                redimensionado = C.getQtdElementos() - valores_repetidos;
                C.setQtdElementos(redimensionado);
            }
            printf("\nUnião realizada com sucesso!\n");
            C.MostraElementos();
        }
    }
    void Intersecao(Conjunto B) //OK
    {
        if (getQtdElementos() == 0 || B.getQtdElementos() == 0)
        {
            printf("\nNao é possivel realizar a intersecao de conjuntos vazios!\n");
        }
        else
        {
            int tamanho;

            if (getQtdElementos() > B.getQtdElementos())
            {
                tamanho = getQtdElementos();
            }
            else
            {
                tamanho = B.getQtdElementos();
            }
            Conjunto C(tamanho);

            printf("\nTamanho do conjunto: %d", C.getQtdElementos());
            printf("\nTamanho da lista de elementos: %d\n", sizeof(C.Elementos));
            int indice = 0;

            for (int i = 0; i < getQtdElementos(); i++)
            {
                for (int j = 0; j < B.getQtdElementos(); j++)
                {
                    if (Elementos[i] == B.Elementos[j])
                    {
                        C.Elementos[indice] = Elementos[i];
                        printf("\nElemento %d inserido no vetor C.Elementos\n", C.Elementos[indice]);
                        indice++;
                    }
                }
            }

           
            printf("\nInterseção realizada com sucesso!\n");
            C.setQtdElementos(indice);
            C.MostraElementos();
            
        }
    }

};

void Menu();

int main()
{
    printf("\n\tTeste de Uniao e Interseccao de Conjuntos\n");
    Menu();
    return 0;
}

void Menu()
{

    int opcao, qtdConjuntos, qtdElementos, grupo, Conjunto1, Conjunto2;
    opcao = -1;

    printf("\nDigite a quantidade de conjuntos que deseja criar: ");
    cin >> qtdConjuntos;
    Conjunto conjuntos[qtdConjuntos];

    while (opcao != 0)
    {

        printf("\n\t\tMenu\n");
        printf("\n1 - Inserir elementos");
        printf("\n2 - Remover elementos");
        printf("\n3 - Modificar elementos");
        printf("\n4 - Uniao");
        printf("\n5 - Interseccao");
        printf("\n6 - Prenche Elemento Vazio  --> (Desativado !)");
        printf("\n7 - Imprimir Conjunto");
        printf("\n0 - Sair");
        printf("\nDigite a opcao desejada: ");
        cin >> opcao;

        switch (opcao)
        {
        case 1:

            printf("\nDigite o grupo que deseja inserir o elemento: ");
            cin >> grupo;
            if (grupo > qtdConjuntos || grupo < 1)
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else
            {
                printf("\nDigite a quantidade de elementos que deseja inserir: ");
                cin >> qtdElementos;
                conjuntos[grupo - 1].setQtdElementos(qtdElementos);
                conjuntos[grupo - 1].InsereElementos();
                break;
            }

        case 2:

            printf("\nDigite o grupo que deseja remover o elemento: ");
            cin >> grupo;
            if (grupo > qtdConjuntos || grupo < 1)
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else
            {

                // conjuntos[grupo - 1]
                conjuntos[grupo - 1].RemoveElementos();
                break;
            }

        case 3:

            if (grupo > qtdConjuntos || grupo < 1)
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else
            {
                printf("\nDigite o grupo que deseja modificar o elemento: ");
                cin >> grupo;
                conjuntos[grupo - 1].ModificaElementos();
                break;
            }

        case 4:

            printf("\nDigite o primeiro grupo: ");
            cin >> Conjunto1;
            printf("\nDigite o segundo grupo: ");
            cin >> Conjunto2;

            
            if ((Conjunto1 > qtdConjuntos) or (Conjunto2 > qtdConjuntos))
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else if ((Conjunto1 < 1) or (Conjunto2 < 1))
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else
            {
                conjuntos[Conjunto1 - 1].Uniao(conjuntos[Conjunto2 - 1]);
                break;
            }

        case 5:

            printf("\nDigite o primeiro grupo: ");
            cin >> Conjunto1;
            printf("\nDigite o segundo grupo: ");
            cin >> Conjunto2;
            if ((Conjunto1 > qtdConjuntos || Conjunto2 > qtdConjuntos) || (Conjunto1 < 1 || Conjunto2 < 1))
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else
            {
                conjuntos[Conjunto1 - 1].Intersecao(conjuntos[Conjunto2 - 1]);
                break;
            }
            /* 
             case 6:

            printf("\nDigite o grupo que deseja preencher o elemento vazio: ");
            cin >> grupo;
            if (grupo > qtdConjuntos || grupo < 1)
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else
            {
                conjuntos[grupo - 1].PreencheElementoVazio();
                break;
            }
            */
        
       

        case 7:

            printf("\nDigite o grupo que deseja imprimir: ");
            cin >> grupo;
            if (grupo > qtdConjuntos || grupo < 1)
            {
                printf("\nGrupo invalido!\n");
                break;
            }
            else
            {
                conjuntos[grupo - 1].MostraElementos();
                break;
            }
        case 0:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }
    }
}