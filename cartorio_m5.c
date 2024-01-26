#include <stdio.h> 													//biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> 												//biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> 												//biblioteca de aloca��es de texto por regi�es.
#include <string.h>													//biblioteca respons�vel por cuidar das string.

int registro()												//FUN��O REGISTRO.
{
	char arquivo[40];												//Cria��o de vari�veis/string.
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");						//Coletando informa��o do usu�rio.
	scanf("%s",cpf);												//Pegando a informa��o coletada e salvando na string(%s) cpf.
	
	strcpy(arquivo, cpf);											//Respons�vel por copiar os valores das string "cpf" pro "arquivo".
	
	FILE *file;														//Cria o arquivo. Ta dizendo para acessar o arquivo "file" que vamos fazer algo nele.
	file = fopen(arquivo, "w");										//Cria um arquivo "w" (write), cujo nome ser� o que estiver na string "arquivo" (que � a c�pia da string "cpf").
	fprintf(file,"CPF: ");											//Salva o texto "CPF: " no file.
	fprintf(file,cpf);												//Salva o valor da vari�vel cpf no file.
	fclose(file);													//Fecha o arquivo.

	file = fopen(arquivo, "a");										//Atualiza "a" um arquivo j� criado.
	fprintf(file,", ");												//Salva o texto ", " no file.
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");						//Coletando informa��o do usu�rio.
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");				//Coletando informa��o do usu�rio.
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");					//Coletando informa��o do usu�rio.
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fprintf(file,".");												//Salva o texto "." no file.
	fclose(file);
	
	system("pause");												//Respons�vel por pausar o sistema.
	
}

int consulta()												//FUN��O CONSULTA.
{
	setlocale(LC_ALL, "portuguese");								//Definindo a linguagem.
	
	char cpf[40];													//Cria��o de vari�veis/string.
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");											//L� �r� (read) o arquivo "cpf".
	
	if(file == NULL)												//In�cio da Fun��o if.
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)							//In�cio da fun��o while.
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	system("pause");												//Pausa do sistema.
}

int deletar()												//FUN��O DELETAR.
{
	char cpf[40];													//Cria��o de vari�veis/string.
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);													//Remove o arquivo.
	
	FILE *file;
	file = fopen(cpf,"r");											//L� �r� (read) o arquivo "cpf".
	
	if(file == NULL)												//In�cio da Fun��o if.
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");		//O usu�rio n�o est� no sistema.
		system("pause");
	}
}


int main()													//FUN��O PRINCIPAL.										
{
	int opcao=0;													//Definindo vari�veis da int main.
	int laco=1; 													//Definindo vari�veis da int main.
	
	for (laco=1;laco=1;)											//In�cio do la�o de repeti��o.
	{
		system("cls");												//Respons�vel por limpar(cleanse) a tela.
		
		setlocale(LC_ALL, "portuguese");							//Definindo idioma.
	
		printf("### Cart�rio da EBAC ###\n\n");						//In�cio do menu.
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t 1 - Registrar nomes\n");
		printf("\t 2 - Consultar nomes\n");
		printf("\t 3 - Deletar nomes\n\n");
		printf("Op��o: ");											//Fim do menu.
	
		scanf("%d", &opcao);										//Escolha do usu�rio.
	
		system("cls");												//Respons�vel por limpar(cleanse) a tela.
	
	
		switch(opcao)												//In�cio da sele��o do menu. Vari�vel estilo Switch.
		{
			case 1:
			registro();												//Chamada da fun��o Registro.
			break;
			
			case 2:
			consulta();												//Chamada da fun��o Consulta.
			break;
			
			case 3:
			deletar();												//Chamada da fun��o Deletar.
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			
		}															//Fim da vari�vel switch.
	}																//Fim do la�o.
}																	//Fim do c�digo.
