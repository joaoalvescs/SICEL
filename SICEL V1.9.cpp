#include <direct.h>
#include <locale.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.c>

using namespace std;

#include "lib\constantes.h"
#include "lib\arquivos.h"
#include "lib\dados.h"
#include "lib\menu.h"

main()
{
	char opc,
         cod[STRSIZE];

	mkdir("data");

	if(!checar_arq(ALUNO_PATH))
		criar_arq(ALUNO_PATH);

	if(!checar_arq(LIVRO_PATH))
		criar_arq(LIVRO_PATH);

	if(!checar_arq(EMP_PATH))
		criar_arq(EMP_PATH);

	// textbackground(15);
	clrscr();

	do
	{
		menu();
		opc = getch();

		switch(opc)
		{
			case '1':
				emp_livro();
				break;
			case '2':
				dev_livro();
				break;
			case '3':
				do
				{
					frm_lst(ALUNO_PATH,"\t\t\tLISTA DE ALUNOS",cod);
					if(strcmp(cod,"0")!=0)
					{
						deletar(ALUNO_PATH,cod,NULL,1);
						deletar(EMP_PATH,cod,NULL,1);
					}
				}
				while(strcmp(cod,"0")!=0);
				break;
			case '4':
				do
				{
					frm_lst(LIVRO_PATH,"\t\t\tLISTA DE LIVROS",cod);
					if(strcmp(cod,"0")!=0)
					{
						deletar(LIVRO_PATH,cod,NULL,1);
						deletar(EMP_PATH,cod,NULL,2);
					}
				}
				while(strcmp(cod,"0")!=0);
				break;
			case '5':
				frm_lst(EMP_PATH,"\t\t  LISTA DE EMPRESTIMOS",NULL);
				break;
			case '6':
				cad_livro();
				break;
			case '7':
				cad_aluno();
				break;
		}
	}
	while(opc!='0');
}
