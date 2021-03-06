# SOLID
Matéria ministrada por professor Delano. 
Autor: Sophia Santonastasio Schuster RA: 760936

Conteudo
========

 * [Principios SOLID]
 * [Single Responsiblity Principle]
 * [Open-Closed Principle]
 * [Liskov Substitution Principle]
 * [Interface Segregation Principle]
 * [Dependency Inversion Principle]
 * [Descrição Arquitetural]
 * [Discussões]
 * [O que é o princípio da inversão de dependência?]
 * [O que é injeção de dependência?]
 * [O que é  inversão de controle?]
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
A classe ResultadoAluno realmente retorna o resultado do aluno em termos de aprovação. Porém ela viola o SRP implementada dessa forma.  Se olharmos com cuidado é possivel ver diversos eixos de mudança:

Vamos supor que eu queria mudar a forma como a média é calculada. Ao realizar essa mudança não é necessário que isso impacte no calculo de frequencia por exemplo. Portanto o ideal seria uma classe que realiza o calculo da media. Da mesma forma considerando o inverso o ideal seria uma classe responsavel para o calculo de frequencia também.

Afinal esses eixos são coisas independentes que a mudança de um não deve impactar no outro. 

Olhando para essa analise podemos dividir essa classe para que ela tenha sua própria responsabilidade (apenas o resultado final), adicionando então duas novas classes para o calculo de frequencia ou media:

