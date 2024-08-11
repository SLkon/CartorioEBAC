#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória 
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca resposável pelas strings

int main()
    {
	int opcao=0; //definindo variaveis 
	int x=1;
	
	for(x=1; x=1;) //repetição
	{
	   
	   system("cls");
	
	   setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	 
	   printf ("*** Cartório da EBAC ***\n\n"); //inicio do menu
	   printf ("Escolha a opção desejada no menu:\n\n");
	   printf ("\t1 - Registrar nomes\n");
	   printf ("\t2 - Consultar nomes\n");
	   printf ("\t3 - Deletar nomes\n");  
	   printf ("\t4 - Sair do sistema\n:"); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usuário
	
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
	    printf("Essa opcão não está disponivel!\n");
		system("pause");
		break;
		
		case 4:
		printf("Até a proxima!\n");
		return 0;
		break;
			
	   }
    }  
}


int registro()  //função de cadastro
{
	//inicio da criação das variáveis
    char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: "); //coleta dos informações do usuário
    scanf("%s", cpf);  //revisando arquivos da string
    
    strcpy(arquivo, cpf); //responsável por copiar o valor das strings
    
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


int consulta() // inicio da criação de variaveis para consulta dos usuarios cadastrados
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //informa que o usuário não existe
	{
		printf("Arquivo não existe!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}


int deletar() //inicio da variavel de exclusao dos usuarios já cadastrados no Banco de dados
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
           
	 
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL) //se o arquivo nao existir ele vai executar o texto de usuario nao encontrado 
    {
    	system("cls"); // limpa a tela 
    	printf("\nUsuário não encontrado!\n");
    	system("pause");
	}
	else  // se ele existir o usuario será deletado!
	{
		remove(cpf);
		printf("Usuario deletado com sucesso!\n");
		system("pause");
		
	}
	
	fclose(file);
	
}


