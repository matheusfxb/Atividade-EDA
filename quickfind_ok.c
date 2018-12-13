#include <stdio.h>
#include <stdlib.h>

	//PROTÓTIPOS
	int particiona(int *V, int inicio, int final);
	int quickFind(int *V, int inicio, int fim, int k);

	int main(void)
	{
		int V[] = {7, 1, 3, 10, 17, 2, 21, 9};

		int k = 2;
		
		int elemento;
		
		printf("\n");
		
		for(k = 1; k <= 8 ; k++)
		{
			elemento = quickFind(V, 0, 7, k);
			printf("\n%d", elemento);
		}

		return 0;
	}

	int particiona(int *V, int inicio, int final)
	{
		int esq, dir, pivo, aux;
		
		esq = inicio;
		dir = final;
		
		pivo = V[inicio];
		
		while(esq < dir)
		{
			while(V[esq] <= pivo)
				esq++;
		
			while(V[dir] > pivo)
				dir--;
			
			if(esq < dir)
			{
				aux = V[esq];
				V[esq] = V[dir];
				V[dir] = aux;
			}
		}
		
		V[inicio] = V[dir];
		V[dir] = pivo;
		
		return dir;
	}

	int quickFind(int *V, int inicio, int fim, int k)
	{
		int pivo;
		
		if(fim > inicio)
		{
			pivo = particiona(V, inicio, fim);

			if(k < pivo)
				quickFind(V, inicio, pivo-1, k);
			else if(k > pivo)
				quickFind(V, pivo+1, fim, k);
		}	
		
		return V[k-1];
	}