Novo Media.h
```source.c++
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
```
Novo Frequencia.h
```source.c++
class Frequencia {
public:
    Frequencia(int totalTarefas, int tarefasFeitas);//construtor
    virtual ~Frequencia();//destrutor
    float calculoFrequencia(); //essa funcao calcula a frequencia
    bool frequenciaAprovada(); //essa funcao dira se o aluno foi reprovado por falta (menos que 75% de frequencia) ou nao
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

Novo Aluno.h 
```source.c++
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
```
Nossa nova classe Aluno já esta de acordo com o LSP, veja a subclasse Pessoa:

Pessoa.h
```source.c++
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
```

A subclasse Aluno é composta exatamente da classe Pessoa. Pois uma Pessoa possui Nome e CPF, assim como o Aluno que além de possuir Nome e CPF possui RA. Por isso eu posso tranquilamente utilizar metódos na subclasse para executar uma tarefa para a classe Pessoa.

Esse principio LSP nos permite garantir que os "filhos" (subclasses) de cada "pai" (classe) consigam fazer o trabalho de seus pais sem problemas, isso é extremamente benefico pois nos da total liberdade para estender as implementações como quisermos. 

### Interface Segregation Principle (ISP)
Uma classe não deve ser forçada a implementar métodos que não ira utilizar. 

Esse principio simplesmente nos fala que é melhor ter interfaces mais especificas do que ter interfaces genéricas que irão forçar classes a implementar um metódo que elas não deveriam! 

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

Nessa versão antiga da nossa classe ResultadoAluno (antes de aplicar os principios) temos uma classe extremamente genérica. Agora imagine que queiramos em uma nova classe imprimir o resultado de um aluno considerando apenas sua media e não sua frequencia... Acabariamos em uma situação extremamente desagradavel. Sendo forçados a implementar novamente funções como calculoMedia e mediaAprovado ou a utilizar a classe ResultadoAluno porém sem que o calculoFrequencia e o frequenciaAprovada se apliquem a nossa nova classe. 

Porém, graças aos principios mencionados anteriormente esses problemas já foram evitados. Para seguir o Single Responsiblity Principle separamos nossa classe em diversas outras classes e com o Liskov Substitution Principle estamos garantindo que nosso programa tenha abstrações no nível certo. Com isso temos agora uma classe para Media:

Media.h
```source.c++
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
```
Tornando possivel ter uma classe que herde apenas a Media e nada alem do desejado. Esse é um ótimo exemplo de como os principios se comunicam entre si, seguindo um efeito dominó. 

### Dependency Inversion Principle (DIP)
Não dependa de implementações e sim de abstrações

Esse principio defende que um módulo não deve depender diretamente de detalhes de implementação de outro modulo, na verdade deve existir uma abstração ali no meio para intermediar essa dependencia. 

Esse principio, assim como no exemplo do principio anterior, é ótimo para mostrar como os principios se comunicam entre si. Isso porque se seguirmos corretamente o Single Responsiblity Principle e o Liskov Substitution Principle o ultimo principio DIP provavelmente já estara sendo aplicado. 

Vamos explicar melhor exemplificando: 

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
Antes de aplicar os principios SOLID tinhamos a classe ResultadoAluno acima. A classe calcula o resultado do aluno (aprovado ou não) baseada em suas próprias funções, como calculoMedia e calculoFrequencia. Porém o ideal para seguir o principio DIP seria que para calcular o resultado utilizassemos uma abstração, pois assim poderiamos calcular o resultado facilmente com diversas outras ferramentas que forem dadas para a classe ResultadoAluno.

Após aplicar os principios ficamos com uma nova classe:
Novo ResultadoAluno.h 
```source.c++
class ResultadoAluno : public Aluno, public Media, public Frequencia {
public:
    ResultadoAluno(string nome, long double CPF, long double RA, int totalTarefas, int tarefasFeitas, int p1, int p2, int peso1, int peso2);//construtor
    virtual ~ResultadoAluno();//destrutor
    virtual void imprime(); //Essa funcao imprimira os resultados dos alunos. 
private: //os atributos foram declarados no privado como solicitado.
    string nome;
    long double CPF;
    long double RA;
    int totalTarefas;
    int tarefasFeitas;
    int p1;
    int p2;
    int peso1;
    int peso2;
};
```
E essa classe utiliza agora de suas "ferramentas" (subclasses) Media e Frequencia para calcular um resultado final. O código assim fica mais maleavel, permitindo com que adicionemos ou extendamos as ferramentas tranquilamente sem afetar o funcionamento de ResultadoAluno.  

### Descrição Arquitetural
Segue uma arquitetura que representa o código depois da aplicação dos principios SOLID:
![image](https://user-images.githubusercontent.com/60801559/143664686-63866f87-23d2-4187-990d-04c3bc5a3f87.png)


### Discussões
 Abaixo seguem discussões levantadas com base nos dois artigos abaixo: 
- Martin Fowler. Inversion of Control. martinfowler.com, 2005.
 https://martinfowler.com/bliki/InversionOfControl.html
- Martin Fowler. Inversion of Control Containers and the Dependency Injection pattern.
 martinfowler.com, 2004.
 https://martinfowler.com/articles/injection.html
 
### O que é o princípio da inversão de dependência?
O principío da inversao de dependencia foi apresentado nesse artigo como Dependency Inversion Principle (DIP). Como já mencionado esse principio defende que um módulo não deve depender diretamente de detalhes de implementação de outro modulo, na verdade deve existir uma abstração ali no meio para intermediar essa dependencia. 

### O que é  inversão de controle?
Inversão de controle é um comportamento que se faz presente especialmente quando usamos frameworks. Na inversão de controle os frameworks organizam por si só a coordenação e sequenciamento das atividades da aplicação. 

### O que é injeção de dependência?
A injeção de dependencia desacopla classes, evitando dependencia direta entre elas. 

### Qual a relação entre inversão de dependência, inversão de controle e injeção de dependência?
A injeção de dependencia é um tipo de inversão de controle, pois ela define que uma classe não é mais responsavel por buscar objetos da qual depende. Ao aplicarmos a injeção de dependencia estamos tambem seguindo o principío da inversão de dependencia, pois visamos reduzir o nível de acoplamento entre diferentes modulos de um sistema estaremos que é justamente o objetivo do DIP; 

