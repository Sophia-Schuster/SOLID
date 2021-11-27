#include "Media.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace poo;

Media::Media(int p1, int p2, int peso1, int peso2) : 
    p1(p1),p2(p2), peso1(peso1), peso2(peso2)  {
} //implementacao do construtor

double Media::calculoMedia (){
    return ((p1*peso1 + p2*peso2)/(peso1 + peso2));
}

bool Media::mediaAprovado() {
    if (calculoMedia()>=6) return true; 
    else return false;
} //retorna verdadeiro apenas se a pessoa conseguiu alcancar a media minima para passar.

Media::~Media() {
} //implementacao do destrutor. 

