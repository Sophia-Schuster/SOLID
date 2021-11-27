#include "ResultadoAluno.h"
#include "Pessoa.h"
#include "Media.h"
using namespace std;
using namespace poo;


void imprimeAluno(ResultadoAluno& resultado) {
    resultado.imprime();
}

int main(int argc, char** argv) {
    
    //esse programa calcula para um aluno se ele foi ou não aprovado em uma matéria. Considerando frequencia, provas, media aritmetica e ponderada.
    
    string nome;
    long double CPF;
    long double RA;
    int totalTarefas;
    int tarefasFeitas;
    int p1;
    int p2;
    int tipoMedia;
    int peso1 = 1;
    int peso2 = 1;

    // Pegando os dados
    //formato (nome, totalTarefas, tarefasFeitas, notasProvas, tipoMedia, pesosProvas)
    
    cout << "Qual seu nome?"<< endl;
    cin >> nome;
    cout << "Qual seu CPF?" <<endl;
    cin >> CPF;
    cout << "Qual seu RA?" <<endl;
    cin >> RA;
    cout << "Quantas tarefas você tinha no total?" <<endl;
    cin >> totalTarefas;
    cout << "Quantas tarefas você fez?" <<endl;
    cin >> tarefasFeitas;
    
    cout << "Quanto você tirou na p1?" <<endl;
    cin >> p1;
    cout << "Quanto você tirou na p2?" <<endl;
    cin >> p2;
        
    cout << "Digite 1 se a média for aritmetica e 2 se for ponderada!" << endl;
    cin >> tipoMedia;
    if (tipoMedia == 2)
    {
        cout << "De o peso de cada uma das provas, digite o peso de cada uma seguido de enter" << endl;
        cin >> peso1;
        cin >> peso2;
    }

    ResultadoAluno resultado(nome, CPF, RA, totalTarefas, tarefasFeitas, p1, p2, peso1, peso2);
    imprimeAluno(resultado);

    cout << endl;

}
