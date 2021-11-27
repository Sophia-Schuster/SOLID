#ifndef RESULTADOALUNO_H
#define RESULTADOALUNO_H

#include "Media.h"
#include "Frequencia.h"
#include "Aluno.h"

namespace poo {
class ResultadoAluno : public Aluno, public Media, public Frequencia {
public:
    ResultadoAluno(string nome, long double CPF, long double RA, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2);//construtor
    virtual ~ResultadoAluno();//destrutor
    virtual void imprime(); //Essa funcao imprimira os resultados dos alunos. 
private: //os atributos foram declarados no privado como solicitado.
    string nome;
    long double CPF;
    long double RA;
    int totalTarefas;
    int tarefasFeitas;
    int p1;
    int p2;
    int peso1;
    int peso2;
};
}

#endif /* RESULTADOALUNO_H */

