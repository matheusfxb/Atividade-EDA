#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//TERCEIRA QUESTÃO - MERGESORT

struct dado
{
	int data, valor;
};

	//PROTÓTIPOS
	void inserir (struct dado d[]);
	void mergeSort (struct dado d[], int inicio, int fim);
	void merge(struct dado d[], int inicio, int meio, int fim);
	void insertionSort(struct dado d[], int n);
	void printar(struct dado d[]);

	int main(int argc, char const *argv[])
	{
		struct dado d[10];

		inserir(d);

		printf("\n");

		printar(d);

		printf("\n");

		mergeSort(d, 0, 9);
		//insertionSort(d, 10);

		printar(d);

		return 0;
	}

	void inserir (struct dado d[]){

		d[0].data = 20050803;
		d[1].data = 20080631;	
		d[2].data = 20180108;
		d[3].data = 19970630;
		d[4].data = 19991007;
		d[5].data = 20181213;
		d[6].data = 20181224;
		d[7].data = 20000430;
		d[8].data = 20060729;
		d[9].data = 20101120;

		d[0].valor = 5648;
		d[1].valor = 8456;
		d[2].valor = 4856;
		d[3].valor = 1564;
		d[4].valor = 6945;
		d[5].valor = 2689;
		d[6].valor = 3826;
		d[7].valor = 2358;
		d[8].valor = 8461;
		d[9].valor = 5596;
	}	

	void mergeSort (struct dado d[], int inicio, int fim){
		int meio;
		if(inicio < fim){
			meio = floor((inicio + fim)/2);
			mergeSort(d, inicio, meio);
			mergeSort(d, meio+1, fim);
			merge(d, inicio, meio, fim);
		}
	}

	void merge(struct dado d[], int inicio, int meio, int fim){
		int *temp, p1, p2, tamanho, i, j ,k;
		int fim1 = 0, fim2 = 0;
		tamanho = fim - inicio + 1;
		p1 = inicio;
		p2 = meio + 1;
		temp = (int *) malloc(tamanho*sizeof(int));
		if(temp != NULL){
			for(i = 0; i < tamanho; i++){
				if(!fim1 && !fim2){
				if(d[p1].data < d[p2].data)
					temp[i] = d[p1++].data;
				else
					temp[i] = d[p2++].data;
				if(p1 > meio) fim1 = 1;
				if(p2 > fim) fim2 = 1;
			}else{
				if(!fim1)
					temp[i] = d[p1++].data;
				else
					temp[i] = d[p2++].data;
			}
		}
		for(j = 0, k = inicio; j < tamanho; j++, k++)
			d[k].data = temp[j];
	}
	free(temp);
}

	void insertionSort(struct dado d[], int n){
		int i, j, aux;
		for (int i = 1; i < n; ++i)
		{
			aux = d[i].data;
			for (j = i; (j > 0) && (aux < d[j - 1].data); j--)
				d[j].data = d[j - 1].data;
			d[j].data = aux;
		}
	}

	void printar(struct dado d[]){
	
		for (int i = 0; i < 10; ++i){
			printf(" %d - %d\n", d[i].data, d[i].valor);
		}
	}

	