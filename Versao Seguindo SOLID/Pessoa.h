#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;

namespace poo { 

class Pessoa {
public://todo mundo ve. 
    Pessoa(string nome, long double CPF); // construtor, deve ficar publico
    virtual ~Pessoa();//destrutor
    long double getCPF(); //funcao que ira pegar o CPF da pessoa. 
    string getNome(); //funcao que ira pegar o nome da pessoa.
    //funcoes devem ficar publicas. 
private: 
    long double CPF; //atributos, podem ficar privados. 
    string nome; 
};

}

#endif /* PESSOA_H */

