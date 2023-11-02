# **Computação Gráfica**
#### As atividades foram feitas em um ambiente Linux, na linguagem C++ e na IDE Visual Studio Code.
> ### ***Instruções de compilação***
> 1. Dentro do diretório do projeto *AtividadeXX*, crie um novo diretório chamado *build*;
> 2. No interior do diretório *build* abra um terminal e insira os comandos abaixo;
>    ```
>    cmake ../
>    ```
>    ```
>    make
>    ```
> 3. Para executar o programa, use o comando abaixo, ajustando o caminho relativo do arquivo executável.
>    ```
>    ./src/main
>    ```

> ### ***Documentação***
> A documentação completa e detalhada do código está no arquivo ***Documentation.html*** dentro do diretório de sua respectiva atividade.

## - **Atividade 01 (I/O de Imagens)**
Aqui, foram feitas operações para **configurar o ambiente** que será utilizado para toda a disciplina, assim como a implementação do código para a **geração de imagens**. O código pertinente a esta atividade está no arquivo ***Generator.h*** e as chamadas das funções está em ***main.cpp***.

> ### ***Configurações*** 
> Foi usado o **CMake** para a compilação e a organização de dependências. Além disso, as bibliotecas **CImg** e **libpng** foram instaladas e, depois, conectadas pelo arquivo *CMakeLists.txt*. Elas servem para a criação e manipulação de imagens em formatos diferentes (como *PNG*). Note que a biblioteca **CImg** necessita apenas da inserção do arquivo ***CImg.h*** dentro do projeto para que ela funcione, enquanto a **libpng** necessita de instalação dentro do ambiente.

> ### ***Geração de imagens***
> Foram geradas 3 imagens, um gradiente, um quadrado e um círculo. Elas estão no diretório *images*.
> - ***Gradiente:*** feito de modo similar ao tutorial com adaptações ao uso da biblioteca **CImg**;
> - ***Quadrado:*** a imagem é gerada a partir do tamanho do lado do quadrado e o tamanho da imagem apenas. 
> - ***Círculo:*** ele é criado a partir da informação do tamanho de seu raio e usa uma fórmula matemática para reconhecer se um pixel pertence ao círculo ou não.

## - **Atividade 02 (Operações Matriciais)**
Nesta Atividade, foram implementadas classes para vetores e matrizes, além de operações referentes a elas. Também foi configurado um ambiente para testes unitários. Note que não há uma função *main* explícita neste projeto, uma vez que o código é executado pelo ambiente de testes.

> ### ***Vetores e Matrizes***
> - Dentro do diretório ***include*** estão os *headers* com as definições das classes e implementações de funções *inline* de utilidade (o corpo das funções *inline* precisam estar nestes arquivos). No diretório ***src***, há os arquivos *.cpp* com a implementação das classes definidas nos *headers*. Os arquivos são relacionados por seus nomes, por exemplo, *vec2.hpp* é header de *vec2.cpp*.
> - Para vetores com 2, 3 e 4 dimensões foram criadas classes denominadas: vec2, vec3 e vec4, respectivamente. Assim como para matrizes 2x2, 3x3 e 4x4, cujas classes foram chamadas de mat2, mat3 e mat4, respectivamente.
> - Encontra-se nesses arquivos, também, código para operações pertinentes à essas classes como produto escalar, produto vetorial, multiplicação de matrizes, multiplicação entre matrizes e vetores, entre outras. Mais detalhes estão presentes na documentação e no código em si.

