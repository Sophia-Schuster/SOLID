#include "Pessoa.h"
#include <iostream>
#include <string>
#include <iomanip>
namespace poo {

void Pessoa::imprime() {
    cout<<"nome: "<<nome<<endl; 
    cout<<"CPF: "<< std::setprecision(15) << CPF <<endl;  
    } // implementacao da funcao imprime, que imprimira nome e cpf de cada pessoa. 

    long double Pessoa::getCPF() {
        return CPF;
    } 

    string Pessoa::getNome() {
        return nome;
    }  
   
    Pessoa::Pessoa(string nome, long double CPF) : 
    nome(nome), CPF(CPF) {
    } //implementacao do construtor. 
    
    Pessoa::~Pessoa() {
    } //implementacao do destrutor. 

       

}