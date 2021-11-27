#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <iostream>

#include "Pessoa.h"

using namespace std;

namespace poo { 

class Aluno : public Pessoa {
public://todo mundo ve. 
    Aluno(string nome, long double CPF, long double RA); // construtor, deve ficar publico
    virtual ~Aluno();//destrutor
    long double getRA(); //funcao que ira pegar o RA da pessoa. 
private: 
    int CPF; //atributos, podem ficar privados. 
    string nome; 
    long double RA;
};

}

#endif /* ALUNO_H */

