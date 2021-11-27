#include "ResultadoAluno.h"
using namespace poo;

ResultadoAluno::ResultadoAluno(string nome, long double CPF, long double RA, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2) : 
    Aluno(nome, CPF, RA), Frequencia(totalTarefas, tarefasFeitas), Media(p1,p2, peso1, peso2)  {
} //implementacao do construtor

void ResultadoAluno::imprime() {
    cout<<"nome: "<<Aluno::getNome()<<endl; 
    cout<<"CPF: "<<Aluno::getCPF()<<endl; 
    cout<<"RA: "<<Aluno::getRA()<<endl; 
    cout << "Media Final: " << Media::calculoMedia() << endl;
    cout << "Frequencia Final: " << Frequencia::calculoFrequencia() << "%" << endl;
    cout << "[Resultado Final] ";
    cout << endl;
    if (Media::mediaAprovado() && !Frequencia::frequenciaAprovada()) {
        cout << "Aluno aprovado" << endl;
    } if (Frequencia::frequenciaAprovada()){
        cout << "Aluno reprovado por frequencia." << endl;
    } else if (Media::calculoMedia() >= 5 && Media::calculoMedia() < 6) {
        cout << "Você pode fazer um SAC" << endl;
    } if (!Media::mediaAprovado()) {
        cout << "Aluno reprovado por nota." << endl;
    }
} // implementacao da funcao imprime, que imprimira nome e cpf de cada aluno, usando o metodo ja feito na classe pessoa, e seus resultados.  

ResultadoAluno::~ResultadoAluno() {
} //implementacao do destrutor. 

