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

#include "Pessoa.h"
#include <iostream>
#include <string>
namespace poo {

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