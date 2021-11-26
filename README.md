# SOLID
Trabalho final de Programação Orientada a Objetos Avançada (POOA), matéria ministrada por professor Delano. Autor: Sophia Santonastasio Schuster RA: 760936

Conteudo
========

 * [Principios SOLID]
 * [Single Responsiblity Principle]
 * [Open-Closed Principle]
 * [Liskov Substitution Principle]
 * [Interface Segregation Principle]
 * [Dependency Inversion Principle]
 * [Discussões]
 * [O que é o princípio da inversão de dependência?]
 * [O que é injeção de dependência?]
 * [O que é injeção de dependência?]
 * [Qual a relação entre inversão de dependência, inversão de controle e injeção de dependência?]
 
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
Vale lembrar que o principio SRP pode e deve ser aplicado também não apenas nas classes mas em suas funções! Por exemplo em Media.cpp:
```source.c++
bool Media::mediaAprovado() {
    if (calculoMedia()>=6) return true; 
    else return false;
} //retorna verdadeiro apenas se a pessoa conseguiu alcancar a media minima para passar.
```
A função mediaAprovado tem como unica responsabilidade retornar um booleano indicando se o Aluno possui ou não media minima para passar.
Seguindo esse principio você pode reaproveitar não apenas suas classes mas suas funções e tudo no seu código mais facilmente!

### Open-Closed Principle (OCP)
 Entidades de software devem estar abertas para extensão mas fechados para modificação. 
 
 O principio OCP nos fala que quando queremos adicionar novos recursos ou comportamentos ao software o nosso código deve receber isso como uma extensão e não uma modificação em algo que já esta funcionando. A importancia de tal principio se da justamente por impedir que alteremos uma função, por exemplo, já existente em nosso código para adicionar um novo comportamento. Pois com isso corremos o risco de prejudicar algo que já estava bom. 
 
Conseguimos visualizar melhor se voltarmos ao nosso antigo exemplo de código *incorreto*
 
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

 Vamos supor, considerando o código acima, que agora a média pode ser calculada de uma maneira diferente, utilizando três notas por exemplo. Se tentarmos aplicar isso no programa da forma como ele esta implementado teriamos que alterar a função calculoMedia() adicionando um if nessa função para verificar quantas provas devemos envolver no calculo e correr o risco de quebrar o que já esta funcionando. Portanto a antiga função ResultadoAluno não respeita o principio OCP. 
 
Mas como resolvemos esse problema? 
É interessante reparar que na verdade quando aplicamos o primeiro principio SRP já temos um passo para resolver de forma mais simples o problema do segundo principio OCP. Isso ocorre pois os princípios SOLID possuem muita comunização entre si, então ao nos preocuparmos que cada classe tenha uma unica responsabilidade acabamos por criar uma nova classe Media a partir da antiga classe ResultadoAluno: 

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

Agora para garantir o principio OCP na nossa nova classe, ao adicionar um novo calculo da media ao inves de mudar a função CalculoMedia podemos apenas adicionar uma nova função que será chamada para calcularmos a media com três provas ao invés de duas. Mantendo um código mais intuitivo sem a necessidade de colocar varias responsabilidades em uma função/classe. 
 
### Liskov Substitution Principle (LSP)
Um subtipo deve ser substituivel pelo seu tipo base.

O principio LSP mostra que idealmente se temos A como subtipo de B então deve ser possivel substituir os objetos de B pelos de A sem que a funcionalidade do programa seja afetada. Seguir o LSP é benefico pois podemos chamar classes derivadas nos referindo a sua classe base sem preocupações forçando nosso programa a ter abstrações no nível certo e ser mais consistente. 

Mas como aplicamos esse principio em nosso código? Vamos a um exemplo. 

