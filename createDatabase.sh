sqlite3 'creche.db' <<END_SQL


CREATE TABLE usuario(
	username VARCHAR UNIQUE,
	cpf CHAR(11),
	senha VARCHAR
)

CREATE TABLE admin(

)