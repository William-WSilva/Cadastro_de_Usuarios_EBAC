#include <stdio.h> // Biblioteca de comunica��o com usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pela cria��o de strings

// Fun��es
int Cadastrar() // Fun��o respons�vel por cadastrar usu�rios no sistema
{
	// Vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// Criar um arquivo novo, renomea-lo e registrar informa��es 
	printf("Digite o CPF a ser cadastrado *(sem espa�os): ");  // Coletando informa��es digitadas pelo usu�rio
	scanf("%s", cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // Copia o valor da vari�vel CPF para a vari�vel Arquivo
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e posiciona em modo escrever:"w"
		
		fprintf(file,cpf); // cadastra o valor da vari�vel cpf no arquivo
		fclose(file); // fecha o arquivo

			file = fopen(arquivo, "a"); // Cadastrar sinal de virgula antes do pr�ximo registro
			fprintf(file,", ");
			fclose(file);
	
	printf("Digite o nome a ser cadastrado *(sem espa�os): ");
	scanf("%s", nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
			file = fopen(arquivo, "a");
			fprintf(file,", ");
			fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado *(sem espa�os): ");
	scanf("%s", sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
			file = fopen(arquivo, "a");
			fprintf(file,", ");
			fclose(file);
	
	printf("Digite o cargo a ser cadastrado *(sem espa�os): ");
	scanf("%s", cargo);
	
			file = fopen(arquivo, "a");
			fprintf(file,cargo);
			fclose(file);
	
	system("pause");
	// fim do cadastro de usu�rio
	
}


int Consultar() // Fun��o respons�vel por consultar usu�rios no sistema
{
	// Definindo Linguagem
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// Vari�veis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��es digitadas pelo usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abrir o arquivo com o nome igual ao CPF
	
	if(file == NULL) // Consultar se o arquivo existe
	{
		printf("\n\n !!! N�o foi poss�vel abrir o arquivo, n�o foi localizado !!!.\n\n");
	}
	
	while( fgets(conteudo, 200, file) != NULL ) // Enquanto existir at� 200 caracteres dentro do arquivo, continua em loop.
	{
		printf("\n\n Estas s�o as informa��es do usu�rio: " );
		printf("%s", conteudo); // Grava os valores capturados dentro da vari�vel conteudo
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}


int Deletar() // Fun��o respons�vel por deletar usu�rios no sistema
{
	// Vari�veis
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");  // Coletando informa��es digitadas pelo usu�rio
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r"); // Abrir o arquivo com o nome igual ao CPF
	fclose(file);	
	
	if(file != NULL) // Consultar se o arquivo existe
	{
		remove(cpf); // Deletar o arquivo
		printf("\nO usu�rio foi deletado com sucesso!\n\n");
		system("pause");
	}
	else
	{
		printf("\nAten��o !!!, O usu�rio n�o foi encontrado no sistema!.\n\n");
		system("pause");
	}
}


// Tela Inicial
int main()
{
	// Vari�veis
	int opcao=0;
	int laco=1;
	char senhadigitada[]="a";
	int Senha_Check;
	
	// Definindo Linguagem
	setlocale(LC_ALL, "Portuguese");
	
	printf("<<<   Cadastro de usu�rios da EBAC   >>>\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	Senha_Check = strcmp(senhadigitada, "admin"); // strcmp: compara 2 strings, caso a=a resultado � 0
	
	if( Senha_Check == 0 )
	{
		for(laco=1; laco=1;)
		{
			system("cls"); // Limpar o conte�do da tela no sistema
		
			// Definindo Linguagem
			setlocale(LC_ALL, "Portuguese");
		
			// Inicio do Menu
			printf("<<<   Cadastro de usu�rios da EBAC   >>>\n\n");
			printf(" Escolha a op��o desejada no menu abaixo:\n\n");
				
			// Menu op��es
			printf("\tMenu:\n");
			printf("\t1 - Cadastrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("\tDigite uma op��o do menu:");
		
			scanf("%d", &opcao); // Capturar escolha do usu�rio
			system("cls"); // Limpar tela
			
			// 	Capturar op��o do menu escolhida pelo usu�rio
			switch(opcao)
			{
				case 1:
				Cadastrar();
				break;
				
				case 2:
				Consultar();
				break;
				
				case 3:
				Deletar();
				break;
				
				case 4:
				printf("Obrigado por ultilizar o sistema \n");
				return 0;
				break;
				
				default:
				printf("\t!!! Op��o n�o est� dispon�vel !!!\n");
				system("pause");
				break;
			}
		}
	}
	
	else
		printf("Senha incorreta!"); 
}



