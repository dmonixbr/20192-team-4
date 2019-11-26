<p align="center">
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c3/Logo_UFMG.png/320px-Logo_UFMG.png" alt="alt text" width="210" height="82">
</p>


<p align="center"> <h1> Sistema de Gerenciamento Financeiro de Creches </h1> </p>

| [Introdução](#introdução) | [Integrantes](#integrantes) | [User Stories](#user-stories) | [Cartões CRC](#cartões-crc) | [Documentação](#documentação) | [Como executar](#como-executar) 
| - | - | - | - | - | - |


### Introdução

Esse trabalho é a consolidação de todo aprendizado na matéria de Programação e Desenvolvimento de Software II, ao longo do segundo semestre de 2019. Conceitos de orientação a objetos, como encapsulamento, herança e polimorfismo foram aplicados ao projeto, assim como, makefile, programação defensiva.
    A motivação do trabalho, nasce da necessidade de um familiar de um dos integrantes do grupo, que é responsável por avaliar dados de creches de Belo Horizonte e com base neles, prever o orçamento do próximo ano que deve ser destinado pela Prefeitura de Belo Horizonte a creche.
    O sistema desenvolvido, consiste em um programa onde seja possível gerar relatório anual com a previsão do orçamento previsto para o próximo ano para a creche com base nos dados inseridos.



### Integrantes
- Daniel Neiva
- Gabriel Torres
- Mariana Quintão 
- Victor Vieira 
- Vinicius Rodrigues

> Professor: Júlio César



### User Stories

<ul>

<li>Como administrador, quero poder cadastrar uma creche para poder gerenciar o financeiro desta creche.</li>


<li>Como administrador, quero poder ver os dados de uma creche para saber quais as informações institucionais e administrativos desta creche.</li>


<li>Como administrador, quero poder editar os dados básicos de uma creche para poder manter os dados do meu sistema sempre atualizados.</li>


<li>Como administrador, quero poder deletar uma creche para poder tirar os dados de escolas que não administro mais do meu sistema.</li>


<li>Como administrador, quero poder cadastrar um gerente de creche para dar acesso ao sistema a uma pessoa responsável pela creche.</li>


<li>Como gerente da creche, quero poder enviar relatórios financeiros trimestrais da minha creche, para que seja possível formalizar os dados fiscais da minha creche perante o governo.</li>


<li>Como administrador, quero poder escolher entre gerar relatórios anuais ou trimestrais de uma creche específica, para que eu possa pensar no orçamento desta creche.</li>


<li>Como usuário, quero poder fazer login para ter acesso às funções delimitadas ao meu papel.</li>
</ul>

### Cartões CRC

#### Classe: Usuario

|Responsabilidades|Colaboração|
| - | - |
|Saber seu nome|
|Saber seu cpf|
|Saber sua senha|
|Editar seus dados|
|Mostrar seu dados|

#### Classe: Administrador

|Responsabilidades| Colaboração|
| - | - |
|Saber seu nome | Usuario |
|Saber seu cpf |
|Saber sua senha |
|Cadastrar uma creche|
|Editar dados de creche |
|Deletar uma creche |
|Cadastrar um gerente |
|Gerar relatório Anual |
|Cadastrar Gerente |
|Mostrar lista de creches |
|Mostrar lista de admins |
|Editar seus dados |
|Fazer login |
|Deslogar |

#### Classe: Gerente

|Responsabilidades| Colaboração |
| - | - |
|Saber seu nome| Usuario|
|Saber seu cpf|
|Saber sua senha|
|Saber o periodo de mandato do gerente|
|Saber o seu endereço|
|Saber o seu telefone|
|Emitir relatorio|
|Editar dados da sua creche|
|Ver os dados da sua creche|
|Fazer login|
|Deslogar|


#### Classe: Creche

|Responsabilidades | Colaboração |
| - | - |
|Saber seu nome |
|Saber seu telefone|
|Saber seu endereço|
|Saber a validade do convenio|
|Saber a quantidade de turmas|
|Saber a quantidade de professores|
|Saber a quantidade de coordenadores|
|Saber a quantidade de auxiliares de berçario|
|Saber a quantidade de alunos|
|Saber o valor per capta de aluno|
|Saber o valor de manutenção|
|Saber a faixa etária média|
|Saber qual o gerente responsável pela creche|

#### Classe: MenuFunc

|Responsabilidades|Colaboração|
| - | - |
|Criar menu para usuario selecionar a função que ele deseja|


### Documentação
Clique [aqui](https://github.com/pds2/20192-team-4/blob/master/Documenta%C3%A7%C3%A3o/Documenta%C3%A7%C3%A3o%20TP%20-%20PDS%20II.pdf) para acessar o pdf com a documentação do programa

### Como executar

- Com o terminal aberto no caminho da pasta do programa, execute:
    > make run
    
- Selecione a opção 1 e faça o login com os dados do administrador supremo.
    > cpf: 000
    > senha: super
    
- Comandos do programa:
    > make run: executa o programa.<br>
    > make tests: executa o script de teste do programa.

 




