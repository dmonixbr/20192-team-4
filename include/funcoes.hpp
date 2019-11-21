#include <iostream>

extern void FormCadastroGerente();
extern void FormCadastroCreche();

/*-----------funcoes do crud e login inicial-------------------*/
/*  */
extern int CrudUsuario(); //OK
extern int AuxCrud(); //OK
extern int LoginAdmin();
extern int LoginGerente();
extern int LoginAux();

/*----------- Menu's administrador e gerente ------------------*/

extern void MenuPrincipal(int /*inteiro que a funcao CrudUsuario retorna para identificar qual menu ele esta;*/);
extern void MenuAdmin();
extern void MenuGerente();