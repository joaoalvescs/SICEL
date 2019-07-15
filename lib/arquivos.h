bool checar_arq(const string nome_arquivo)
{
	ifstream arquivo(nome_arquivo.c_str()); 		
	arquivo.close();								
	if(arquivo)										
		return true;								
	else
		return false;								
}


void criar_arq(const string nome_arquivo)
{
	ofstream arquivo(nome_arquivo.c_str());			
	arquivo.close();								
}


void escrever(const string nome_arquivo,string dados)
{
	ofstream arquivo(nome_arquivo.c_str()); 		
	for(int i=0;i < dados.length();i++)				
		arquivo.put(dados[i]);						
	arquivo.close();								
}


string ler(const string nome_arquivo)
{
	ifstream arquivo(nome_arquivo.c_str()); 		
	string conteudo = "";							
	char c;					
	
	while(arquivo.get(c))							
		conteudo += c;								
		
	arquivo.close();								
		
	return conteudo;								
}
