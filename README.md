# SOLID
Trabalho final de Programação Orientada a Objetos Avançada (POOA), matéria ministrada por professor Delano. Autor: Sophia Santonastasio Schuster RA: 760936

Conteudo
========

 * [Principios SOLID](#SOLID)
 * [Single Responsiblity Principle](#S)
 * [Open-Closed Principle](#O)
 * [Liskov Substitution Principle](#L)
 * [Interface Segregation Principle](#I)
 * [Dependency Inversion Principle](#D)
 * [Discussões](#Discussoes)
 * [O que é o princípio da inversão de dependência?](#1)
 * [O que é injeção de dependência?](#2)
 * [O que é injeção de dependência?](#3)
 * [Qual a relação entre inversão de dependência, inversão de controle e injeção de dependência?](#4)
 
 ### Principios SOLID
 São cinco princípios da programação orientada a objetos. Princípios os quais ajudam o programador a escrever códigos limpos facilitando a posterior escrita e leitura destes códigos. Neste artigo veremos cada um dos princípios SOLID definiremos e exemplificaremos cada um.  Para auxiliar nesse artigo criei um código em C++, no qual pegamos os dados de um Aluno e calculamos se ele foi ou não aprovado em uma matéria com duas provas ou se precisa de SAC, considerando uma média para as provas especificada pelo aluno (aritmética simples ou ponderada) e sua frequência. 

 
### Single Responsiblity Principle (SRP)
 Cada classe deve ter somente um motivo para mudar. 

Esse princípio declara que cada classe deve possuir apenas uma responsabilidade dentro do projeto. Mas por que é importante cada classe ter sua própria responsabilidade? 

Podemos considerar cada responsabilidade um eixo de mudança, se uma classe possui mais de um eixo de mudança caso queiramos mudar apenas um deles podemos prejudicar o funcionamento da classe como um todo comprometendo outras responsabilidades. Com isso teremos um projeto frágil.

Mas assim como ter mais de uma responsabilidade é ruim realizar mudanças desnecessárias também não é positivo. Se as responsabilidades de nossa classe não mudam ou mudam em momentos diferentes não há a necessidade de separá-las. Pelo contrário, se separarmos o código teria uma complexidade desnecessária.

Vamos a um exemplo

Abaixo temos um código que seria considerado *incorreto* 

Antigo ResultadoAluno.h
```source.c++
class ResultadoAluno : public Pessoa {
public:
    ResultadoAluno(string nome, long double CPF, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2);//construtor
    virtual ~ResultadoAluno();//destrutor
    virtual void imprime(); //Essa funcao imprimira os dados dos alunos. 
    double calculoMedia(); //essa funcao calculara a media do aluno
    bool mediaAprovado(); //essa funcao dira se o aluno foi aprovado ou nao
    float calculoFrequencia(); //essa funcao calcula a frequencia
    bool frequenciaAprovada(); //essa funcao dira se o aluno foi reprovado por falta (menos que 75% de frequencia) ou nao
private: //atributos foram declarados no privado.
    string nome;
    long double CPF;
    int totalTarefas;
    int tarefasFeitas;
    int p1;
    int p2;
    int peso1;
    int peso2;
};
```
A classe ResultadoAluno realmente retorna o resultado do aluno em termos de aprovação. Porém ela viola o SRP implementada dessa forma.  Se olharmos com cuidado é possivel ver diversos eixos de mudança:

Vamos supor que eu queria mudar a forma como a média é calculada. Ao realizar essa mudança não é necessário que isso impacte no calculo de frequencia por exemplo. Portanto o ideal seria uma classe que realiza o calculo da media. 

Da mesma forma o ideal seria uma classe responsavel para o calculo de frequencia já que se eu decidir por alterar a forma como é feito esse calculo não quero que isso impacte na forma como é impresso os dados do meu aluno. 

Afinal esses eixos são coisas independentes que a mudança de um não deve impactar no outro. 

Olhando para essa analise podemos dividir essa classe para que ela tenha sua própria responsabilidade, adicionando então duas novas classes e deixando essa classe apenas para o resultado final e não para o calculo de frequencia ou media:

Novo Media.h
```source.c++
class Media {
public:
    Media(int p1, int p2, int peso1, int peso2);//construtor
    virtual ~Media();//destrutor
    double calculoMedia(); //essa funcao calculara a media do aluno
    bool mediaAprovado(); //essa funcao dira se a media esta acima de 6
    virtual void imprime(); //Essa funcao imprimira o resultado da media
private: //os atributos foram declarados no privado
    int p1;
    int p2;
    int peso1;
    int peso2;
};
```
Novo Frequencia.h
```source.c++
class Frequencia {
public:
    Frequencia(int totalTarefas, int tarefasFeitas);//construtor
    virtual ~Frequencia();//destrutor
    float calculoFrequencia(); //essa funcao calcula a frequencia
    bool frequenciaAprovada(); //essa funcao dira se o aluno foi reprovado por falta (menos que 75% de frequencia) ou nao
    virtual void imprime(); //Essa funcao imprimira o resultado da frequencia.
private: //os atributos foram declarados no privado
    int totalTarefas;
    int tarefasFeitas;
};
```

### Open-Closed Principle (OCP)
 Entidades de software devem estar abertas para extensão mas fechados para modificação. 
 
 O principio OCP nos fala que quando queremos adicionar novos recursos ou comportamentos ao software o nosso código deve receber isso como uma extensão e não uma modificação em algo que já esta funcionando. A importancia de tal principio se da justamente por impedir que alteremos uma função, por exemplo, já existente em nosso código para adicionar um novo comportamento. Pois com isso corremos o risco de prejudicar algo que já estava bom. 
 
 Por exemplo, se voltarmos ao nosso antigo exemplo de código incorreto
 
Antigo ResultadoAluno.h
```source.c++
class ResultadoAluno : public Pessoa {
public:
    ResultadoAluno(string nome, long double CPF, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2);//construtor
    virtual ~ResultadoAluno();//destrutor
    virtual void imprime(); //Essa funcao imprimira os dados dos alunos. 
    double calculoMedia(); //essa funcao calculara a media do aluno
    bool mediaAprovado(); //essa funcao dira se o aluno foi aprovado ou nao
    float calculoFrequencia(); //essa funcao calcula a frequencia
    bool frequenciaAprovada(); //essa funcao dira se o aluno foi reprovado por falta (menos que 75% de frequencia) ou nao
private: //atributos foram declarados no privado.
    string nome;
    long double CPF;
    int totalTarefas;
    int tarefasFeitas;
    int p1;
    int p2;
    int peso1;
    int peso2;
};
```

 Vamos supor que agora a média pode ser calculada de uma maneira diferente, considerando três provas por exemplo. Se tentarmos aplicar isso no programa da forma como ele estava teriamos que alterar a função calculoMedia() adicionando um if nessa função para verificar quantas provas devemos envolver no calculo e correr o risco de quebrar o que já esta funcionando. Portanto a antiga função ResultadoAluno não respeita o principio OCP. 
 
Mas como resolvemos esse problema? 
É interessante reparar que na verdade quando aplicamos o primeiro principio SRP já temos um grande passo para resolver o problema do segundo principio OCP. Isso ocorre pois os princípios SOLID possuem muita comunização entre si, então ao nos preocuparmos que cada classe tenha uma unica responsabilidade acabamos por separar uma classe Media da classe ResultadoAluno: 

Novo Media.h
```source.c++
class Media {
public:
    Media(int p1, int p2, int peso1, int peso2);//construtor
    virtual ~Media();//destrutor
    double calculoMedia(); //essa funcao calculara a media do aluno
    bool mediaAprovado(); //essa funcao dira se a media esta acima de 6
    virtual void imprime(); //Essa funcao imprimira o resultado da media
private: //os atributos foram declarados no privado
    int p1;
    int p2;
    int peso1;
    int peso2;
};
```

Agora para garantir o principio OCP na nossa nova classe, ao adicionar um novo calculo da media ao inves de mudar a função CalculoMedia podemos apenas adicionar uma nova função que será chamada para calcularmos a media com três provas ao invés de duas. E assim por diante poderiamos implementar um CalculoMedia para quantas provas desejarmos. 
 
 
### Liskov Substitution Principle (LSP)



### Interface Segregation Principle


### Dependency Inversion Principle


### Discussões
 
 
### O que é o princípio da inversão de dependência?


### O que é injeção de dependência?


### O que é injeção de dependência?


### Qual a relação entre inversão de dependência, inversão de controle e injeção de dependência?

