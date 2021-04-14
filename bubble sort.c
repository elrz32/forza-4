#include<stdio.h>
#include<time.h>
#define N 10
void bubblesort(int vet[N]){
	int i,temp,ultima;
	for(ultima=N;ultima!=0;ultima--){
		for(i=0;i!=ultima-1;i++){
			if(vet[i]>vet[i+1]){
				temp=vet[i+1];
				vet[i+1]=vet[i];
				vet[i]=temp;
			}
		}
	}
}
int trovanumero(int numero,int vet[N]){
	int i;
	for(i=0;i<N;i++){
		if(vet[i]==numero){
			return i;
		}
		if(vet[i]>numero){
			return -1;
		}
	}
	return -1;
}
main(){
	int i,vet[N],num;
	srand(time(0));
	for(i=0;i<N;i++){
		vet[i]=rand()%999;
		printf(" %d",vet[i]);
	}
	printf("\n");
	bubblesort(vet);
	for(i=0;i<N;i++){
		printf(" %d",vet[i]);
	}
	printf("\n scegli un numero da trovare\n");
	scanf("%d",&num);
	int risultato_ricerca;
	risultato_ricerca=trovanumero(num,vet);
	printf("\n %d",risultato_ricerca);
}