> ### ***Testes Unitários***
> A biblioteca escolhida foi o **GoogleTest**. A integração desse ambiente com o projeto foi feita através do *CMakeLists.txt*. Todos os testes estão no diretório ***tests*** e há um arquivo de teste para cada classe feita, ou seja, *vec2_tests.cpp* é referente à classe vec2, *vec3_tests.cpp* à classe vec3, e assim por diante. Por fim, o projeto é compilado do mesmo modo de como foi descrito [nas instruções de compilação](#instruções-de-compilação), contudo, para executar os testes, deve-se utilizar o comando ***./run_tests*** sob o diretório *build*.

## - **Atividade 03 (I/O de Malhas)**
Nesta Atividade, foi implementada a classe obj referente à leitura e ao armazenamento de malhas à partir de um arquivo em formato *.obj*. 

> ### ***Malhas***
> O *header* dessa classe está no diretório *include*, no arquivo *obj.hpp*, e a sua respectiva implementação está em *obj.cpp* dentro da pasta *src*. A classe obj tem apenas seu construtor, que recebe como parâmetro o nome do arquivo a ser armazenado, e alguns métodos auxiliares (usados na fase de teste) para a conversão dos dados armazenados de volta para *string*. Mais detalhes estão na documentação e no código em si.

> ### ***Testes Unitários***
> - Os testes seguem o mesmo padrão da [Atividade 02](#testes-unitários), porém há apenas um arquivo de teste *obj_tests.cpp*, onde são testadas as estrutura de dados (vértices geométricos, coordenadas de texturas, vértices normais e elementos de faces) utilizadas pela classe.
> - Foram feitos testes através da criação de um objeto da classe obj com os arquivos *.obj* do diretório *tests/mock_inputs*, e a posterior comparação entre os dados que foram armazenados no objeto e o que estava na sua entrada. 
> - Cada teste tem um nome e um arquivo de *mock_input* relacionado, por exemplo, *mock_inputs/v_test.obj* é atribuído ao teste *v_test* que é o teste para vértices geométricos. Mais detalhes estão na documentação e no código de teste em si.
> - Todos os arquivos de *mock_inputs* foram gerados com base em um arquivo *.obj* real chamado *cat.obj*, baixado do site [free3d](https://free3d.com/). Ele está dentro do diretório *input*.

## - **Atividade 04 (Visualização Inicial)**
Nesta Atividade, foram implementadas a visualização de esferas, a de triângulos e a de objetos formados por faces triangulares. Algumas classes foram adicionadas, enquanto outras classes, como vec3, foram reutilizadas de atividades anteriores.

> ### ***Esferas***
> - Nessa seção, o [tutorial 1](https://raytracing.github.io/books/RayTracingInOneWeekend.html#rays,asimplecamera,andbackground) foi seguido para a criação da classe **ray** e a visualização de uma imagem de uma esfera. Para a organização do código, foi criada uma classe base **hittable** que é herdada pela classe **sphere**. Na classe **sphere**, temos a implementação da lógica por trás da checagem de que um ray está atravessando a esfera ou não. 
> - Além disso, foi criada uma classe **renderer** que irá traçar os rays referentes a cada pixel e desenhar sua cor, considerando se o ray acerta ou não a esfera. Mais detalhes estão na documentação e no código em si.
> - A organização dos arquivos segue assim como na atividade anterior, por exemplo, o *header* da classe renderer está no arquivo *renderer.hpp* no diretório *include* e o corpo do código está no arquivo *renderer.cpp* sob o diretório *src*. Contudo, algumas classes foram implementadas totalmente em seus *headers* por serem simples, o que pode ser visto na classe sphere que tem apenas seu *header* *sphere.hpp*.

> ### ***Triângulos***
> - Nessa parte, o [tutorial 2](https://raytracing.github.io/books/RayTracingTheNextWeek.html#quadrilaterals/ray-planeintersection) foi usado de inspiração para a criação da classe **triangle** que representa um triângulo no espaço tridimensional. A implementação do código e a distribuição dos arquivos segue o mesmo padrão utilizado para a classe sphere.

> ### ***Renderer***
> - A classe **renderer** é a responsável por renderizar as imagens e é chamada diretamente pela *main*. Ela possui métodos para cada tipo de imagem vista nesta atividade. Para mais detalhes, veja a documentação e o código.

> ### ***Objetos***
> - Por fim, 2 arquivos do formato *.obj* foram baixados da internet para servirem de teste na visualização de objetos reais. Um se chama [cat.obj](https://free3d.com/pt/3d-model/low-poly-cat-46138.html) e outro [icosahedron.obj](https://github.com/angerangel/LCR3D/blob/master/3D-models/icosahedron.obj) e estão no diretório *input*. Ambos possuem apenas faces triangulares, uma vez que não foi implementado suporte para quadriláteros. Foram escolhidos dois objetos para testes, pois um deles (icosahedron) é mais fácil de observar, e o outro (cat) possui geometria mais complexa e mais difícil de visualizar sem o uso de normais.

> ### ***Execução do programa e saídas***
> A compilação e execução do programa segue exatamente igual à [atividade 01](#instruções-de-compilação) e as saídas estão no diretório *images*, sendo que cada imagem é referente a um dos objetos feitos nesta atividade (veja o arquivo *main.cpp* para mais detalhes).