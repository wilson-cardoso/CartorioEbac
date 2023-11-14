#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de testo por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // copia os valores da string(cpf para arquivo)
	
	FILE *file; //criando arquivo
	file = fopen(arquivo, "w"); //("w") criando arquivo novo (write)
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a"); // ("a") atualizar o arquivo e nao criar um novo 
	fprintf(file,"\t"); // colocando uma virgula no final do arquivo 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\t"); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\t");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
		
	system("pause");
		
}

int consluta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a se consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //(r) ler o arquivo
	
	if(file == NULL) //
	{
		printf("N�o foi possivel encontrar o arquivo!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //(fgets) vai buscar o arquivo, busca o conte�do, tamanho m�ximo � (200) busca no arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("digita o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", cpf);
		printf("\n\n");
	}
	
	if(file==NULL)
	{
		printf("Usu�rio nao encontrado no sistema! \n");
		system("pause");
	}
	
}

int main() 
{
		int opcao=0; //definindo as vari�veis
		int x=1;
	
		for(x=1;x=1;)
	{
			
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem da escrita
	
		printf("\n### Cart�rio da EBAC ###\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes \n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d",&opcao); // armazenando a escolha 
	
		system("cls");
		
		switch(opcao)
		{
		
			case 1:
				registro();
				break;
			
			case 2:
				consluta();
				break;
				
			case 3:
				deletar();
				break;
			
			default:
				printf("\nEsta op��o n�o est� disponivel\n");
				system("pause");
				break;
		}
	}

}
