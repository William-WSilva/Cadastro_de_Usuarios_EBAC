#include <stdio.h> // Biblioteca de comunicação com usuário
#include <stdlib.h> // Biblioteca de alocação de memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pela criação de strings

// Funções
int Cadastrar() // Função responsável por cadastrar usuários no sistema
{
	// Variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	// Criar um arquivo novo, renomea-lo e registrar informações 
	printf("Digite o CPF a ser cadastrado *(sem espaços): ");  // Coletando informações digitadas pelo usuário
	scanf("%s", cpf); // %s refere-se a strings
	
	strcpy(arquivo, cpf); // Copia o valor da variável CPF para a variável Arquivo
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e posiciona em modo escrever:"w"
		
		fprintf(file,cpf); // cadastra o valor da variável cpf no arquivo
		fclose(file); // fecha o arquivo

			file = fopen(arquivo, "a"); // Cadastrar sinal de virgula antes do próximo registro
			fprintf(file,", ");
			fclose(file);
	
	printf("Digite o nome a ser cadastrado *(sem espaços): ");
	scanf("%s", nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
			file = fopen(arquivo, "a");
			fprintf(file,", ");
			fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado *(sem espaços): ");
	scanf("%s", sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
			file = fopen(arquivo, "a");
			fprintf(file,", ");
			fclose(file);
	
	printf("Digite o cargo a ser cadastrado *(sem espaços): ");
	scanf("%s", cargo);
	
			file = fopen(arquivo, "a");
			fprintf(file,cargo);
			fclose(file);
	
	system("pause");
	// fim do cadastro de usuário
	
}


int Consultar() // Função responsável por consultar usuários no sistema
{
	// Definindo Linguagem
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	// Variáveis
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Coletando informações digitadas pelo usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Abrir o arquivo com o nome igual ao CPF
	
	if(file == NULL) // Consultar se o arquivo existe
	{
		printf("\n\n !!! Não foi possível abrir o arquivo, não foi localizado !!!.\n\n");
	}
	
	while( fgets(conteudo, 200, file) != NULL ) // Enquanto existir até 200 caracteres dentro do arquivo, continua em loop.
	{
		printf("\n\n Estas são as informações do usuário: " );
		printf("%s", conteudo); // Grava os valores capturados dentro da variável conteudo
		printf("\n\n");
	}
	fclose(file);
	system("pause");
}


int Deletar() // Função responsável por deletar usuários no sistema
{
	// Variáveis
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");  // Coletando informações digitadas pelo usuário
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf,"r"); // Abrir o arquivo com o nome igual ao CPF
	fclose(file);	
	
	if(file != NULL) // Consultar se o arquivo existe
	{
		remove(cpf); // Deletar o arquivo
		printf("\nO usuário foi deletado com sucesso!\n\n");
		system("pause");
	}
	else
	{
		printf("\nAtenção !!!, O usuário não foi encontrado no sistema!.\n\n");
		system("pause");
	}
}


// Tela Inicial
int main()
{
	// Variáveis
	int opcao=0;
	int laco=1;
	char senhadigitada[]="a";
	int Senha_Check;
	
	// Definindo Linguagem
	setlocale(LC_ALL, "Portuguese");
	
	printf("<<<   Cadastro de usuários da EBAC   >>>\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	Senha_Check = strcmp(senhadigitada, "admin"); // strcmp: compara 2 strings, caso a=a resultado é 0
	
	if( Senha_Check == 0 )
	{
		for(laco=1; laco=1;)
		{
			system("cls"); // Limpar o conteúdo da tela no sistema
		
			// Definindo Linguagem
			setlocale(LC_ALL, "Portuguese");
		
			// Inicio do Menu
			printf("<<<   Cadastro de usuários da EBAC   >>>\n\n");
			printf(" Escolha a opção desejada no menu abaixo:\n\n");
				
			// Menu opções
			printf("\tMenu:\n");
			printf("\t1 - Cadastrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("\tDigite uma opção do menu:");
		
			scanf("%d", &opcao); // Capturar escolha do usuário
			system("cls"); // Limpar tela
			
			// 	Capturar opção do menu escolhida pelo usuário
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
				printf("\t!!! Opção não está disponível !!!\n");
				system("pause");
				break;
			}
		}
	}
	
	else
		printf("Senha incorreta!"); 
}



