#include "ResultadoAluno.h"
using namespace poo;

ResultadoAluno::ResultadoAluno(string nome, long double CPF, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2) : 
    Pessoa(nome,CPF),totalTarefas(totalTarefas), tarefasFeitas(tarefasFeitas), p1(p1),p2(p2), peso1(peso1), peso2(peso2)  {
} //implementacao do construtor

double ResultadoAluno::calculoMedia (){
    return ((p1*peso1 + p2*peso2)/(peso1 + peso2));
}

float ResultadoAluno::calculoFrequencia (){
    return (tarefasFeitas*100/totalTarefas);
}

bool ResultadoAluno::frequenciaAprovada() {
    if (calculoFrequencia()>=75) return false; //retornara false, pois acima de 75% de frequencia passou
    else return true; //qualquer outro caso a pessoa nao conseguiu frequencia suficiente 
} 

bool ResultadoAluno::mediaAprovado() {
    if (calculoMedia()>=6) return true; 
    else return false;
} //retorna verdadeiro apenas se a pessoa conseguiu alcancar a media minima para passar.

void ResultadoAluno::imprime() {
    Pessoa::imprime();
    cout << "Media Final: " << calculoMedia() << endl;
    cout << "Frequencia Final: " << calculoFrequencia() << "%" << endl;
} // implementacao da funcao imprime, que imprimira nome e cpf de cada aluno, usando o metodo ja feito na classe pessoa, e a media final do aluno. 

ResultadoAluno::~ResultadoAluno() {
} //implementacao do destrutor. 

