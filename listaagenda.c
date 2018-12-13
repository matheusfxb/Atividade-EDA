#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Definição:
O nome só pode conter de 0 a 20 caracteres
O sorbenome só pode conter de 0 a 20 caracteres
O número não pode conter caracteres especiais, somente números
*/

struct lista
{
	char nome[20];
	char sobrenome[20];
	int numero;
	struct lista *prox;
	
};

void inserir(struct lista **l, char nome[20], char sobrenome[20], int num);
void imprimir(struct lista *l);
int buscar(struct lista **l, int num);
void remover(struct lista **l, int num);

int main(void)
{
	struct lista *l = NULL;

	inserir(&l, "Joao", "Pedro", 8122338844);
	inserir(&l, "Maria", "da Silva", 8928888888);
	inserir(&l, "Kristen", "Karey", 9844884488);
	inserir(&l, "Lacey", "Sturm", 948756465);

	imprimir(l);

	printf("\n%d\n", buscar(&l, 9844884488));
	printf("%d\n\n", buscar(&l, 9844884488));
	printf("%d\n\n", buscar(&l, 0000000));
	remover(&l, 9844884488);
	remover(&l, 948756465);
	
	imprimir(l);

	return 1;
}

void inserir(struct lista **l,  char nome[20], char sobrenome[20], int num)
{
	if(*l == NULL)
	{
		struct lista *novo = malloc(sizeof(struct lista));
		strcpy(novo->nome, nome);
		strcpy(novo->sobrenome, sobrenome);
		novo->numero = num;
		novo->prox = NULL;

		*l = novo;
	}
	else
	{
		inserir( &((*l)->prox) ,  nome, sobrenome, num);

	}
}

void imprimir(struct lista *l)
{
	struct lista *tmp = l;
	int i;

	while(tmp != NULL)
	{

		printf("Nome: %s, Sobrenome: %s, Numero: %d\n" , tmp->nome, tmp->sobrenome, tmp->numero);

		tmp = tmp->prox;
	}
}

int buscar(struct lista **l, int num)
{
	struct lista *tmp = *l;
	int existe = 0;

	while(tmp != NULL)
	{
		if(tmp->numero == num)
		{
			existe = 1;
			return existe;
		}

		tmp = tmp->prox;
	}

	return existe;
}

void remover(struct lista **l, int num)
{
	if(*l == NULL)
	{
		return;
	}
	else
	{
		if(buscar(l, num) == 1)
		{
			if((*l)->numero == num)
			{
				*l = (*l)->prox;
			}
			else
			{
				/*struct lista *anterior = *l;
				printf("\n%d\n", anterior->numero);
				struct lista *presente = (*l)->prox;
				printf("\n%d\n", presente->numero);

				while(presente->numero != num)
				{
					anterior = presente;
					presente = presente->prox;
				}

				anterior = presente->prox;*/

				struct lista *tmp = (*l);

				while((tmp->prox)->numero != num)
				{
					tmp = tmp->prox;
				}

				tmp->prox = (tmp->prox)->prox;
			}
		}
	}
}




