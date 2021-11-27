/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pessoa.cpp
 * Author: srala
 * 
 * Created on 27 de Setembro de 2019, 18:52
 */

#include "Aluno.h"
#include <iostream>
#include <string>
namespace poo {
    
    Aluno::Aluno(string nome, long double CPF, long double RA) : 
    Pessoa(nome, CPF), RA(RA) {
    } //implementacao do construtor. 
    
    long double Aluno::getRA() {
        return RA;
    }
    
    Aluno::~Aluno() {
    } //implementacao do destrutor. 

       

}