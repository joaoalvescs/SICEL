void repetir(int n,int caractere)
{
	for(int i=0;i<n;i++)
	{
		printf("%c",caractere);
	}
}


void message()
{
	textcolor(TEXT);
	cout << "  Digite 0 para voltar a qualquer momento\n";
	
	textcolor(FRAME);
	
	printf("%c",CIE);
	repetir(59,BDH);
	printf("%c\n",CID);
	
	gotoxy(1,4);
	printf("%c",BDV);
	gotoxy(61,4);
	printf("%c",BDV);
	gotoxy(1,6);
	textcolor(TEXT);
}


char question()
{
	char ans;
	cout << "> Novamente? (S/N) ";
	ans = getch();
	return ans;
}


void header(string msg)
{
	system("cls");
	textcolor(FRAME);
	printf("%c",CSE);
	repetir(59,BDH);
	printf("%c\n%c",CSD,BDV);
	textcolor(TEXT);
	cout << msg;
	textcolor(FRAME);
	gotoxy(61,2);
	printf("%c",BDV);
	gotoxy(1,3);
	printf("%c",JTE);
	repetir(59,BDH);
	printf("%c\n",JTD);
}


void menu()
{
	header("\t\t\t SICEL 1.9");							
	textcolor(TEXT);
	printf("  0- Sair\n  1- Emprestimo de livro\n  2- Devolu%c%co de livro\n  3- Lista de alunos cadastrados\n  4- Lista de livros cadastrados\n  5- Lista de livros emprestados\n  6- Cadastrar livro\n  7- Cadastrar aluno\n",cced,atil);
	
	textcolor(FRAME);
	printf("%c",CIE);
	repetir(59,BDH);
	printf("%c\n>",CID);
	
	for(int i=0;i<8;i++)								
	{
		gotoxy(1,i+4);
		printf("%c",BDV);
		gotoxy(61,i+4);
		printf("%c",BDV);
	}
	gotoxy(4,13);
}


void emp_livro()
{
	string date = __DATE__;									
	char ans,
		aluno[STRSIZE],										
		livro[STRSIZE];										
	
	do
	{	
        ans = 'n';
		header("                         EMPRESTIMO");		
		message();											
		
		cout << "> Informe a matricula do aluno: ";				
		gets(aluno);										
		
		if(strcmp(aluno,"0")!=0)							
		{
			if(existe(ALUNO_PATH,1,aluno,""))				
			{
				cout << "> Informe o codigo do livro...: ";
				gets(livro);								
				
				if(strcmp(livro,"0")!=0)				
				{
					if(existe(LIVRO_PATH,1,livro,""))		
					{
						cadastrar(EMP_PATH,aluno,livro,date);
						cout << "> EMPRESTIMO CONCLUIDO!\n";
					}
					else									
					{
						textcolor(12);
						cout << "X Este livro nao esta cadastrado no sistema!\n";
						textcolor(TEXT);
					}
				}
				else										
				{
					menu();
				}		
			}
			else											
			{
				textcolor(12);
				cout << "X Este aluno nao esta cadastrado no sistema!\n";
				textcolor(TEXT);
			}
		}
		
		if((strcmp(aluno,"0")!=0)&&(strcmp(livro,"0")!=0))
		{
			ans = question();								
		}
	}
	while((ans == 'S')||(ans == 's'));						
}


void dev_livro()
{
	char aluno[STRSIZE],									
		livro[STRSIZE],										
		ans;
	
	do
	{
        ans = 'n';
		header("                          DEVOLUCÇO");		
		message();											
		
		cout << "> Informe a matricula do aluno: ";
		gets(aluno);										
		
		if(strcmp(aluno,"0")!=0)							
		{
			if(existe(EMP_PATH,1,aluno,""))				
			{
				cout << "> Informe o codigo do livro...: ";
				gets(livro);								
				
				if(strcmp(livro,"0")!=0)					
				{
					if(existe(EMP_PATH,3,aluno,livro))		
					{
						deletar(EMP_PATH,aluno,livro,3);	
						cout << "> DEVOLUCÇO CONCLUIDA!\n";
					}
					else								
					{
						textcolor(12);
						cout << "X Este livro nao foi emprestado a esse aluno!\n";
						textcolor(TEXT);
					}
				}
				else										
				{
					menu();
				}		
			}
			else											
			{
				textcolor(12);
				cout << "X Este aluno nao adquiriu nenhum livro!\n";
				textcolor(TEXT);
			}
		}
		
		if((strcmp(aluno,"0")!=0)&&(strcmp(livro,"0")!=0))	
		{
			ans = question();								
		}
	}
	while((ans == 'S')||(ans == 's'));					
}