Novo ResultadoAluno.h 
```source.c++
class ResultadoAluno : public Pessoa, public Media, public Frequencia {
public:
    ResultadoAluno(string nome, long double CPF, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2);//construtor
    virtual ~ResultadoAluno();//destrutor
    virtual void imprime(); //Essa funcao imprimira os resultados dos alunos. 
private: //os atributos foram declarados no privado como solicitado.
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
Nossa nova classe ResultadoAluno já esta de acordo com o LSP, pois ela possui três subclasses:

Pessoa.h
```source.c++
class Pessoa {
public://todo mundo ve. 
    Pessoa(string nome, long double CPF); // construtor, deve ficar publico
    virtual ~Pessoa();//destrutor
    long double getCPF(); //funcao que ira pegar o CPF da pessoa. 
    string getNome(); //funcao que ira pegar o nome da pessoa.
    //funcoes devem ficar publicas. 
   virtual void imprime(); //Essa funcao imprimira os dados das pessoas. 
private: 
    long double CPF; //atributos, podem ficar privados. 
    string nome; 
};
```
Media.h
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
Frequencia.h
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

E essas três subclasses compõem exatamente a classe pai ResultadoAluno. Por isso eu posso tranquilamente utilizar os metódos de suas subclasses para imprimir os dados além de utilizar os dados de suas subclasses para obter informações como por exemplo se o aluno já foi aprovado:

ResultadoAluno.cpp
```source.c++
ResultadoAluno::ResultadoAluno(string nome, long double CPF, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2) : 
    Pessoa(nome,CPF), Frequencia(totalTarefas, tarefasFeitas), Media(p1,p2, peso1, peso2)  {
} //implementacao do construtor

void ResultadoAluno::imprime() {
    Pessoa::imprime();
    Media::imprime();
    Frequencia::imprime();
    cout << "[Resultado Final] ";
    cout << endl;
    if (Media::mediaAprovado() && !Frequencia::frequenciaAprovada()) {
        cout << "Aluno aprovado" << endl;
    } 
    //...
} 
// implementacao da funcao imprime, que imprimira nome e cpf de cada aluno, usando o metodo ja feito na classe pessoa, e seus resultados.
```
Esse principio LSP nos permite garantir que os "filhos" (subclasses) de cada "pai" (classe) consigam fazer o trabalho de seus pais sem problemas, isso é extremamente benefico pois nos da total liberdade para estender as implementações como eu quiser. 

### Interface Segregation Principle (ISP)
Uma classe não deve ser forçada a implementar métodos que não ira utilizar. 

Esse principio simplesmente nos fala que é melhor ter interfaces mais especificas do que ter interfaces genéricas que irão forçar classes a implementar um metódo que elas não deveriam ter! 

Por exemplo:
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

Nessa versão antiga da nossa classe ResultadoAluno (antes de aplicar os principios) temos uma classe extremamente genérica. Agora imagine que queiramos em uma nova classe imprimir o resultado de um aluno considerando apenas sua media e não sua frequencia... Acabariamos em uma situação extremamente desagradavel. Sendo forçados a implementar novamente funções como calculoMedia e mediaAprovado ou a utilizar a classe ResultadoAluno porém sem que o calculoFrequencia e o frequenciaAprovada se apliquem a nossa nova classe. 

Porém, graças aos principios mencionados anteriormente esses problemas já foram evitados. Para seguir o Single Responsiblity Principle separamos nossa classe em diversas outras classes e com o Liskov Substitution Principle estamos garantindo que nosso programa tenha abstrações no nível certo. Com isso temos agora uma classe para Media e Frequencia, sendo possivel ter uma classe de Resultado que herde apenas a Media e nada alem do desejado. Esse é um ótimo exemplo de como os principios se comunicam entre si, seguindo um efeito dominó. 

### Dependency Inversion Principle


### Discussões
 
 
### O que é o princípio da inversão de dependência?


### O que é injeção de dependência?


### O que é injeção de dependência?


### Qual a relação entre inversão de dependência, inversão de controle e injeção de dependência?

