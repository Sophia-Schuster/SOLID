#include "Frequencia.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace poo;

Frequencia::Frequencia(int totalTarefas, int tarefasFeitas) : 
    totalTarefas(totalTarefas), tarefasFeitas(tarefasFeitas)  {
} //implementacao do construtor

float Frequencia::calculoFrequencia (){
    return (tarefasFeitas*100/totalTarefas);
}

bool Frequencia::frequenciaAprovada() {
    if (calculoFrequencia()>=75) return false; //retornara false, pois acima de 75% de frequencia passou
    else return true; //qualquer outro caso a pessoa nao conseguiu frequencia suficiente 
} 
    
Frequencia::~Frequencia() {
} //implementacao do destrutor. 

