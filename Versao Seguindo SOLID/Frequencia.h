#ifndef FREQUENCIA_H
#define FREQUENCIA_H

using namespace std;

namespace poo {
class Frequencia {
public:
    Frequencia(int totalTarefas, int tarefasFeitas);//construtor
    virtual ~Frequencia();//destrutor
    float calculoFrequencia(); //essa funcao calcula a frequencia
    bool frequenciaAprovada(); //essa funcao dira se o aluno foi reprovado por falta (menos que 75% de frequencia) ou nao
private: //os atributos foram declarados no privado
    int totalTarefas;
    int tarefasFeitas;
};
}

#endif /* FREQUENCIA_H */

