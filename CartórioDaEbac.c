#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respos�vel pelas strings

int main()
    {
	int opcao=0; //definindo variaveis 
	int x=1;
	
	for(x=1; x=1;) //repeti��o
	{
	   
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	 
	   printf ("*** Cart�rio da EBAC ***\n\n"); //inicio do menu
	   printf ("Escolha a op��o desejada no menu:\n\n");
	   printf ("\t1 - Registrar nomes\n");
	   printf ("\t2 - Consultar nomes\n");
	   printf ("\t3 - Deletar nomes\n");  
	   printf ("\t4 - Sair do sistema\n:"); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	   system("cls");  
	   
	   switch(opcao)
	   {
	   	case 1:
	   	registro();
	   	break;
	   	   	
	   	case 2:
	   	consulta();
		break;
		
		case 3:
	    deletar();
		break;
				
	    default:
	    printf("Essa opc�o n�o est� disponivel!\n");
		system("pause");
		break;
		
		case 4:
		printf("At� a proxima!\n");
		return 0;
		break;
			
	   }
    }  
}


int registro()  //fun��o de cadastro
{
	//inicio da cria��o das vari�veis
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: "); //coleta dos informa��es do usu�rio
    scanf("%s", cpf);  //revisando arquivos da string
    
    strcpy(arquivo, cpf); //respons�vel por copiar o valor das strings
    
    FILE *file; // cria o arquivo no Banco de dados dentro do sistema
    file = fopen(arquivo, "w"); //cria  o arquivo definindo W como novo arquivo
    fprintf(file,cpf);  //salva dentro do arquivo a variavel de leitura principal sendo no caso CPF
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); // abre o arquivo o A em aspas e para atualizar e alterar o arquivo
    fprintf(file,", ");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
        
    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
	file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
        
    file = fopen(arquivo, "a");
    fprintf(file, ", ");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}


int consulta() // inicio da cria��o de variaveis para consulta dos usuarios cadastrados
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //informa que o usu�rio n�o existe
	{
		printf("Arquivo n�o existe!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}


int deletar() //inicio da variavel de exclusao dos usuarios j� cadastrados no Banco de dados
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
           
	 
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL) //se o arquivo nao existir ele vai executar o texto de usuario nao encontrado 
    {
    	system("cls"); // limpa a tela 
    	printf("\nUsu�rio n�o encontrado!\n");
    	system("pause");
	}
	else  // se ele existir o usuario ser� deletado!
	{
		remove(cpf);
		printf("Usuario deletado com sucesso!\n");
		system("pause");
		
	}
	
	fclose(file);
	
}


