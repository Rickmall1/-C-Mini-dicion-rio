#include <stdio.h>
#include <stdbool.h>

// Dicionario
typedef struct
{
	char palavra[21];
	char definicao[51];
} dicionario;

// FERRAMENTA: verifica se strings são iguais (V,F)
bool compararStr(const char palavra1[], const char palavra2[])
{
	int i = 0;
	while((palavra1[i] == palavra2[i]) && (palavra1[i] != '\0') && (palavra2[i] != '\0'))
	{	
		i++;
	}

 if(palavra1[i] == palavra2[i])
	return true;

 else
	return false;
}

// Procura a palavra no dicionario
int procurarStr(const dicionario lingua[], const char procurar[],
const int numDePalavras)
{
	int i = 0;
	while(i<numDePalavras)
	{
		if(compararStr(procurar, lingua[i].palavra))
			return i; // Retorna a posição do vetor com a palavra correta

		else
			i++;	// Soma +1 e continua a procura	
	}
 return -1; // Palavra não encontrada
}

#define NUMERODEDEFINICOES 7

int main(void)
{
 char palavra[20] = {'\0'};
 int resultadoPesquisa;

 const dicionario portugues[NUMERODEDEFINICOES] =
 {{"amor","sentimento forte.\n"},
	{"cenoura","comida laranja.\n"},
	{"bolo","massa doce.\n"},
	{"chocolate","doce feito de cacau.\n"},
	{"maracuja","fruta silvestre.\n"},
	{"peixe","fruto do mar.\n"},
	{"sapo","animal verde.\n"}
 };

 while(1)
 {
 printf("Digite uma palavra: ");
 scanf("%s", palavra);

 if(compararStr(palavra,"q"))
 {
 	printf("\nFim\n");
  return 0;
 }

 resultadoPesquisa = procurarStr(portugues, palavra, NUMERODEDEFINICOES);

 if(resultadoPesquisa!= -1)
	printf("%s\n", portugues[resultadoPesquisa].definicao);
 
 else
	printf("\nPalavra nao encontrada\n");
 }

 return 0;
}

