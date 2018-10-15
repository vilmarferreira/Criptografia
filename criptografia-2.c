#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char *criptografa(char s[100], int cifra) {
  int i,dif,valor, n = strlen(s);//recebe o "numero" de caracteres da mensagem
  char saux[100];
  strcpy(saux, s);//copia valr da string 
	//inicio da criptografia.
  for (i=0; i<n; i++) 
	{
    
 	if(saux[i]==" ")

  {
    saux=0;
  }
	
	else
	{
			
	 		valor=saux[i]+cifra;
			if (valor<=90)
			{
				saux[i] = saux[i]+cifra;
			}
			else
			{
				dif=valor-90;
				saux[i]=65+(dif-1);
			}
	}
	}

  return(saux);
}

char *descriptografa(char s[100], int cifra) {
  int i, n = strlen(s);
  char saux[100];
  strcpy(saux, s);

  for (i=0; i<n; i++) {
    saux[i] = saux[i] - cifra;
  }

  return(saux);
}
void main() {
  char mensagem[100], sc[100], sd[100];
  int chave;

  printf("Informe um texto:\n");
  gets(mensagem);

  printf("\nInforme o valor da cifra:\n");
  scanf("%d", &chave);
  system("clear");
	while ((chave < 1) || (chave >26))
    {
		printf("Chave inválida. Digite outra chave: ");
		scanf("%d", &chave);
	}
  strcpy(sc, criptografa(mensagem, chave));//passagem de parametro para a função
  strcpy(sd, descriptografa(sc, chave));

  printf("\nTexto criptografado:\n");
  printf("%s", sc);

  
}

