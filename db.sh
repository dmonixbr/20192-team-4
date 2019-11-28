#!/bin/sh
sqlite3 'creche.db' <<END_SQL

CREATE TABLE admin(
	id int NOT NULL,
	cpf varchar(11),
	nome varchar(120),
	senha varchar(50),
	PRIMARY KEY (id)
);

CREATE TABLE gerente(
	id int NOT NULL,
	cpf varchar(11),
	nome varchar(120),
	senha varchar(50),
	endereco varchar(180),
	telefone varchar(50),
	periodo_mandato varchar(50),
	PRIMARY KEY (id)
);

CREATE TABLE creche(
	id int NOT NULL,
	nome varchar(120),
	endereco varchar(180),
	telefone varchar(50),
	validade_convenio varchar(50),
	id_gerente int,
	numero_turmas int,
	numero_professores int,
	numero_coordenadores int,
	numero_auxbercario int,
	numero_alunos int,
	valor_pc float,
	valor_manutencao float,
	faixa_etaria float,
	PRIMARY KEY (id)
);