void cad_livro()
{
	char cod[STRSIZE],										
		nome[STRSIZE],									
		ans;
	
	do
	{
        ans = 'n';
		header("                      CADASTRAR LIVRO");	
		message();											
		
		cout << "> Informe o codigo do livro: ";
		gets(cod);											
		
		if(strcmp(cod,"0")!=0)								
		{
			if(!existe(LIVRO_PATH,1,cod,""))				
			{
				cout << "> Informe o nome do livro..: ";
				gets(nome);									
				
				if(strcmp(nome,"0")!=0)						
				{
					cadastrar(LIVRO_PATH,cod,nome);			
					cout << "> CADASTRO CONCLUIDO!\n";
				}			
				else										
				{
					menu();
				}		
			}
			else											
			{
				textcolor(12);
				cout << "X Este livro ja esta cadastrado no sistema!\n";
				textcolor(TEXT);
			}
		}
		
		if((strcmp(cod,"0")!=0)&&(strcmp(nome,"0")!=0))		
		{
			ans = question();							
		}
	}
	while((ans == 'S')||(ans == 's'));						
}


void cad_aluno()
{
	char nome[STRSIZE],										
		mat[STRSIZE],										
		ans;
	
	do
	{
        ans = 'n';
		header("                      CADASTRAR ALUNO");
		message();											
		
		cout << "> Informe a matricula do aluno: ";
		gets(mat);											
		
		if(strcmp(mat,"0")!=0)								
		{
			if(!existe(ALUNO_PATH,1,mat,""))			
			{
				cout << "> Informe o nome do aluno.....: ";
				gets(nome);								
				
				if(strcmp(nome,"0")!=0)						
				{
					cadastrar(ALUNO_PATH,mat,nome);		
					cout << "> CADASTRO CONCLUIDO!\n";
				}			
				else										
				{
					menu();
				}		
			}
			else											
			{
				textcolor(12);
				cout << "X Este aluno ja esta cadastrado no sistema!\n";
				textcolor(TEXT);
			}
		}
		
		if((strcmp(mat,"0")!=0)&&(strcmp(nome,"0")!=0))		
		{
			ans = question();							
		}
	}
	while((ans == 'S')||(ans == 's'));					
}


