#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 15
void insectionsort(int vet[N]){
	int valore;
	int i,j;
	for(i=1;i<N;i++){
		valore=vet[i];
		for(j=i-1;j>=0 && vet[j]>valore;j--){
			vet[j+1]=vet[j];
		}
		vet[j+1]=valore;
	}
}
main(){
	int vett[N];
	int i;
	srand(time(0));
	for(i=0;i<N;i++){
		vett[i]=rand()%999;
		printf("%d ",vett[i]);
	}
	printf("\n");
	insectionsort(vett);
	for(i=0;i<N;i++){
		printf("%d ",vett[i]);
	}
}
