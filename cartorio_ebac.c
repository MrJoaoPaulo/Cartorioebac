#include <stdio.h> 													//biblioteca de comunicação com o usuário.
#include <stdlib.h> 												//biblioteca de alocação de espaço em memória.
#include <locale.h> 												//biblioteca de alocações de texto por regiões.
#include <string.h>													//biblioteca responsável por cuidar das string.

int registro()												//FUNÇÃO REGISTRO.
{
	char arquivo[40];												//Criação de variáveis/string.
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");						//Coletando informação do usuário.
	scanf("%s",cpf);												//Pegando a informação coletada e salvando na string(%s) cpf.
	
	strcpy(arquivo, cpf);											//Responsável por copiar os valores das string "cpf" pro "arquivo".
	
	FILE *file;														//Cria o arquivo. Ta dizendo para acessar o arquivo "file" que vamos fazer algo nele.
	file = fopen(arquivo, "w");										//Cria um arquivo "w" (write), cujo nome será o que estiver na string "arquivo" (que é a cópia da string "cpf").
	fprintf(file,"CPF: ");											//Salva o texto "CPF: " no file.
	fprintf(file,cpf);												//Salva o valor da variável cpf no file.
	fclose(file);													//Fecha o arquivo.

	file = fopen(arquivo, "a");										//Atualiza "a" um arquivo já criado.
	fprintf(file,", ");												//Salva o texto ", " no file.
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");						//Coletando informação do usuário.
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");				//Coletando informação do usuário.
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");					//Coletando informação do usuário.
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fprintf(file,".");												//Salva o texto "." no file.
	fclose(file);
	
	printf("\n");													//Dando espaço por questão de estética.
	system("pause");												//Responsável por pausar o sistema.
	
}																	//Fim da função Registro

int consulta()												//FUNÇÃO CONSULTA.
{
	setlocale(LC_ALL, "portuguese");								//Definindo a linguagem.
	
	char cpf[40];													//Criação de variáveis/string.
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");						//Recebendo qual usuário vai ser consultado.
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");											//Lê “r” (read) o arquivo "cpf".
	
	if(file == NULL)												//Início da Função if.
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)							//Início da função while.
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	fclose(file);													//Fecha o arquivo.
	system("pause");												//Pausa do sistema.
}																	//Fim da função Consulta

int deletar()												//FUNÇÃO DELETAR.
{
	char cpf[40];													//Criação de variáveis/string.
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	
	FILE *file;														//Para acessar o arquivo "file".
	file = fopen(cpf,"r");											//Lê “r” (read) o arquivo "cpf".
	
	if(file == NULL)												//Início da Função if. Caso o usuário não esteja no sistema.
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else															//Caso o usuário esteja no sistema faça:
	{
		fclose(file);												//Fecha o arquivo.
		remove(cpf);												//Remove o arquivo.
		FILE *file;													//Para acessar o arquivo "file".
		file = fopen(cpf,"r");										//Lê “r” (read) o arquivo "cpf".
		
		if(file == NULL)											//Início da Função if. Caso o usuário não esteja mais no sistema.
		{
			printf("Usuário deletado com sucesso!.\n\n");
			system("pause");
		}
	}
	fclose(file);													//Fecha o arquivo cpf.
}																	//Fim da função Deletar

int main()													//FUNÇÃO PRINCIPAL.										
{
	setlocale(LC_ALL, "portuguese");								//Definindo idioma.
	
	int opcao=0;													//Definindo variáveis da int main.
	int laco=1; 													//Definindo variáveis da int main.
	
	char senhadigitada[]="a";										//String da senha digitada
	int comparacao;													//Variável para coparar a senha digitada com a senha correta.
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);										//Coleta da senha digitada
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)											//Início da Função senha digitada
	{
		system("cls");												//Responsável por limpar(cleanse) a tela.
		for(laco=1;laco=1;)										//Início do laço de repetição.
		{
			setlocale(LC_ALL, "Portuguese");						//Definindo idioma.
	
			printf("### Cartório da EBAC ###\n\n");					//Início do menu.
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");										//Fim do menu.
	
			scanf("%d", &opcao);									//Escolha do usuário.
	
			system("cls");											//Responsável por limpar(cleanse) a tela.
	
			switch(opcao)											//Início da seleção do menu. Variável estilo Switch.
			{
				case 1:
				registro();											//Chamada da função Registro.
				break;
			
				case 2:
				consulta();											//Chamada da função Consulta.
				break;
			
				case 3:
				deletar();											//Chamada da função Deletar.
				break;
			
				case 4:												//Função Sair do sistema.
				printf("Obrigado por utilizar o sistema!\n");
				return 0;											//"Retorna valor zero". ou seja, quebraça o laço, quebra a função, quebra tudo e sai do sistema.
				break;
			
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			}														//Fim da variável switch.
		}															//Fim do laço.
	}																//Fim da função if senha digitada.
	
	else
		printf("Senha incorreta!");									//else da função if senha digitada. Ocorrerá se a pessoa errar a senha.
	
}																//Fim do código.
