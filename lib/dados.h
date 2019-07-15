void cadastrar(const string nome_arquivo,string d1,string d2,string d3)
{
	string conteudo = ler(nome_arquivo);							 
	escrever(nome_arquivo,conteudo + d1 + ","  + d2 + "," + d3 + ";");
}


void cadastrar(const string nome_arquivo,string d1,string d2)
{
	string conteudo = ler(nome_arquivo);								
	escrever(nome_arquivo,conteudo + d1 + ","  + d2 + ";");				
}


void tabular(const string nome_arquivo,string d1[],string d2[],string d3[])
{
	string conteudo = ler(nome_arquivo);							
	int	l = 0,															
		c = 0;															
	
	for(int i=0;i<conteudo.length();i++)								
	{
		if(conteudo[i]==',')										
		{
			c++;
		}
		else if(conteudo[i]==';')										
		{			
			c = 0;
			l++;
		}		
		else															
		{
			switch(c)
			{
				case 0:
					d1[l].append(1,conteudo[i]);						
					break;
				case 1:
					d2[l].append(1,conteudo[i]);						
					break;
				case 2:
					d3[l].append(1,conteudo[i]);						
					break;
			}
		}
	}
}


int qtd_linhas(const string nome_arquivo)
{
	string conteudo = ler(nome_arquivo);							
	int linhas = 0;														
	
	for(int i=0;i<conteudo.length();i++)								
	{
		if(conteudo[i]==';')										
			linhas++;	
	}
	return linhas;														
}


bool existe(const string nome_arquivo,int coluna,string valor,string valor2)
{
	int q = qtd_linhas(nome_arquivo);									
	string D1[q],D2[q],D3[q];											
	tabular(nome_arquivo,D1,D2,D3);										
	bool retorno;								

	switch(coluna)
	{
		case 1:
			for(int i=0;i<q;i++)										
			{
				if(D1[i]==valor)										
				{
					retorno = true;
					break;
				}
				else
					retorno = false;		
			}
			break;
		case 2:
			for(int i=0;i<q;i++)										
			{
				if(D2[i]==valor)										
				{
					retorno = true;
					break;
				}
				else
					retorno = false;	
			}
			break;
		case 3:
			for(int i=0;i<q;i++)										
			{
				if((D1[i]==valor)&&(D2[i]==valor2))					
				{
					retorno = true;
					break;
				}

				else
					retorno = false;
			}
			
			break;
	}

	return retorno;
}


void deletar(const string nome_arquivo,char cod1[],char cod2[],int tipo)
{
	int q = qtd_linhas(nome_arquivo);									
	string D1[q],D2[q],D3[q],											
		saida = "";
	
	if((nome_arquivo == EMP_PATH)&&(tipo == 3))							
	{
		tabular(nome_arquivo,D1,D2,D3);									
		
		for(int i=0;i<q;i++)											
		{
			if((D1[i]!=cod1)||(D2[i]!=cod2))						
				saida += D1[i] + "," + D2[i] + "," + D3[i] + ";";
		}
	}
	else if(tipo == 1)
	{	
		if(nome_arquivo == EMP_PATH)
		{
			tabular(nome_arquivo,D1,D2,D3);									
			
			for(int i=0;i<q;i++)											
			{
				if(D1[i]!=cod1)												
					saida += D1[i] + "," + D2[i] + "," + D3[i] + ";";
			}
		}
		else
		{
			tabular(nome_arquivo,D1,D2,NULL);							
			
			for(int i=0;i<q;i++)										
			{
				if(D1[i]!=cod1)												
					saida += D1[i] + "," + D2[i] + ";";
			}
		}
	}
	else if(tipo == 2)
	{
		if(nome_arquivo == EMP_PATH)
		{
			tabular(nome_arquivo,D1,D2,D3);								
			
			for(int i=0;i<q;i++)										
			{
				if(D2[i]!=cod1)												
					saida += D1[i] + "," + D2[i] + "," + D3[i] + ";";
			}
		}
		else
		{
			tabular(nome_arquivo,D1,D2,NULL);							
			
			for(int i=0;i<q;i++)											
			{
				if(D2[i]!=cod1)												
					saida += D1[i] + "," + D2[i] + ";";
			}
		}
		
	}
	
	escrever(nome_arquivo,saida);										
}