void frm_lst(const string nome_arquivo,string texto,char* delete_code)
{
	int q = qtd_linhas(nome_arquivo);						
	string D1[q],D2[q],D3[q];							
	
	tabular(nome_arquivo,D1,D2,D3);						
	
	header(texto);										
	
	if(nome_arquivo == ALUNO_PATH)						
	{
		textcolor(FRAME);
		gotoxy(26,3);
		printf("%c",JTS);
		gotoxy(1,4);
		printf("%c       ",BDV);
		textcolor(TEXT);
		cout << "MATRICULA";
		textcolor(FRAME);
		printf("        %c               ",BDV);
		textcolor(TEXT);
		cout << "NOME";
		textcolor(FRAME);
		printf("               %c\n",BDV);
		 
		printf("%c",JTE);
		repetir(59,BDH);
		printf("%c\n",JTD);
		gotoxy(26,5);
		printf("%c",JCQ);
		gotoxy(1,6);
		
		for(int i=0;i<q;i++)
		{
			gotoxy(1,i+6);
			printf("%c",BDV);
			
			textcolor(TEXT);
			gotoxy(13-D1[i].length()/2,i+6);
			cout << D1[i];
			
			textcolor(FRAME);
			gotoxy(26,i+6);
			printf("%c",BDV);
			
			textcolor(TEXT);
			gotoxy(43-D2[i].length()/2,i+6);
			cout << D2[i];
			
			textcolor(FRAME);
			gotoxy(61,i+6);
			printf("%c",BDV);
		}
		
		gotoxy(1,6+q);
		printf("%c",CIE);
		repetir(59,BDH);
		printf("%c\n",CID);
		gotoxy(26,6+q);
		printf("%c",JTI);
		gotoxy(1,7+q);
		
		textcolor(TEXT);
		cout << "> Informe a matricula para deletar um aluno ou 0 para voltar: \n"
			 << "> ";
		gets(delete_code);								
	}
	else if(nome_arquivo == EMP_PATH)					
	{
		textcolor(FRAME);
		printf("%c ",BDV);
		textcolor(TEXT);
		cout << "MATRICULA DO ALUNO";
		textcolor(FRAME);
		printf(" %c ",BDV);
		textcolor(TEXT);
		cout << "CODIGO DO LIVRO";
		textcolor(FRAME);
		printf(" %c ",BDV);
		textcolor(TEXT);
		cout << "DATA DE EMPRESTIMO";
		textcolor(FRAME);
		printf(" %c \n",BDV);
		
		printf("%c",JTE);
		repetir(59,BDH);
		printf("%c\n",JTD);
		gotoxy(22,3);
		printf("%c",JTS);
		gotoxy(40,3);
		printf("%c",JTS);
		gotoxy(22,5);
		printf("%c",JCQ);
		gotoxy(40,5);
		printf("%c",JCQ);
		gotoxy(1,6);
		
		for(int i=0;i<q;i++)
		{
			gotoxy(1,i+6);
			printf("%c",BDV);
			
			textcolor(TEXT);
			gotoxy(12-D1[i].length()/2,i+6);
			cout << D1[i];
			
			textcolor(FRAME);
			gotoxy(22,i+6);
			printf("%c",BDV);
			
			textcolor(TEXT);
			gotoxy(32-D2[i].length()/2,i+6);
			cout << D2[i];
			
			textcolor(FRAME);
			gotoxy(40,i+6);
			printf("%c",BDV);
			
			textcolor(TEXT);
			gotoxy(51-D3[i].length()/2,i+6);
			cout << D3[i];
			
			textcolor(FRAME);
			gotoxy(61,i+6);
			printf("%c",BDV);
		}
		
		gotoxy(1,6+q);
		printf("%c",CIE);
		repetir(59,BDH);
		printf("%c\n",CID);
		gotoxy(22,6+q);
		printf("%c",JTI);
		gotoxy(40,6+q);
		printf("%c",JTI);
		gotoxy(1,7+q);
		
		textcolor(TEXT);
		system("pause");									
	}
	else													
	{
		textcolor(FRAME);
		printf("%c        ",BDV);
		textcolor(TEXT);
		cout << "CODIGO";
		textcolor(FRAME);
		printf("          %c              ",BDV);
		textcolor(TEXT);
		cout << "NOME";
		textcolor(FRAME);
		printf("                %c\n",BDV);

		printf("%c",JTE);
		repetir(59,BDH);
		printf("%c\n",JTD);
		gotoxy(26,3);
		printf("%c",JTS);
		gotoxy(26,5);
		printf("%c",JCQ);
		gotoxy(1,6);
		
		for(int i=0;i<q;i++)
		{
			gotoxy(1,i+6);
			printf("%c",BDV);
			
			textcolor(TEXT);
			gotoxy(13-D1[i].length()/2,i+6);
			cout << D1[i];
			
			textcolor(FRAME);
			gotoxy(26,i+6);
			printf("%c",BDV);
			
			textcolor(TEXT);
			gotoxy(43-D2[i].length()/2,i+6);
			cout << D2[i];
			
			textcolor(FRAME);
			gotoxy(61,i+6);
			printf("%c",BDV);
		}
		
		gotoxy(1,6+q);
		printf("%c",CIE);
		repetir(59,BDH);
		printf("%c\n",CID);
		gotoxy(26,6+q);
		printf("%c",JTI);
		gotoxy(1,7+q);
		
		textcolor(TEXT);
		cout << "> Informe o codigo para deletar um livro ou 0 para voltar: \n"
			 << "> ";
		gets(delete_code);								
	}
}
