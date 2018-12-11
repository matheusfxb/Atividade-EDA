#include <stdio.h>
#include <stdlib.h>

struct lista
{
	int numero;
	struct lista *prox;
};

void inserir(struct lista **l, int num);
void imprimir(struct lista *l);
int buscar(struct lista **l, int num);
void remover(struct lista **l, int num);

int main(void)
{
	struct lista *l = NULL;
	
	inserir(&l, 9);
	inserir(&l, 4);
	inserir(&l, 2);
	inserir(&l, 1);
	
	imprimir(l);
	
	printf("\n%d\n", buscar(&l, 2));
	printf("%d\n\n", buscar(&l, 3));
	
	remover(&l, 2);
	remover(&l, 1);
	
	imprimir(l);
	
	return 1;
}

void inserir(struct lista **l, int num)
{
	if(*l == NULL)
	{
		struct lista *novo = malloc(sizeof(struct lista));
		novo->numero = num;
		novo->prox = NULL;
		
		*l = novo;
	}
	else
	{
		inserir(&((*l)->prox),num);
	}
}

void imprimir(struct lista *l)
{
	struct lista *tmp = l;
	
	while(tmp != NULL)
	{
		printf("%d\n", tmp->numero);
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




