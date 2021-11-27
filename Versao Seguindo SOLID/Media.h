#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

namespace poo {
class Media {
public:
    Media(int p1, int p2, int peso1, int peso2);//construtor
    virtual ~Media();//destrutor
    double calculoMedia(); //essa funcao calculara a media do aluno
    bool mediaAprovado(); //essa funcao dira se a media esta acima de 6
private: //os atributos foram declarados no privado
    int p1;
    int p2;
    int peso1;
    int peso2;
};
}

#endif /* MEDIA_H */

