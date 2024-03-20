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
	
	printf("\n");													//Dando espa�o por quest�o de est�tica.
	system("pause");												//Respons�vel por pausar o sistema.
	
}																	//Fim da fun��o Registro

int consulta()												//FUN��O CONSULTA.
{
	setlocale(LC_ALL, "portuguese");								//Definindo a linguagem.
	
	char cpf[40];													//Cria��o de vari�veis/string.
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");						//Recebendo qual usu�rio vai ser consultado.
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
	
	fclose(file);													//Fecha o arquivo.
	system("pause");												//Pausa do sistema.
}																	//Fim da fun��o Consulta

int deletar()												//FUN��O DELETAR.
{
	char cpf[40];													//Cria��o de vari�veis/string.
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	
	FILE *file;														//Para acessar o arquivo "file".
	file = fopen(cpf,"r");											//L� �r� (read) o arquivo "cpf".
	
	if(file == NULL)												//In�cio da Fun��o if. Caso o usu�rio n�o esteja no sistema.
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else															//Caso o usu�rio esteja no sistema fa�a:
	{
		fclose(file);												//Fecha o arquivo.
		remove(cpf);												//Remove o arquivo.
		FILE *file;													//Para acessar o arquivo "file".
		file = fopen(cpf,"r");										//L� �r� (read) o arquivo "cpf".
		
		if(file == NULL)											//In�cio da Fun��o if. Caso o usu�rio n�o esteja mais no sistema.
		{
			printf("Usu�rio deletado com sucesso!.\n\n");
			system("pause");
		}
	}
	fclose(file);													//Fecha o arquivo cpf.
}																	//Fim da fun��o Deletar

int main()													//FUN��O PRINCIPAL.										
{
	setlocale(LC_ALL, "portuguese");								//Definindo idioma.
	
	int opcao=0;													//Definindo vari�veis da int main.
	int laco=1; 													//Definindo vari�veis da int main.
	
	char senhadigitada[]="a";										//String da senha digitada
	int comparacao;													//Vari�vel para coparar a senha digitada com a senha correta.
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);										//Coleta da senha digitada
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)											//In�cio da Fun��o senha digitada
	{
		system("cls");												//Respons�vel por limpar(cleanse) a tela.
		for(laco=1;laco=1;)										//In�cio do la�o de repeti��o.
		{
			setlocale(LC_ALL, "Portuguese");						//Definindo idioma.
	
			printf("### Cart�rio da EBAC ###\n\n");					//In�cio do menu.
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: ");										//Fim do menu.
	
			scanf("%d", &opcao);									//Escolha do usu�rio.
	
			system("cls");											//Respons�vel por limpar(cleanse) a tela.
	
			switch(opcao)											//In�cio da sele��o do menu. Vari�vel estilo Switch.
			{
				case 1:
				registro();											//Chamada da fun��o Registro.
				break;
			
				case 2:
				consulta();											//Chamada da fun��o Consulta.
				break;
			
				case 3:
				deletar();											//Chamada da fun��o Deletar.
				break;
			
				case 4:												//Fun��o Sair do sistema.
				printf("Obrigado por utilizar o sistema!\n");
				return 0;											//"Retorna valor zero". ou seja, quebra�a o la�o, quebra a fun��o, quebra tudo e sai do sistema.
				break;
			
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			}														//Fim da vari�vel switch.
		}															//Fim do la�o.
	}																//Fim da fun��o if senha digitada.
	
	else
		printf("Senha incorreta!");									//else da fun��o if senha digitada. Ocorrer� se a pessoa errar a senha.
	
}																//Fim do c�digo.
