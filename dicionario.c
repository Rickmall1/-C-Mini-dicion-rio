#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

// Registro para objeto dicionario;
typedef struct
{
	char palavra[21];
	char definicao[51];
} dicionario;

// Ferramenta para comparação de strings;
bool comparaStr(char str1[], char str2[]){
	int  i = 0;
	while((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'))
	{
		i++;
	}

	if(str1[i] == '\0' && str2[i] == '\0')
		return true;

	else
		return false;
}

// Função que percorre as palavras do dicionario em busca da palavra fornecida;
int procuraNoDicionario(char palavra[], int tamDicionario, dicionario fonte[])
{
	int i = 0;
	while(i<tamDicionario)
	{
		if(comparaStr(palavra,fonte[i].palavra))
			return i;

		else
			i++;
	}
	return -1;
}

// Número de palavras do dicionario;
#define TAM 6

int main(void)
{
	setlocale(LC_ALL,"Portuguese");

	// Dicionario criado;
	dicionario portugues[TAM] = 
	{
		{{"pão"},{"'massa fermentada com fungos passivos.'\n\n"}},
		{{"cenoura"},{"'legume laranja.'\n\n"}},
		{{"brocolis"},{"'vegetal verde.'\n\n"}},
		{{"chocolate"},{"'doce feito de cacau.'\n\n"}},
		{{"morango"},{"'fruta campeira silvestre.'\n\n"}},
		{{"abacate"},{"'fruta verde.'\n\n"}}
	};

	// Entrada do usuário;
	char prompt[20] = {'\0'};

 while(1)
 {
	 printf("Digite a palavra\n$");
	 scanf("%s", prompt);

	 if(comparaStr(prompt,"q"))
	 {
	 	printf("\n### Fim ###\n");
		exit(EXIT_SUCCESS);
   }

   // Retorna o número do indice contendo a palavra;
	 int state = procuraNoDicionario(prompt,TAM,portugues);

	 // Retorna a definição da palavra;
	 if(state != -1)
		printf("%s", portugues[state].definicao);

	 else
		printf("\n**Palavra não existe.**\n\n");
 }

return EXIT_SUCCESS;
}
