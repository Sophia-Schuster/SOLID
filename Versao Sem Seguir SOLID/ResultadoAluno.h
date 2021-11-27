#ifndef RESULTADOALUNO_H
#define RESULTADOALUNO_H

#include "Pessoa.h"

namespace poo {
class ResultadoAluno : public Pessoa {
public:
    ResultadoAluno(string nome, long double CPF, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2);//construtor
    virtual ~ResultadoAluno();//destrutor
    virtual void imprime(); //Essa funcao imprimira os dados dos alunos. 
    double calculoMedia(); //essa funcao calculara a media do aluno
    bool mediaAprovado(); //essa funcao dira se o aluno foi aprovado ou nao
    float calculoFrequencia(); //essa funcao calcula a frequencia
    bool frequenciaAprovada(); //essa funcao dira se o aluno foi reprovado por falta (menos que 75% de frequencia) ou nao
private: //os atributos foram declarados no privado como solicitado.
    string nome;
    long double CPF;
    int totalTarefas;
    int tarefasFeitas;
    int p1;
    int p2;
    int peso1;
    int peso2;
};
}

#endif /* RESULTADOALUNO_H */

